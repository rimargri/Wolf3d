/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:09:55 by hchau             #+#    #+#             */
/*   Updated: 2020/03/08 14:09:56 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	record_shape(t_map *map, char *src)
{
	int		i;
	int		str_diff;
	int		comm_diff;

	i = 0;
	comm_diff = 0;
	while (src[i])
	{
		str_diff = 0;
		while (src[i] && src[i] != '\n')
		{
			map->line[comm_diff] = src[i];
			i++;
			str_diff++;
			comm_diff++;
		}
		while (str_diff < map->w)
		{
			map->line[comm_diff] = ' ';
			comm_diff++;
			str_diff++;
		}
		i = src[i] ? ++i : i;
	}
	map->line[comm_diff] = '\0';
}

void	make_empty_map(t_map *map)
{
	map->h = 1;
	map->w = 1;
	map->line[0] = ' ';
	map->line[1] = '\0';
}

void	prepare_map(t_map *map, char *src, int ret)
{
	if (!(map->line =
			(char *)malloc(sizeof(char) * ((map->h + 1) * (map->w + 1)))))
		wolf_error(MALLOC_ERROR);
	if (ret < 2)
	{
		make_empty_map(map);
		return ;
	}
	record_shape(map, src);
}
