/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:48:35 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/06 16:48:37 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ssl.h"

// void	free_list(t_list **list)
// {
// 	t_list *tmp;

// 	while (*list)
// 	{
// 		tmp = (*list)->next;
// 		if ((*list)->content)
// 		{
// 			(*list)->content_size = 0;
// 			(*list)->content = NULL;
// 		}
// 		free(*list);
// 		(*list) = NULL;
// 		*list = tmp;
// 	}
// }
