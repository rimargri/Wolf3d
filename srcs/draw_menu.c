/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:34:42 by hchau             #+#    #+#             */
/*   Updated: 2020/03/09 20:20:25 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		write_extra_management(t_wolf *w)
{
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 283,
			0x00BBBBFF, "use    (enter)");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 260,
			0x00BBBBFF, "show/hide map:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 283,
			0x00BBBBFF, "      |");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 260, 285,
			0x00BBBBFF, "     _");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 262, 285,
			0x00BBBBFF, "    _");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 262, 292,
			0x00BBBBFF, "    <");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 312,
			0x00BBBBFF, "show/hide radar:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 332,
			0x00BBBBFF, "R key");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 380,
			0x00BBBBFF, "on/off mouse");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 400,
			0x00BBBBFF, "rotation:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 420,
			0x00BBBBFF, "right button");
	if (w->dem->music_on == TRUE)
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 680,
		0x00BBBBFF, "press Q to on/off connect           music and maze shape");
}

int			write_waves_earthquake(t_wolf *w)
{
	if (w->dem->wave->on == TRUE)
	{
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230, 600,
			0x00BBBBFF, "waves");
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 630,
			0x00BBBBFF, "scroll mouse up or down to change intence");
		if (w->dem->fract->on == TRUE)
			mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 295, 600,
			0x00BBBBFF, "and fractal");
	}
	else if (w->dem->quake->on == TRUE)
	{
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230, 600,
				0x00BBBBFF, "earthquake");
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 630,
				0x00BBBBFF, "scroll mouse up or down to change speed");
		if (w->dem->fract->on == TRUE)
			mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 340, 600,
				0x00BBBBFF, "and fractal");
	}
	else
		return (0);
	return (1);
}

void		write_curr_dem(t_wolf *w)
{
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 600,
			0x00BBBBFF, "current shape:");
	if (w->dem->norm->on == TRUE)
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230, 600,
			0x00BBBBFF, "normal");
	else if (write_waves_earthquake(w))
		;
	else if (w->dem->mirr->on == TRUE)
	{
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230, 600,
			0x00BBBBFF, "mirror floors");
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 630,
			0x00BBBBFF, "scroll mouse up or down to change brightness");
		if (w->dem->fract->on == TRUE)
			mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 370, 600,
			0x00BBBBFF, "and fractal");
	}
	else if (w->dem->fract->on == TRUE)
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230, 600,
			0x00BBBBFF, "fractal");
	else
		mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230, 600,
			0x00BBBBFF, "please, choose one");
}

void		write_dementions_management(t_wolf *w)
{
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + (255 + 50) / 2, 30,
			0x00BBBBFF, "Game control:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 120,
			0x00BBBBFF, "change maze shape: ");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 150,
			0x00BBBBFF, "1 - set default");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 170,
			0x00BBBBFF, "2 - waves");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 190,
			0x00BBBBFF, "3 - earthquake");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 210,
			0x00BBBBFF, "4 - mirrors on floor");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 255, 230,
			0x00BBBBFF, "5 - fractal mask");
	write_curr_dem(w);
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230 + 250, 120,
			0x00BBBBFF, "change maze");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230 + 250, 140,
			0x00BBBBFF, "textures:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 230 + 250, 170,
			0x00BBBBFF, "press T");
	write_extra_management(w);
}

void		draw_menu(t_wolf *w)
{
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 120,
			0x00BBBBFF, "move:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 150,
			0x00BBBBFF, "W - forward");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 170,
			0x00BBBBFF, "A - left");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 190,
			0x00BBBBFF, "D - right");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 210,
			0x00BBBBFF, "S - back");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 240,
			0x00BBBBFF, "look around:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 260,
			0x00BBBBFF, "move mouse");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 280,
			0x00BBBBFF, "or use <  >");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 55, 280,
			0x00BBBBFF, "       - - ");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 300,
			0x00BBBBFF, "keys");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 330,
			0x00BBBBFF, "jump:");
	mlx_string_put(w->mlx.mptr, w->mlx.wptr, WIN_W / 2 + 50, 350,
			0x00BBBBFF, "hold space");
	write_dementions_management(w);
}
