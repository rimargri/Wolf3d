/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:10:09 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/06 18:58:27 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char *str1;
	unsigned const char *str2;

	if (n == 0)
		return (0);
	str1 = (unsigned const char*)s1;
	str2 = (unsigned const char*)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0'
															&& i < (n - 1))
		i++;
	return (str1[i] - str2[i]);
}
