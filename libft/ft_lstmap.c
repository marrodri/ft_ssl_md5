/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:06:05 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/21 00:35:45 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *node;
	t_list *new_list;

	if (!lst)
		return (NULL);
	new_list = f(lst);
	node = new_list;
	if (node == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = f(lst);
		if (new_list->next == NULL)
			return (NULL);
		new_list = new_list->next;
	}
	return (node);
}
