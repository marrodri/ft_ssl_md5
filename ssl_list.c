/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:37:11 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/06 22:37:13 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		free_list(t_list **list)
{
	t_list *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->content)
		{
			(*list)->content_size = 0;
			(*list)->content = NULL;
		}
		free(*list);
		(*list) = NULL;
		*list = tmp;
	}
}

t_list		*set_new_node(uint8_t *chunk, int bytes)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (chunk)
	{
		new->content = chunk;
		new->content_size = bytes;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}

void		add_new_chunk(t_list **list, uint8_t *chunk, int bytes)
{
	t_list	*new_chunk;

	new_chunk = set_new_node(chunk, bytes);
	if (*list == NULL)
		*list = new_chunk;
	else
		ft_lstaddend(list, new_chunk);
}

void	init_var_fd(t_lstcon **lst_v, t_hash **hash_v, uint32_t bytes)
{
	*lst_v = malloc(sizeof(t_lstcon));
	(*lst_v)->bit_len = 0;
	(*lst_v)->byte_len = 0;
	(*lst_v)->buff = ft_memalloc(bytes);
	ft_bzero((*lst_v)->buff, bytes);
	(*hash_v)->mssg = NULL;
}