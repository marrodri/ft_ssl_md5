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

uint32_t	*init_wrd_sha1(uint32_t *w_bf)
{
	int i;

	i = 16;
	while (i < 80)
	{
		w_bf[i] = ROT_LEFT((w_bf[i - 3] ^ w_bf[i - 8] ^
			w_bf[i - 14] ^ w_bf[i - 16]), 1);
		i++;
	}
	return (w_bf);
}

void		sha1_hash_rot(t_hash **hash_v, uint32_t *w_bf, int i)
{
	(*hash_v)->tmp1 = ROT_LEFT((*hash_v)->a, 5) + (*hash_v)->f +
		(*hash_v)->e + (*hash_v)->k + w_bf[i];
	(*hash_v)->e = (*hash_v)->d;
	(*hash_v)->d = (*hash_v)->c;
	(*hash_v)->c = ROT_LEFT((*hash_v)->b, 30);
	(*hash_v)->b = (*hash_v)->a;
	(*hash_v)->a = (*hash_v)->tmp1;
}

void		sha1_compr(t_hash **hash_v, uint32_t *w_bf, int i)
{
	if (i < 20)
	{
		(*hash_v)->f = F_DIG((*hash_v)->b, (*hash_v)->c, (*hash_v)->d);
		(*hash_v)->k = 0x5a827999;
	}
	else if (i < 40)
	{
		(*hash_v)->f = H_DIG((*hash_v)->b, (*hash_v)->c, (*hash_v)->d);
		(*hash_v)->k = 0x6ed9eba1;
	}
	else if (i < 60)
	{
		(*hash_v)->f = J_DIG((*hash_v)->b, (*hash_v)->c, (*hash_v)->d);
		(*hash_v)->k = 0x8f1bbcdc;
	}
	else if (i < 80)
	{
		(*hash_v)->f = H_DIG((*hash_v)->b, (*hash_v)->c, (*hash_v)->d);
		(*hash_v)->k = 0xca62c1d6;
	}
	sha1_hash_rot(hash_v, w_bf, i);
}

void		init_val_sha1(t_hash **hash_v)
{
	(*hash_v)->a = (*hash_v)->h0[0];
	(*hash_v)->b = (*hash_v)->h0[1];
	(*hash_v)->c = (*hash_v)->h0[2];
	(*hash_v)->d = (*hash_v)->h0[3];
	(*hash_v)->e = (*hash_v)->h0[4];
}

uint8_t		*sha1_hash(t_list *chunks, t_hash *hash_v)
{
	uint32_t	*w_bf;
	uint8_t		*chunk;
	int			i;

	chunk = NULL;
	sha1_buff_init(&hash_v);
	while (chunks)
	{
		i = -1;
		chunk = chunks->content;
		w_bf = set_w_bf80(chunk);
		w_bf = init_wrd_sha1(w_bf);
		init_val_sha1(&hash_v);
		while (++i < 80)
			sha1_compr(&hash_v, w_bf, i);
		hash_v->h0[0] += hash_v->a;
		hash_v->h0[1] += hash_v->b;
		hash_v->h0[2] += hash_v->c;
		hash_v->h0[3] += hash_v->d;
		hash_v->h0[4] += hash_v->e;
		chunks = chunks->next;
	}
	put1hash(hash_v);
	return (0);
}
