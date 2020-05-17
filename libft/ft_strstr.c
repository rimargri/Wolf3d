/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:33:20 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/15 02:23:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (!(ft_memcmp(haystack + i, needle, n)))
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
