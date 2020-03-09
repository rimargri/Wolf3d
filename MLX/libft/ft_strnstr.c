/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:16:59 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/14 22:24:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len)
{
	size_t	i;
	ssize_t	n;

	n = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i <= len)
	{
		if ((n + i <= len) && (!(ft_memcmp(haystack + i, needle, n))))
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
