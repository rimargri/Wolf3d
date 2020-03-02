/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:02:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/02 23:37:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	*cardinal_points(t_wolf *w, t_vec2 len)
{
	t_vec2	pix;

	// hit->x = floor(offset.x);		// перевод в локальные координаты
	// hit->y = floor(offset.y);
	// hit->x = hit->x - 0.5;
	// hit->y = hit->y - 0.5;

	pix.x = len.x - floor(len.x);
	pix.y = len.y - floor(len.y);
	pix.x = pix.x - 0.5f;
	pix.y = pix.y - 0.5f;
	if (pix.y > pix.x && pix.y > -pix.x)								// zapad
		return (choice_texture(w, '2'));
	else if (pix.y < -pix.x && pix.y < pix.x)							// vostok
		return (choice_texture(w, '3'));
	else if (pix.y > pix.x && pix.y < -pix.x)							// sever
		return (choice_texture(w, '0'));
	else if	(pix.y > -pix.x && pix.y < pix.x)							// ug
		return (choice_texture(w, '1'));
	// return (NULL);
}

// t_texture	*cardinal_points(t_wolf *w, t_vec2 hit)
// {
// 	if (hit.x < EPS)								// zapad
// 		return (choice_texture(w, '2'));
// 	else if (hit.x > hit.y && hit.y > EPS)			// vostok
// 		return (choice_texture(w, '3'));
// 	else if (hit.y > EPS)							// sever
// 		return (choice_texture(w, '0'));
// 	else											// ug
// 		return (choice_texture(w, '1'));
// 	// return (NULL);
// }