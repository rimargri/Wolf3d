/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:54:59 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/03 15:36:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	unsigned const char *str1;
	unsigned const char *str2;

	str1 = (unsigned const char*)s1;
	str2 = (unsigned const char*)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0'
			&& str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}
