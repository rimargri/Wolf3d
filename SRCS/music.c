/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:30:52 by hchau             #+#    #+#             */
/*   Updated: 2020/03/09 19:41:07 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		change_music(t_wolf *w)
{
	if (w->dem->music_on == FALSE || w->dem->change_music == FALSE)
		return ;
	system("pkill afplay");
	if (w->dem->fract->on == TRUE)
		system("afplay ./sounds/fract.mp3 &");
	else if (w->dem->wave->on == TRUE)
		system("afplay ./sounds/wave.mp3 &");
	else if (w->dem->quake->on == TRUE)
		system("afplay ./sounds/quake.mp3 &");
	else if (w->dem->mirr->on == TRUE)
		system("afplay ./sounds/mirr.mp3 &");
	else if (w->dem->norm->on == TRUE)
		system("afplay ./sounds/norm.mp3 &");
	else
		system("afplay ./sounds/no_mode.mp3 &");
	w->dem->change_music = FALSE;
}

void		torn_music_on(int x, int y, t_wolf *w)
{
	if (x > WIN_W - 90 && x < WIN_W - 40 && y > WIN_H - 90 && y < WIN_H - 40)
		w->dem->music_on = w->dem->music_on == TRUE ? FALSE : TRUE;
	else
		return ;
	if (w->dem->music_on == FALSE)
	{
		system("pkill afplay");
		w->dem->change_music = FALSE;
		return ;
	}
	if (w->dem->wave->on == TRUE)
		system("afplay ./sounds/wave.mp3 &");
	else if (w->dem->quake->on == TRUE)
		system("afplay ./sounds/quake.mp3 &");
	else if (w->dem->mirr->on == TRUE)
		system("afplay ./sounds/mirr.mp3 &");
	else if (w->dem->fract->on == TRUE)
		system("afplay ./sounds/fract.mp3 &");
	else if (w->dem->norm->on == TRUE)
		system("afplay ./sounds/norm.mp3 &");
	else
		system("afplay ./sounds/no_mode.mp3 &");
}
