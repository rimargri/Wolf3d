/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:02:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/01 23:13:29 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// t_texture	*cardinal_points(t_wolf *w, t_vec2 len)
// {
// 	if (w->map.line[(int)(len.x - 1) + (int)(len.y) * w->map.w] == ' ')			// zapad
// 		return (choice_texture(w, '2'));
// 	else if (w->map.line[(int)(len.x + 1) + (int)(len.y) * w->map.w] == ' ')			// vostok
// 		return (choice_texture(w, '3'));
// 	else if (w->map.line[(int)(len.x) + (int)(len.y + 1) * w->map.w] == ' ')			// sever
// 		return (choice_texture(w, '0'));
// 	else if (w->map.line[(int)(len.x) + (int)(len.y - 1) * w->map.w] == ' ')			// ug
// 		return (choice_texture(w, '1'));
// 	return (NULL);
// }









t_texture	*cardinal_points(t_wolf *w, t_vec2 hit)
{
	if (hit.x < EPS)								// zapad
		return (choice_texture(w, '2'));
	else if (hit.x > hit.y && hit.y > EPS)			// vostok
		return (choice_texture(w, '3'));
	else if (hit.y > EPS)							// sever
		return (choice_texture(w, '0'));
	else											// ug
		return (choice_texture(w, '1'));
	// return (NULL);
}



































