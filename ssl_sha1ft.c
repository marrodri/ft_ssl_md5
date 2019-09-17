/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha1ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:04:32 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/16 22:04:34 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		sha1_buff_init(t_hash **hash_v)
{
	(*hash_v)->h0 = (uint32_t*)malloc(5 * sizeof(uint32_t));
	(*hash_v)->h0[0] = 0x67452301;
	(*hash_v)->h0[1] = 0xefcdab89;
	(*hash_v)->h0[2] = 0x98badcfe;
	(*hash_v)->h0[3] = 0x10325476;
	(*hash_v)->h0[4] = 0xc3d2e1f0;
}

uint32_t	*set_w_bf80(uint8_t *chunk)
{
	int			i;
	int			j;
	uint32_t	*w_bf;
	uint32_t	*words;

	words = (uint32_t*)(chunk);
	i = 0;
	j = 0;
	w_bf = ft_memalloc(80);
	while (i < 16)
	{
		w_bf[i] = words[i];
		i++;
	}
	while (j < 80)
	{
		w_bf[j] = swap_endian(w_bf[j]);
		j++;
	}
	return (w_bf);
}
