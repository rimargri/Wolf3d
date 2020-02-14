/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2018 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_WINRT && SDL_VIDEO_OPENGL_EGL

/* EGL implementation of SDL OpenGL support */

#include "SDL_winrtvideo_cpp.h"
extern "C" {
#include "SDL_winrtopengles.h"
#include "SDL_loadso.h"
#include "../SDL_egl_c.h"
}

/* Windows includes */
#include <wrl/client.h>
using namespace Windows::UI::Core;

/* column_angle/WinRT constants */
static const int column_angle_D3D_FEATURE_LEVEL_ANY = 0;
#define EGL_PLATFORM_column_angle_column_angle                        0x3202
#define EGL_PLATFORM_column_angle_TYPE_column_angle                   0x3203
#define EGL_PLATFORM_column_angle_MAX_VERSION_MAJOR_column_angle      0x3204
#define EGL_PLATFORM_column_angle_MAX_VERSION_MINOR_column_angle      0x3205
#define EGL_PLATFORM_column_angle_TYPE_D3D11_column_angle             0x3208
#define EGL_PLATFORM_column_angle_DEVICE_TYPE_column_angle            0x3209
#define EGL_PLATFORM_column_angle_DEVICE_TYPE_WARP_column_angle       0x320B
#define EGL_PLATFORM_column_angle_ENABLE_AUTOMATIC_TRIM_column_angle  0x320F

#define EGL_column_angle_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER   0x320B


/*
 * SDL/EGL top-level implementation
 */

