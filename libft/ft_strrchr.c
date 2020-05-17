/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:01:03 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/06 18:34:49 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	sym;
	char	*adr;

	adr = (char*)s;
	sym = (char)c;
	i = ft_strlen(s);
	if (sym == '\0')
		return ((char *)&s[i]);
	while (s[i] != sym && &s[i] != adr)
		i--;
	if (sym == s[i])
		return ((char *)&s[i]);
	else
		return (NULL);
}
