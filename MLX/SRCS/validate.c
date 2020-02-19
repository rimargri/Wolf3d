//
// Created by Hugor Chau on 2020-02-11.
//
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "wolf3d.h"

void	wolf_error(char *reason)
{
	int		i;

	i = 0;
	while(reason[i])
		i++;
	write(1, reason, i);
	exit(0);
}

void	check_simbols(t_map *map, char *buf)
{
	//ты считываешь фигуру подряд, без разделителей строки,
	//поэтому перепись получилась довольно большая, позже
	//разобью
	int		i;
	int		cur_w;

	map->h = 0;
	map->w = 0;
	cur_w = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			map->h++;
			if (map->w < cur_w)
			{
				map->w = cur_w;
			}
			cur_w = 0;
		}
		else
		{
			if ((buf[i] < '0' || buf[i] > '9') && buf[i] != ' ')
				{
					free(map->line);
					wolf_error(MAP_SIMB);
				}
			cur_w++;
		}
		i++;
	}
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
	if ((ret = read(fd, buf, MAX_MAP)) == MAX_MAP)
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
	res.line = (char *)malloc(sizeof(char) * (res.h * res.w + 1));
	//проверка формы (пока доступен только прямоугольник)
//	check_square(res);
	record_shape(&res, buf);
	//если мапа пустая:
//	if (ret == 0)
//		make_empty_map(&res);
	if ((close(fd)))
		wolf_error(CLOSE_FD_ERROR);
//	printf("\n%s", res.line);
	return (res);
}
