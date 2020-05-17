/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:55:53 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/15 02:38:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*p;

	i = 0;
	j = 0;
	if (len + 1 == 0)
		return (NULL);
	if (s && (p = malloc((sizeof(char) * (len + 1)))))
	{
		while (s[i] != '\0' && i != start)
			i++;
		while (j < len)
		{
			p[j] = s[i];
			i++;
			j++;
		}
		p[j] = '\0';
		return (p);
	}
	return (NULL);
}
