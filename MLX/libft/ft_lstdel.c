/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:11:41 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/15 02:33:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**lst;
	t_list	*tmp;

	if (alst && *alst && del)
	{
		lst = alst;
		while (*lst)
		{
			del((*lst)->content, (*lst)->content_size);
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
		free(*alst);
		*alst = NULL;
	}
}
