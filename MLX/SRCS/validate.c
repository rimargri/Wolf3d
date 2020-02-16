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
	int		map_i;

	map->h = 0;
	map->w = 0;
	i = 0;
	map_i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			map->h++;
			if (map->w != 0 && map->w != i / map->h)
			{
				free(map->line);
				wolf_error(SHAPE);
			}
			map->w = i / map->h;
		}
		else
		{
			map->line[map_i] = buf[i];
			if ((buf[i] < '0' || buf[i] > '9') && buf[i] != ' ')
				{
					free(map->line);
					wolf_error(MAP_SIMB);
				}
			map_i++;
		}
		i++;
	}
	map->line[map_i] = '\0';
}

void	check_square(t_map map)
{
	int		i;

	i = 0;
	while (i < map.w)
	{
		//гаризонталь первой и последней линий должны быть забиты числами
		if (map.line[i] < '0' || map.line[i] > '9')
			wolf_error(SHAPE);
		if (map.line[i + (map.h - 1) * (map.w)] < '0')
			wolf_error(SHAPE);
		i++;
	}
	i = 0;
	//вертикаль первой и последней линий должны быть забиты числами
	while (map.line[i])
	{
		if (map.line[i] < '0' || map.line[i] > '9')
			if (map.line[i] != '\n')
				wolf_error(SHAPE);
		if (map.line[i + map.w - 1] < '0')
			wolf_error(SHAPE);
		i += map.w;
	}
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
	//подготовка строки
	res.line = (char *)malloc(sizeof(char) * ret);
	//посимвольная проверка
	check_simbols(&res, buf);
	//проверка формы (пока доступен только прямоугольник)
	check_square(res);
	if (!(close(fd)))
		wolf_error("wolf3d: fd close error");
	return (res);
}
