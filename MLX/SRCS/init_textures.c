/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:47:57 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <string.h>

void		malloc_text(t_texture **t, int count_text, int i)
{
	int start_pos;

	start_pos = i + count_text;
	while (i < start_pos)
	{
		t[i] = (t_texture*)malloc(sizeof(t_texture));
		((t[i] == NULL) ? wolf_error(MALLOC_ERROR) : 1);
		i++;
	}
}

t_texture	**init_textures(t_wolf *w, char *s)
{
	t_texture	**t;

	t = (t_texture**)malloc(sizeof(t_texture*) * 6);
	((t == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	malloc_text(t, 6, 0);
	text_floor(t[0]);
	text_celling(t[1]);
	if (!strcmp(s, "../maps/0") || (!strcmp(s, "../maps/2")))
	{
		w->text_id = STATE_PANELKI;
		text_panelki(t);
	}
	else if (!strcmp(s, "../maps/4") || !strcmp(s, "../maps/5") ||
												(!strcmp(s, "../maps/1")))
	{
		w->text_id = STATE_EVANGELION;
		text_evangelion(t);
	}
	else if (!strcmp(s, "../maps/Pepe"))
	{
		w->text_id = STATE_PEPEGA;
		text_pepe(t);
	}
	return (t);
}

void		change_textures(t_wolf *w)
{
	clear_texture(w->t);
	malloc_text(w->t, 4, 2);
	if (w->text_id == STATE_EVANGELION)
		w->text_id = STATE_PEPEGA;
	else if (w->text_id == STATE_PEPEGA)
		w->text_id = STATE_PANELKI;
	else if (w->text_id == STATE_PANELKI)
		w->text_id = STATE_EVANGELION_MULTI;
	else if (w->text_id == STATE_EVANGELION_MULTI)
		w->text_id = STATE_PEPEGA_MULTI;
	else if (w->text_id == STATE_PEPEGA_MULTI)
		w->text_id = STATE_PANELKI_MULTI;
	else if (w->text_id == STATE_PANELKI_MULTI)
		w->text_id = STATE_EVANGELION;
	if (w->text_id == STATE_EVANGELION || w->text_id == STATE_EVANGELION_MULTI)
		text_evangelion(w->t);
	if (w->text_id == STATE_PEPEGA || w->text_id == STATE_PEPEGA_MULTI)
		text_pepe(w->t);
	else if (w->text_id == STATE_PANELKI || w->text_id == STATE_PANELKI_MULTI)
		text_panelki(w->t);
}
