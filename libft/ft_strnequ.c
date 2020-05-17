/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:55:24 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/12 19:29:02 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (1);
	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && i < n && s1[i] == s2[i])
			i++;
	}
	else
		return (1);
	if ((s1[i - 1] == s2[i - 1] && i == n)
			|| (s1[i] == '\0' && s2[i] == '\0' && s1[i - 1] == s2[i - 1]))
		return (1);
	else
		return (0);
}
