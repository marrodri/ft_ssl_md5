/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_bit_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:43:09 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/06 22:43:24 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int			check_last8bytes(uint8_t *chunk, int bytes)
{
	int i;
	int dif;

	i = bytes - 1;
	dif = bytes - 8;
	while (i >= dif)
	{
		if (chunk[i] != 0x00)
			return (0);
		i--;
	}
	return (1);
}

uint8_t		*ft_append_bytes(uint8_t *chunk, int ret, int bytes)
{
	int	i;
	int	dif;

	i = ret + 1;
	dif = bytes - 8;
	chunk[ret] = (chunk[ret] << 8) | 0x80;
	while (i < bytes)
	{
		chunk[i] = (chunk[i] << 8) | 0x00;
		i++;
	}
	return (chunk);
}

uint64_t	byte_length(uint64_t val)
{
	int i;

	i = 0;
	while (val)
	{
		val = val >> 8;
		i++;
	}
	return (i);
}
