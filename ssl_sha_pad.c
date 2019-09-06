/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha_pad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:53:20 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/04 20:53:22 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/* 
**DELETE IF NOT USED FOR SHA256
*/

uint32_t		ft_32bitpad(uint8_t *chunk, int *j)
{
	int			i;
	uint32_t	word;

	i = 0;
	word = 0;
	while (i < 4)
	{
		word = (word << 8) | chunk[*j];
		*j += 1;
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
		// ft_printf("dec is|%u| hex is|%x|\n", words[i]);
		i++;
	}
	return words;
}
