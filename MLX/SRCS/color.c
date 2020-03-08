/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:45:42 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 18:10:05 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

int			choice_color(t_wolf *w, char c)
{
	int color;

	color = 0;
	if (c == '0')
		color = get_color((t_color){0, 0, 0});
	else if (c == '2')
		color = get_color((t_color){100, 150, 100});
	else if (c == '3')
		color = get_color((t_color){240, 240, 240});
	else if (c == '4')
		color = get_color((t_color){0, 0, 0});
	else if (c == '5')
		color = get_color((t_color){240, 100, 100});
	else if (c == '6')
		color = w->t[2]->texture[2];
	else if (c == '7')
		color = w->t[3]->texture[149];
	else if (c == '8')
		color = w->t[4]->texture[170];
	else if (c == '9')
		color = w->t[5]->texture[160];
	else
		return (-1);
	return (color);
}

t_texture	*choice_texture(t_wolf *w, char c)
{
	t_texture *texture;

	if (c == '0')
		texture = w->t[2];
	else if (c == '2')
		texture = w->t[3];
	else if (c == '3')
		texture = w->t[3];
	else if (c == '4')
		texture = w->t[3];
	else if (c == '5')
		texture = w->t[3];
	else if (c == '6')
		texture = w->t[2];
	else if (c == '7')
		texture = w->t[3];
	else if (c == '8')
		texture = w->t[4];
	else if (c == '9')
		texture = w->t[5];
	else
		texture = NULL;
	return (texture);
}
