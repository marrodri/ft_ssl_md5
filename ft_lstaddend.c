/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:11:44 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/22 17:11:48 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ssl.h"

void ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	// ft_printf("beg content is |%s|\n", tmp->content);
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	// ft_printf("after setting node tmp content is |%s|\n", tmp->content);
	// ft_printf("NEW NODE ADDED AT THE END!++++++");
}
