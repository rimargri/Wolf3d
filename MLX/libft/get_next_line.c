/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:05:08 by cvernius          #+#    #+#             */
/*   Updated: 2019/09/24 01:10:34 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		func1(char **s, int fd, char **line, char *tmp)
{
	char	*dump;

	*line = ft_strsub(s[fd], 0, tmp - s[fd]);
	if (!s[fd])
		return (-1);
	dump = s[fd];
	s[fd] = ft_strsub(s[fd], tmp - s[fd] + 1, s[fd] + ft_strlen(s[fd]) - tmp);
	if (!s[fd])
		return (-1);
	free(dump);
	return (1);
}

int		func2(char **s, int fd, char **line)
{
	*line = ft_strdup(s[fd]);
	if (!s[fd])
		return (-1);
	ft_bzero(s[fd], ft_strlen(s[fd]));
	free(s[fd]);
	return (1);
}

int		func3(char *buf, int n, char **s, int fd)
{
	char	*dump;

	buf[n] = '\0';
	dump = s[fd];
	s[fd] = ft_strjoin(s[fd], buf);
	if (!s[fd])
		return (-1);
	free(dump);
	if (ft_memchr(buf, '\n', BUFF_SIZE))
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			n;
	int			temp;
	char		*tmp;
	static char	*s[FD_LIMIT];

	if (fd < 0 || fd == 1 || fd == 2 || read(fd, 0, 0) < 0 || !line
												|| BUFF_SIZE < 0)
		return (-1);
	s[fd] = (!s[fd]) ? (ft_strnew(1)) : s[fd];
	n = -1;
	tmp = NULL;
	while ((n = read(fd, &buf, BUFF_SIZE)))
		if ((temp = func3(buf, n, s, fd)))
			break ;
		else if (temp == -1)
			return (-1);
	if ((tmp = ft_strchr(s[fd], '\n')))
		return (func1(s, fd, line, tmp));
	else if (*s[fd] != 0)
		return (func2(s, fd, line));
	line = NULL;
	return ((n == 0) ? 0 : -1);
}
