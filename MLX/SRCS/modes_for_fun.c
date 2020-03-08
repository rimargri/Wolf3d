/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes_for_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:41:27 by hchau             #+#    #+#             */
/*   Updated: 2020/03/08 13:41:28 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

void	redraw_fract(t_wolf *w)
{
	if (w->dem->fract->on == FALSE)
		return ;
	if (w->dem->fract->intence % 5 == 0)
	{
		w->layers->d_fractol->count.k.x +=
				FRACT_MOVE * w->layers->d_fractol->is_mooving;
		w->layers->d_fractol->count.k.y +=
				FRACT_MOVE * w->layers->d_fractol->is_mooving;
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

void	get_wolf_with_modes(t_wolf *w)
{
	if (w->dem->norm->on == TRUE)
		set_modes_false(w->dem);
	if (w->dem->quake->on != FALSE)
		w->player.look_column_angle.y +=
				CAMERA_DIFFUSION * w->dem->quake->intence;
	if (w->dem->wave->on != FALSE)
		w->player.look_column_angle.y += CAMERA_DIFFUSION * 3;
	if (w->dem->mirr->on != FALSE)
		w->player.look_column_angle.y = CAMERA_DIFFUSION * 4;
	w->layers->d_fractol_draw.on = w->dem->fract->on == FALSE ? FALSE : TRUE;
	redraw_fract(w);
}

int		count_intence(int k, int x, int y, t_wolf *w)
{
	if (k == SCROLL_UP)
	{
		if (w->dem->quake->on != FALSE)
			w->dem->quake->intence++;
		if (w->dem->wave->on != FALSE)
			w->dem->wave->intence++;
		if (w->dem->mirr->on != FALSE && w->dem->mirr->intence > 0)
			w->dem->mirr->intence--;
	}
	if (k == SCROLL_DOWN)
	{
		if (w->dem->quake->on != FALSE)
			w->dem->quake->intence--;
		if (w->dem->wave->on != FALSE)
			w->dem->wave->intence--;
		if (w->dem->mirr->on != FALSE && w->dem->mirr->intence < (51))
			w->dem->mirr->intence++;
	}
	x = 0;
	y = 0;
	return (0);
}
