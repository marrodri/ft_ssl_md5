/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:22:07 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/19 12:24:37 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;
	void	*copy;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		copy = (void *)malloc((content_size) * sizeof(void));
		if (copy == NULL || new_node == NULL)
			return (NULL);
		ft_memcpy(copy, content, content_size);
		new_node->content = copy;
		new_node->content_size = content_size;
	}
	new_node->next = NULL;
	return (new_node);
}
