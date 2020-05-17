/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:02:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:44:03 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** *********************************** **
** *********************************** **
**         		north		           **
**         		south		           **
**        		 west		           **
**        		 east		           **
** *********************************** **
** *********************************** **
*/

int			should_multiside(t_wolf *w)
{
	if (w->text_id >= STATE_EVANGELION_MULTI)
		return (1);
	else
		return (0);
}

t_texture	*choice_drawing_texture(t_wolf *w, t_vec2 len)
{
	if (should_multiside(w))
		return (cardinal_points(w, len));
	else
		return (special_side(w, len));
}

t_texture	*cardinal_points(t_wolf *w, t_vec2 len)
{
	t_vec2	pix;

	pix.x = len.x - floor(len.x);
	pix.y = len.y - floor(len.y);
	pix.x = pix.x - 0.5f;
	pix.y = pix.y - 0.5f;
	if (pix.y > pix.x && pix.y > -pix.x)
		return (choice_texture(w, '6'));
	else if (pix.y < -pix.x && pix.y < pix.x)
		return (choice_texture(w, '7'));
	else if (pix.y > pix.x && pix.y < -pix.x)
		return (choice_texture(w, '8'));
	else if (pix.y > -pix.x && pix.y < pix.x)
		return (choice_texture(w, '9'));
	return (NULL);
}

t_texture	*special_side(t_wolf *w, t_vec2 len)
{
	char ch;

	ch = w->map.line[(int)len.x + (int)len.y * w->map.w];
	if (ch == '0' || ch == '2' || ch == '3' || ch == '5')
		return (choice_texture(w, '0'));
	else if (ch == '4')
		return (choice_texture(w, '4'));
	else if (ch == '6')
		return (choice_texture(w, '6'));
	else if (ch == '7')
		return (choice_texture(w, '7'));
	else if (ch == '8')
		return (choice_texture(w, '8'));
	else if (ch == '9')
		return (choice_texture(w, '9'));
	return (NULL);
}
