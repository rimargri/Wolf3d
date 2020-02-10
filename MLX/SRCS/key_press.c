/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:34 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/10 20:53:56 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int k, t_mlx *mlx)
{
    (k == KEY_ESC ? exit(0) : 1);
    mlx_clear_window(mlx->mptr, mlx->wptr);
	create_objects((t_mlx*)mlx);
	return (0);
}

int		close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