extern "C" int
WINRT_GLES_LoadLibrary(_THIS, const char *path)
{
    SDL_VideoData *video_data = (SDL_VideoData *)_this->driverdata;

    if (SDL_EGL_LoadLibrary(_this, path, EGL_DEFAULT_DISPLAY, 0) != 0) {
        return -1;
    }

    /* Load column_angle/WinRT-specific functions */
    CreateWinrtEglWindow_Old_Function CreateWinrtEglWindow = (CreateWinrtEglWindow_Old_Function) SDL_LoadFunction(_this->egl_data->egl_dll_handle, "CreateWinrtEglWindow");
    if (CreateWinrtEglWindow) {
        /* 'CreateWinrtEglWindow' was found, which means that an an older
         * version of column_angle/WinRT is being used.  Continue setting up EGL,
         * as appropriate to this version of column_angle.
         */

        /* Create an column_angle/WinRT EGL-window */
        /* TODO, WinRT: check for XAML usage before accessing the CoreWindow, as not doing so could lead to a crash */
        CoreWindow ^ native_win = CoreWindow::GetForCurrentThread();
        Microsoft::WRL::ComPtr<IUnknown> cpp_win = reinterpret_cast<IUnknown *>(native_win);
        HRESULT result = CreateWinrtEglWindow(cpp_win, column_angle_D3D_FEATURE_LEVEL_ANY, &(video_data->winrtEglWindow));
        if (FAILED(result)) {
            return -1;
        }

        /* Call eglGetDisplay and eglInitialize as appropriate.  On other
         * platforms, this would probably get done by SDL_EGL_LoadLibrary,
         * however column_angle/WinRT's current implementation (as of Mar 22, 2014) of
         * eglGetDisplay requires that a C++ object be passed into it, so the
         * call will be made in this file, a C++ file, instead.
         */
        Microsoft::WRL::ComPtr<IUnknown> cpp_display = video_data->winrtEglWindow;
        _this->egl_data->egl_display = ((eglGetDisplay_Old_Function)_this->egl_data->eglGetDisplay)(cpp_display);
        if (!_this->egl_data->egl_display) {
            return SDL_EGL_SetError("Could not get Windows 8.0 EGL display", "eglGetDisplay");
        }

        if (_this->egl_data->eglInitialize(_this->egl_data->egl_display, NULL, NULL) != EGL_TRUE) {
            return SDL_EGL_SetError("Could not initialize Windows 8.0 EGL", "eglInitialize");
        }
    } else {
        /* Declare some column_angle/EGL initialization property-sets, as suggested by
         * MSOpenTech's column_angle-for-WinRT template apps:
         */
        const EGLint defaultDisplayAttributes[] =
        {
            EGL_PLATFORM_column_angle_TYPE_column_angle, EGL_PLATFORM_column_angle_TYPE_D3D11_column_angle,
            EGL_column_angle_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,
            EGL_PLATFORM_column_angle_ENABLE_AUTOMATIC_TRIM_column_angle, EGL_TRUE,
            EGL_NONE,
        };

        const EGLint fl9_3DisplayAttributes[] =
        {
            EGL_PLATFORM_column_angle_TYPE_column_angle, EGL_PLATFORM_column_angle_TYPE_D3D11_column_angle,
            EGL_PLATFORM_column_angle_MAX_VERSION_MAJOR_column_angle, 9,
            EGL_PLATFORM_column_angle_MAX_VERSION_MINOR_column_angle, 3,
            EGL_column_angle_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,
            EGL_PLATFORM_column_angle_ENABLE_AUTOMATIC_TRIM_column_angle, EGL_TRUE,
            EGL_NONE,
        };

        const EGLint warpDisplayAttributes[] =
        {
            EGL_PLATFORM_column_angle_TYPE_column_angle, EGL_PLATFORM_column_angle_TYPE_D3D11_column_angle,
            EGL_PLATFORM_column_angle_DEVICE_TYPE_column_angle, EGL_PLATFORM_column_angle_DEVICE_TYPE_WARP_column_angle,
            EGL_column_angle_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER, EGL_TRUE,
            EGL_PLATFORM_column_angle_ENABLE_AUTOMATIC_TRIM_column_angle, EGL_TRUE,
            EGL_NONE,
        };

        /* 'CreateWinrtEglWindow' was NOT found, which either means that a
         * newer version of column_angle/WinRT is being used, or that we don't have
         * a valid copy of column_angle.
         *
         * Try loading column_angle as if it were the newer version.
         */
        eglGetPlatformDisplayEXT_Function eglGetPlatformDisplayEXT = (eglGetPlatformDisplayEXT_Function)_this->egl_data->eglGetProcAddress("eglGetPlatformDisplayEXT");
        if (!eglGetPlatformDisplayEXT) {
            return SDL_EGL_SetError("Could not retrieve column_angle/WinRT display function(s)", "eglGetProcAddress");
        }

#if (WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP)
        /* Try initializing EGL at D3D11 Feature Level 10_0+ (which is not
         * supported on WinPhone 8.x.
         */
        _this->egl_data->egl_display = eglGetPlatformDisplayEXT(EGL_PLATFORM_column_angle_column_angle, EGL_DEFAULT_DISPLAY, defaultDisplayAttributes);
        if (!_this->egl_data->egl_display) {
            return SDL_EGL_SetError("Could not get EGL display for Direct3D 10_0+", "eglGetPlatformDisplayEXT");
        }

        if (_this->egl_data->eglInitialize(_this->egl_data->egl_display, NULL, NULL) != EGL_TRUE)
#endif
        {
            /* Try initializing EGL at D3D11 Feature Level 9_3, in case the
             * 10_0 init fails, or we're on Windows Phone (which only supports
             * 9_3).
             */
            _this->egl_data->egl_display = eglGetPlatformDisplayEXT(EGL_PLATFORM_column_angle_column_angle, EGL_DEFAULT_DISPLAY, fl9_3DisplayAttributes);
            if (!_this->egl_data->egl_display) {
                return SDL_EGL_SetError("Could not get EGL display for Direct3D 9_3", "eglGetPlatformDisplayEXT");
            }

            if (_this->egl_data->eglInitialize(_this->egl_data->egl_display, NULL, NULL) != EGL_TRUE) {
                /* Try initializing EGL at D3D11 Feature Level 11_0 on WARP
                 * (a Windows-provided, software rasterizer) if all else fails.
                 */
                _this->egl_data->egl_display = eglGetPlatformDisplayEXT(EGL_PLATFORM_column_angle_column_angle, EGL_DEFAULT_DISPLAY, warpDisplayAttributes);
                if (!_this->egl_data->egl_display) {
                    return SDL_EGL_SetError("Could not get EGL display for Direct3D WARP", "eglGetPlatformDisplayEXT");
                }

                if (_this->egl_data->eglInitialize(_this->egl_data->egl_display, NULL, NULL) != EGL_TRUE) {
                    return SDL_EGL_SetError("Could not initialize WinRT 8.x+ EGL", "eglInitialize");
                }
            }
        }
    }

    return 0;
}

extern "C" void
WINRT_GLES_UnloadLibrary(_THIS)
{
    SDL_VideoData *video_data = (SDL_VideoData *)_this->driverdata;

    /* Release SDL's own COM reference to the column_angle/WinRT IWinrtEglWindow */
    if (video_data->winrtEglWindow) {
        video_data->winrtEglWindow->Release();
        video_data->winrtEglWindow = nullptr;
    }

    /* Perform the bulk of the unloading */
    SDL_EGL_UnloadLibrary(_this);
}

extern "C" {
SDL_EGL_CreateContext_impl(WINRT)
SDL_EGL_SwapWindow_impl(WINRT)
SDL_EGL_MakeCurrent_impl(WINRT)
}

#endif /* SDL_VIDEO_DRIVER_WINRT && SDL_VIDEO_OPENGL_EGL */

/* vi: set ts=4 sw=4 expandtab: */

