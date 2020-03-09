/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:53:39 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/14 23:45:24 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	int		i;
	int		count;
	int		temp;
	char	*st;

	if (s)
	{
		st = (char*)s;
		i = 0;
		count = ft_strlen(s);
		while (i < count / 2)
		{
			temp = st[i];
			st[i] = st[count - i - 1];
			st[count - 1 - i] = temp;
			i++;
		}
		return (st);
	}
	return (NULL);
}
