/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:45:42 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/01 19:07:39 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

int		color_of_texture(t_wolf *w, char c)
{
	int color;

	color = 0;
	if (c == '0')
		color = w->t[0]->texture[0];
	else if (c == '1')
		color = w->t[1]->texture[149];
	else if (c == '2')
		color = w->t[2]->texture[170];
	else if (c == '3')
		color = w->t[3]->texture[160];
	else if (c >= '4' && c <= '7')
		color = w->t[4]->texture[160];
	else
		return (-1);
	return (color);
}

t_texture	*choice_texture(t_wolf *w, char c)
{
	t_texture *texture;

	if (c == '0')
		texture = w->t[0];
	else if (c == '1')
		texture = w->t[1];
	else if (c == '2')
		texture = w->t[2];
	else if (c == '3')
		texture = w->t[3];
	else if (c >= '4' && c <= '7')
		texture = w->t[4];
	else
		texture = NULL;
	return (texture);
}
