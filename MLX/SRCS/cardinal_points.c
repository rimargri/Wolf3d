/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:02:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 22:53:48 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/** *********************************** **/
/** *********************************** **/
/**         	north		            **/
/**         	south		            **/
/**        		 west		            **/
/**        		 east		            **/
/** *********************************** **/
/** *********************************** **/

t_texture	*cardinal_points(t_wolf *w, t_vec2 len)
{
	t_vec2	pix;

	pix.x = len.x - floor(len.x);
	pix.y = len.y - floor(len.y);
	pix.x = pix.x - 0.5f;
	pix.y = pix.y - 0.5f;
	if (pix.y > pix.x && pix.y > -pix.x)
		return (choice_texture(w, '2'));
	else if (pix.y < -pix.x && pix.y < pix.x)
		return (choice_texture(w, '3'));
	else if (pix.y > pix.x && pix.y < -pix.x)
		return (choice_texture(w, '0'));
	else if	(pix.y > -pix.x && pix.y < pix.x)
		return (choice_texture(w, '1'));
	return (NULL);
}
