/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:17:01 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/07 20:24:52 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	arguments_errors(int n)
{
	if (n == 0)
		write_error("wolf3d: missing argument after call\n\
							usage: ./wolf3d [file]\n");
	if (n == 1)
		write_error("wolf3d: too much arguments, expected one\n\
							usage: ./wolf3d [file]\n");
}

void	map_errors(int n)
{
	if (n == 2)
		write_error("wolf3d: map is invalid!\n\
							it should consist of only numbers and spaces\n");
	if (n == 3)
		write_error("wolf3d: map is invalid!\n\
							shape of map should remind a square\n");
	if (n == 4)
		write_error("wolf3d: map is empty!\n\
							it should consist of only numbers and spaces\n");
	if (n == 5)
		write_error("wolf3d: can't open a map\n");
	if (n == 6)
		write_error("wolf3d: map is too big! try to load another one\n");
	if (n == 7)
		write_error("wolf3d: map can't be a directory!\n\
							wolf3d: please check path\n");
	if (n == 8)
		write_error("wolf3d: fd close error\n");
}

void	player_errors(int n)
{
	if (n == 9)
		write_error("wolf3d: can't put player on map\n\
							please, check if map has any space for him!\n");
	if (n == 10)
		write_error("wolf3d: too much of \"x\" characters on map.\n\
							Game wrote for one player only. Please remove\n\
							extra position-indificators or delete them all.\n");
}

void	texture_errors(int n)
{
	if (n == 11)
		write_error("wolf3d: can't load texture. Please, check the path.\n\
				Your image should be written in jpeg, pmg or bmp format.\n");
	if (n == 12)
		write_error("wolf3d: can't load texture. Color channels conflict.\n");
}

void	mlx_errors(int n)
{
	if (n == 14)
		write_error("wolf3d: can't open window\n");
	if (n == 15)
		write_error("wolf3d: mlx error: can't initialize mlx-connetcion\n");
	if (n == 16)
		write_error("wolf3d: image allocation error.\n");
}
