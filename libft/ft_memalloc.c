/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:46:39 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 20:49:00 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	uint32_t		*str;

	i = 0;
	str = (uint32_t *)malloc(size * sizeof(uint32_t));
	while (i < size)
	{
		if (str == NULL)
			return (NULL);
		str[i] = 0;
		i++;
	}
	str[i] = 0;
	return (str);
}
