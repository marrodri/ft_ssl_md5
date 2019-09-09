/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha256ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:15:43 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/08 21:15:44 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t	*set_w_bf(uint8_t *chunk)
{
	int			i;
	int			j;
	uint32_t	*w_bf;
	uint32_t	*words;

	words = (uint32_t*)(chunk);
	i = 0;
	j = 0;
	w_bf = ft_memalloc(64);
	while (i < 16)
	{
		w_bf[i] = words[i];
		i++;
	}
	while (j < 64)
	{
		w_bf[j] = swap_endian(w_bf[j]);
		j++;
	}
	return (w_bf);
}

void		*ft_append_256bit(uint32_t *input)
{
	static uint8_t	output[32];
	uint32_t		i;
	uint32_t		j;

	i = -1;
	while (++i < 8)
		input[i] = swap_endian(input[i]);
	i = 0;
	j = 0;
	while (j < 32)
	{
		output[j] = (input[i] & 0xff);
		output[j + 1] = ((input[i] >> 8) & 0xff);
		output[j + 2] = ((input[i] >> 16) & 0xff);
		output[j + 3] = ((input[i] >> 24) & 0xff);
		output[j + 4] = (input[i + 1] & 0xff);
		output[j + 5] = ((input[i + 1] >> 8) & 0xff);
		output[j + 6] = ((input[i + 1] >> 16) & 0xff);
		output[j + 7] = ((input[i + 1] >> 24) & 0xff);
		j += 8;
		i += 2;
	}
	return (output);
}
