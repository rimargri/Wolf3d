/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:56:32 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/13 15:44:17 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (s)
	{
		j = ft_strlen((char*)s) - 1;
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		while (j >= i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
			j--;
		if (i == 0 && j == ft_strlen((char*)s) - 1)
			str = ft_strdup((char*)s);
		else
		{
			if (!(str = malloc(sizeof(char) * (j - i + 2))))
				return (NULL);
			str = ft_strsub((char*)s, i, j - i + 1);
		}
		return (str);
	}
	return (NULL);
}
