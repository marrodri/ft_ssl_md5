/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:09:23 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/08 20:49:16 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, unsigned int len)
{
	unsigned int	i;
	char			*ch;

	i = 0;
	ch = str;
	while (i < len)
	{
		ch[i] = c;
		i++;
	}
	return (ch);
}
