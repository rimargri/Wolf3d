/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:12:21 by cvernius          #+#    #+#             */
/*   Updated: 2019/12/01 19:57:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(char *filename)
{
	char	*line;
	char	*s;
	char	*destroy;
	int		fd;

	s = ft_strnew(1);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		destroy = s;
		s = ft_strjoin((const char*)s, (const char*)line);
		free(destroy);
		destroy = s;
		s = ft_strjoin(s, "\n");
		free(destroy);
		free(line);
	}
	close(fd);
	return (s);
}
