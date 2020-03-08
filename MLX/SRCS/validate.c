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

void	check_str(char c, int *x_flag)
{
	if ((c < '0' || c > '9'))
	{
		if (c == 'x')
			*x_flag = *x_flag + 1;
		else if (c != ' ')
			wolf_error(MAP_SIMB);
	}
}

void	check_simbols(t_map *map, char *buf)
{
	int		i;
	int		cur_w;
	int		x_flag;

	map->h = 0;
	map->w = 0;
	cur_w = 0;
	x_flag = 0;
	i = -1;
	while (buf[++i])
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
			check_str(buf[i], &x_flag);
			cur_w++;
		}
	}
	x_flag > 1 ? wolf_error(EXNTRA_X) : 0;
}

void	check_read_file(int ac, char **maps)
{
	int		fd;

	if (ac < 2)
		wolf_error(MISSING_ARG);
	if (ac > 2)
		wolf_error(TOO_MUCH);
	if ((fd = open(maps[1], O_DIRECTORY)) > 0)
		wolf_error(DIRECTORY_ERR);
	close(fd);
}

t_map	validate(int ac, char **maps)
{
	t_map	res;
	char	buf[MAX_MAP];
	int		fd;
	int		ret;

	check_read_file(ac, maps);
	if ((fd = open(maps[1], O_RDONLY)) < 3)
		wolf_error(NOT_A_FILE);
	if ((ret = read(fd, buf, MAX_MAP)) >= MAX_MAP - 1)
		wolf_error(TOO_BIG);
	buf[ret] = '\0';
	if (buf[ret - 1] != '\n')
	{
		buf[ret] = '\n';
		buf[ret + 1] = '\0';
	}
	check_simbols(&res, buf);
	prepare_map(&res, buf, ret);
	if ((close(fd)))
		wolf_error(CLOSE_FD_ERROR);
	return (res);
}
