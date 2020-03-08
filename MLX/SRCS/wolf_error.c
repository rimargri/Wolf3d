/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:12:38 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:26:04 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	write_error(char *reason)
{
	int		i;

	i = 0;
	while (reason[i])
		i++;
	write(1, reason, i);
}

void	wolf_error(int n)
{
	if (n >= 0 && n <= 1)
		arguments_errors(n);
	if (n >= 2 && n <= 8)
		map_errors(n);
	if (n >= 9 && n <= 10)
		player_errors(n);
	if (n >= 11 && n <= 12)
		texture_errors(n);
	if (n == 13)
		malloc_errors(n);
	if (n >= 14 && n <= 16)
		mlx_errors(n);
	exit(0);
}

void	malloc_errors(int n)
{
	if (n == 13)
		write_error("wolf3d: memory allocation error.\n");
}
