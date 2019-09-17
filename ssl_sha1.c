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

void		*ft_append_160bit(uint32_t *input)
{
	static uint8_t	output[20];
	uint32_t		i;
	uint32_t		j;

	i = -1;
	while (++i < 5)
		input[i] = swap_endian(input[i]);
	i = 0;
	j = 0;

	while (j < 20)
	{
		output[j] = (input[i] & 0xff);
		output[j + 1] = ((input[i] >> 8) & 0xff);
		output[j + 2] = ((input[i] >> 16) & 0xff);
		output[j + 3] = ((input[i] >> 24) & 0xff);
		// output[j + 4] = ((input[i] >> 28) & 0xff);
		j += 5;
		i++;
	}
	return (output);
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

uint32_t	*init_wrd_sha1(uint32_t *w_bf)
{
	int i;

	i = 16;
	while(i < 80)
	{
		w_bf[i] = ROT_LEFT((w_bf[i - 3] ^ w_bf[i - 8] ^
			w_bf[i - 14] ^ w_bf[i - 16]), 1);
		i++;
	}
	return (w_bf);
}

void sha1_compr(t_hash **hash_v, uint32_t *w_bf)
{
	int			i;

	i = 0;
	while (i < 80)
	{
		if (i < 20)
		{
			(*hash_v)->f = F_DIG((*hash_v)->b,(*hash_v)->c,(*hash_v)->d);
			(*hash_v)->k = 0x5a827999;
		}
		else if (i < 40)
		{
			(*hash_v)->f = H_DIG((*hash_v)->b,(*hash_v)->c,(*hash_v)->d);
			(*hash_v)->k = 0x6ed9eba1;
		}
		else if (i < 60)
		{
			(*hash_v)->f = J_DIG((*hash_v)->b,(*hash_v)->c,(*hash_v)->d);
			(*hash_v)->k = 0x8f1bbcdc;
		}
		else if (i < 80)
		{
			(*hash_v)->f = H_DIG((*hash_v)->b,(*hash_v)->c,(*hash_v)->d);
			(*hash_v)->k = 0xca62c1d6;
		}
		(*hash_v)->tmp1 = ROT_LEFT((*hash_v)->a, 5) + (*hash_v)->f + (*hash_v)->e +(*hash_v)->k + w_bf[i];
		(*hash_v)->e = (*hash_v)->d;
		(*hash_v)->d = (*hash_v)->c;
		(*hash_v)->c = ROT_LEFT((*hash_v)->b, 30);
		(*hash_v)->b = (*hash_v)->a;
		(*hash_v)->a = (*hash_v)->tmp1;
		// ft_printf("a[%d] |%08x|\n", i, (*hash_v)->a);
		// ft_printf("b[%d] |%08x|\n", i, (*hash_v)->b);
		// ft_printf("c[%d] |%08x|\n", i, (*hash_v)->c);
		// ft_printf("d[%d] |%08x|\n", i, (*hash_v)->d);
		// ft_printf("e[%d] |%08x|\n", i, (*hash_v)->e);
		i++;
	}
}

void	init_val_sha1(t_hash **hash_v)
{
		(*hash_v)->a = (*hash_v)->h0[0];
		(*hash_v)->b = (*hash_v)->h0[1];
		(*hash_v)->c = (*hash_v)->h0[2];
		(*hash_v)->d = (*hash_v)->h0[3];
		(*hash_v)->e = (*hash_v)->h0[4];	
}

uint8_t *sha1_hash(t_list *chunks, t_hash *hash_v)
{
	uint8_t *digest;
	uint32_t *w_bf;
	uint8_t	*chunk;

	chunk = NULL;
	sha1_buff_init(&hash_v);
	while(chunks)
	{
		chunk = chunks->content;
		w_bf = set_w_bf80(chunk);
		
		w_bf = init_wrd_sha1(w_bf);
		// for(int i = 0; i < 80; i++)
		// {
		// 	ft_printf("w_bf[%d] is |%08x|\n", i, w_bf[i]);
		// }
		init_val_sha1(&hash_v);
		// ft_printf("----------init values--------\n");
		// ft_printf("a |%08x|\n", hash_v->a);
		// ft_printf("b |%08x|\n", hash_v->b);
		// ft_printf("c |%08x|\n", hash_v->c);
		// ft_printf("d |%08x|\n", hash_v->d);
		// ft_printf("e |%08x|\n", hash_v->e);
		sha1_compr(&hash_v,w_bf);
		// ft_printf("final buff VAL_______\n");
		// ft_printf("a |%08x|\n", hash_v->a);
		// ft_printf("b |%08x|\n", hash_v->b);
		// ft_printf("c |%08x|\n", hash_v->c);
		// ft_printf("d |%08x|\n", hash_v->d);
		// ft_printf("e |%08x|\n", hash_v->e);
		hash_v->h0[0] += hash_v->a;
		hash_v->h0[1] += hash_v->b;
		hash_v->h0[2] += hash_v->c;
		hash_v->h0[3] += hash_v->d;
		hash_v->h0[4] += hash_v->e;
		chunks = chunks->next;
	}
	for(int i = 0; i < 5; i++)
	ft_printf("h0[%d] |%08x|\n", i , hash_v->h0[i]);
	digest = ft_append_160bit(hash_v->h0);
	return digest;
}