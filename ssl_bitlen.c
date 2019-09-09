/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_bitlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:29 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/07 19:33:30 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t		*app_bitlen_sha256(uint8_t *chunk, int bytes, uint64_t bit_len)
{
	int i;
	int dif;
	i = bytes - 1;
	dif = bytes - 8;
	while (i >= dif)
	{
		chunk[i] = (chunk[i] << 8) | bit_len;
		chunk[i] = chunk[i] | bit_len;
		bit_len = bit_len >> 8;
		i--;
	}
	return (chunk);
}

uint8_t		*app_bitlen_md5(uint8_t *chunk, int bytes, uint64_t bit_len)
{
	int			i;
	uint64_t	push;
	uint64_t	tmp;
	uint64_t	lim;

	lim = byte_length(bit_len);
	i = (bytes - 8) + lim;
	push = (lim) * 8;
	while (i >= 56)
	{
		tmp = bit_len;
		tmp = bit_len >> push;
		chunk[i] = 0x00 | tmp;
		i--;
		push -= 8;
	}
	return (chunk);
}


uint8_t	*bitlen_tb(int input, uint8_t *chunk, int bytes, uint64_t bit_len)
{
	t_bitlen_app *bitlen_algo[HS_SZ];

	bitlen_algo[0] = app_bitlen_md5;
	bitlen_algo[1] = app_bitlen_sha256;
	return (bitlen_algo[input](chunk, bytes, bit_len));
}
