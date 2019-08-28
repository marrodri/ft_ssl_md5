/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_pad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 21:26:53 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/27 21:26:56 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t		ft_32bitpad(uint8_t *chunk, int *j)
{
	int			i;
	uint32_t	word;

	i = 0;
	word = 0;
	while(i < 4)
	{
		word = (word << 8) | chunk[*j];
		*j+= 1;
		i++;
	}
	return word;
}

uint32_t		*split_32bitwords(uint8_t *chunk)
{
	int				i;
	int 			j;
	static uint32_t	words[16];

	i = 0;
	j = 0;
	while (i < 16)
	{
		words[i] = ft_32bitpad(chunk, &j);
		// printf("dec is|%u| hex is|%x|\n", words[i]);
		i++;
	}
	return words;
}
