/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/11 20:07:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*get_map(void)
{
	char *map;
    
	map = (char*)malloc(sizeof(char) * 258);
	map   = "0000222222220000"\
			"1              0"\
			"1      11111   0"\
			"1     0        0"\
			"0     0  1110000"\
			"0     3        0"\
			"0   10000      0"\
			"0   0   11100  0"\
			"0   0   0      0"\
			"0   0   1  00000"\
			"0       1      0"\
			"2       1      0"\
			"0       0      0"\
			"0 0000000      0"\
			"0              0"\
			"0002222222200000";
	return (map);
}

void	create_objects(t_mlx *mlx)
{
	t_player player;

	background_for_map(mlx);
	walls_on_map(mlx, mlx->map);
	player = player_on_map(mlx); //! проинициализировать player в начале т к потом камера будет двигаться -> будут меняться значения
	// printf("player.x = %d\nplayer.y = %d\n", player.x, player.y);
	cast_ray(mlx, mlx->map, player);
}

int		main(void)
{
	t_mlx *mlx;

	mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
	mlx->mptr = mlx_init();
	mlx->wptr = mlx_new_window(mlx->mptr, WIN_W, WIN_H, "WOLF3D\0");
	mlx->map = get_map();
	create_objects(mlx);
	mlx_hook(mlx->wptr, 17, 0, &close_hook, mlx);
	mlx_hook(mlx->wptr, 2, 0, &key_press, mlx);
	// mlx_hook(mlx->win_ptr, 4, 0, &mouse_hook, mlx);
	// mlx_hook(mlx->win_ptr, 6, 0, &move_hook, mlx);
	mlx_loop(mlx->mptr);
	return (0);
}
