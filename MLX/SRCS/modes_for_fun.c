//
// Created by Hugor Chau on 2020-02-25.
//

#include "wolf3d.h"

void	redraw_fract(t_wolf *w)
{
	if (w->dem->fract->on == FALSE)
		return ;
	if (w->dem->fract->intence % 5 == 0)
	{
		w->layers->d_fractol->count.k.x += FRACT_MOVE * w->layers->d_fractol->is_mooving;
		w->layers->d_fractol->count.k.y += FRACT_MOVE * w->layers->d_fractol->is_mooving;
		w->layers->d_fractol->count.color_shift++;
		draw_fractal(&w->layers->d_fractol, &w->layers->d_fractol_draw);
	}
	if (w->dem->fract->intence > FRACT_MAX_INTENCE)
		w->layers->d_fractol->is_mooving = OUT;
	if (w->dem->fract->intence < FRACT_MIN_INTENCE)
	{
		w->layers->d_fractol->is_mooving = IN;
		w->layers->d_fractol->count.k.y += FRACT_MOVE * 3;
	}
	w->dem->fract->intence += w->layers->d_fractol->is_mooving;
}

void	set_modes_false(t_dem *d)
{
	d->norm->intence = 0;
	d->wave->on = FALSE;
	d->wave->intence = 0;
	d->quake->on = FALSE;
	d->quake->intence = 0;
	d->fisheye->on = FALSE;
	d->fisheye->intence = 0;
	d->mirr->on = FALSE;
	d->mirr->intence = 1;
	d->fract->on = FALSE;
	d->fract->intence = 0;
}

void	get_wolf_with_modes(t_wolf *w)
{
	if (w->dem->norm->on == TRUE)
		set_modes_false(w->dem);
	if (w->dem->quake->on != FALSE)
		w->player.look_column_angle.y += CAMERA_DIFFUSION * w->dem->quake->intence;
	if (w->dem->wave->on != FALSE)
		w->player.look_column_angle.y += CAMERA_DIFFUSION * 3;
	if (w->dem->mirr->on != FALSE)
	{
		w->player.look_column_angle.y = CAMERA_DIFFUSION * 3;
		w->dem->wave->intence = w->dem->mirr->intence * 4;
	}
	w->layers->d_fractol_draw.on = w->dem->fract->on == FALSE ? FALSE : TRUE;
	redraw_fract(w);
}

t_mode	*new_mode(void)
{
	t_mode		*res;

	res = (t_mode *)malloc(sizeof(t_mode));
	res->on = FALSE;
	res->intence = 0;
	return (res);
}
//__FIXX_IMMIDEATLEY Перенести выделение в другой файл
t_dem	*init_dem(void)
{
	t_dem	*res;

	res = (t_dem *)malloc(sizeof(t_dem));
	res->wave = new_mode();
	res->quake = new_mode();
	res->fisheye = new_mode();
	res->mirr = new_mode();
	res->norm = new_mode();
	res->fract = new_mode();
	res->norm->on = TRUE;
	res->mirr->intence = 2;
	return (res);
}

int		count_intence(int k, int x, int y, t_wolf *w)
{
	if (k == SCROLL_UP)
	{
		if (w->dem->quake->on != FALSE)
			w->dem->quake->intence++;
		if (w->dem->wave->on != FALSE)
			w->dem->wave->intence++;
		if (w->dem->mirr->on != FALSE)
			w->dem->mirr->intence++;
	}
	if (k == SCROLL_DOWN)
	{
		if (w->dem->quake->on != FALSE)
			w->dem->quake->intence--;
		if (w->dem->wave->on != FALSE)
			w->dem->wave->intence--;
		if (w->dem->mirr->on != FALSE)
			w->dem->mirr->intence--;
		if (w->dem->mirr->intence < 5)
			w->dem->mirr->intence = 5;
	}
	return (0);
}
