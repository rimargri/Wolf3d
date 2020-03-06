/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:19:43 by hchau             #+#    #+#             */
/*   Updated: 2020/03/06 22:49:42 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_simbols(t_map *map, char *buf)
{
	int		i;
	int		cur_w;
	int		x_flag;

	map->h = 0;
	map->w = 0;
	cur_w = 0;
	x_flag = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			map->h++;
			if (map->w < cur_w)
				map->w = cur_w;
			cur_w = 0;
		}
		else
		{
			if ((buf[i] < '0' || buf[i] > '9')
										&& buf[i] != ' ' && buf[i] != 'x')
			{
				if (buf[i] == 'x')
					x_flag++;
				else
					wolf_error(MAP_SIMB);
			}
			cur_w++;
		}
		i++;
	}
	x_flag > 1 ? wolf_error(EXNTRA_X) : 0;
}

void	make_empty_map(t_map *map)
{
	map->h = 1;
	map->w = 1;
	map->line[0] = ' ';
	map->line[1] = '\0';
}

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

t_map	validate(int ac, char **maps)
{
	t_map	res;
	char	buf[MAX_MAP];
	int		fd;
	int		ret;

	//все проверки валидности самого аргумента
	if (ac < 2)
		wolf_error(MISSING_ARG);
	if (ac > 2)
		wolf_error(TOO_MUCH);
	if ((fd = open(maps[1], O_DIRECTORY)) > 0)
		wolf_error(DIRECTORY_ERR);
	close(fd);
	if ((fd = open(maps[1], O_RDONLY)) < 3)
		wolf_error(NOT_A_FILE);
	//считывание в буффер
	if ((ret = read(fd, buf, MAX_MAP)) >= MAX_MAP - 1)
		wolf_error(TOO_BIG);
	buf[ret] = '\0';
	if (buf[ret - 1] != '\n')
	{
		buf[ret] = '\n';
		buf[ret + 1] = '\0';
	}
	//подготовка строки
	//посимвольная проверка
	check_simbols(&res, buf);
	if (!(res.line = (char *)malloc(sizeof(char) * ((res.h + 1) * (res.w + 1)))))
		wolf_error(MALLOC_ERROR);
	record_shape(&res, buf);
	//если мапа пустая:
	if (ret < 2)
		make_empty_map(&res);
	if ((close(fd)))
		wolf_error(CLOSE_FD_ERROR);
	return (res);
}
