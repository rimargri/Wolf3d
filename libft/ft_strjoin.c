/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:56:02 by cvernius          #+#    #+#             */
/*   Updated: 2019/06/13 16:46:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s;

	s2_len = 0;
	s1_len = 0;
	s = NULL;
	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		if ((s = malloc((sizeof(char)) * (s1_len + s2_len + 1))))
		{
			s = ft_strcpy(ft_strncpy(s, s1, s1_len) + s1_len, s2);
			return (s - s1_len);
		}
	}
	return (NULL);
}
