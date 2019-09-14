/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:03:53 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/14 15:03:54 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

const uint32_t g_sha1_key[4] =
{0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6};

void sha1_buff_init(t_hash **hash_v)
{
	(*hash_v)->h0 = (uint32_t*)malloc(5 * sizeof(uint32_t));
	(*hash_v)->h0[0] = 0x67452301; 
	(*hash_v)->h0[1] = 0xefcdab89; 
	(*hash_v)->h0[2] = 0x98badcfe; 
	(*hash_v)->h0[3] = 0x10325476; 
	(*hash_v)->h0[4] = 0xc3d2e1f0; 
}

uint8_t *sha1_hash(t_list *chunks, t_hash *hash_v)
{
	uint8_t *digest;
	uint32_t w_bf;
	uint8_t	*chunk;

	chunk = NULL;
	sha1_buff_init(&hash_v);
	while(chunks)
	{
		chunk = chunks->content;

		chunks = chunks->next;
	}
	digest = ft_append_256bit(hash_v->h0);
	return digest;
}