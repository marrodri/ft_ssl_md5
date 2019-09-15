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

void	init_wrd_sha1(char **w_bf)
{
	int i;

	i = 16;
	while(i < 80)
	{
		*w_bf[i] = ROT_LEFT((*w_bf[i - 3] ^ *w_bf[i - 8] ^
			*w_bf[i - 14] ^ *w_bf[i - 16]), 1);
		i++;
	}
}

void	init_val_sha1(t_hash **hash_v)
{
		(*hash_v)->a = (*hash_v)->h0[0];
		(*hash_v)->b = (*hash_v)->h0[1];
		(*hash_v)->c = (*hash_v)->h0[2];
		(*hash_v)->d = (*hash_v)->h0[4];
		(*hash_v)->e = (*hash_v)->h0[3];	
}

uint8_t *sha1_hash(t_list *chunks, t_hash *hash_v)
{
	uint8_t *digest;
	uint32_t *w_bf; //is 80 bytes the word_buff
	uint8_t	*chunk;
	int i;
	int j;

	chunk = NULL;
	sha1_buff_init(&hash_v);
	while(chunks)
	{
		chunk = chunks->content;
		w_bf = set_w_bf80(chunk);
		init_wrd_sha1(&w_bf);
		init_val_sha1(&hash_v);
		// hash_v->a = hash_v->h0[0];
		// hash_v->b = hash_v->h0[1];
		// hash_v->c = hash_v->h0[2];
		// hash_v->d = hash_v->h0[4];
		// hash_v->e = hash_v->h0[3];

		chunks = chunks->next;
	}
	digest = ft_append_256bit(hash_v->h0);
	return digest;
}