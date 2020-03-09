/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:10:15 by cvernius          #+#    #+#             */
/*   Updated: 2019/05/15 00:43:43 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;
	size_t	data_size;

	data_size = content_size;
	if (!(new_node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		data_size = 0;
		new_node->content = NULL;
	}
	else
	{
		new_node->content = malloc(sizeof(data_size));
		if (!new_node->content)
		{
			free(new_node);
			return (NULL);
		}
		new_node->content = ft_memcpy(new_node->content, content, data_size);
	}
	new_node->content_size = data_size;
	new_node->next = NULL;
	return (new_node);
}
