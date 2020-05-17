/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:23:36 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/14 21:59:06 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	i = 0;
	source = (unsigned char*)src;
	dest = (unsigned char*)dst;
	while (n-- > 0)
	{
		dest[i] = source[i];
		if (source[i] == (unsigned char)c)
		{
			dest[i] = source[i];
			return ((void *)dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
