/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:44:13 by cvernius          #+#    #+#             */
/*   Updated: 2020/01/28 15:01:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int get_color(t_color *col)
{
	return (((int)col->r << 16) + ((int)col->g << 8) + (int)col->b);
}

t_vector3d *vec_diff(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d *diff;
	
	diff = malloc(sizeof(t_vector3d*));
	diff->x = v2->x - v1->x;
	diff->y = v2->y - v1->y;
	diff->z = v2->z - v1->z;
	return (diff);
}

double	dot_product(t_vector3d *v1, t_vector3d *v2)
{
	double dp;

	dp = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (dp);
}

// t_vector3d *vec_product(t_vector3d *v1, t_vector3d *v2)
// {

// }