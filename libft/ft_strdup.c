/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:58:22 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/14 22:16:09 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str2;
	size_t	i;

	if ((str2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		i = 0;
		while (s1[i] != '\0')
		{
			str2[i] = s1[i];
			i++;
		}
		str2[i] = '\0';
		return (str2);
	}
	else
		return (NULL);
}
