/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha256.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:01:05 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/31 03:01:07 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

const uint32_t	g_sha256_key[64] =
{0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
	0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
	0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
	0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
	0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
	0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
	0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
	0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void	*ft_append_256bit(uint32_t *input)
{
	static uint8_t output[32];
	uint32_t i;
	uint32_t j;
	i = -1;
	while(++i < 8)
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

void	sha256_buff_init(t_hash **hash_v)
{
	(*hash_v)->h0 = (uint32_t*)malloc(8 * sizeof(uint32_t));
	(*hash_v)->h0[0] = 0x6a09e667;
	(*hash_v)->h0[1] = 0xbb67ae85;
	(*hash_v)->h0[2] = 0x3c6ef372;
	(*hash_v)->h0[3] = 0xa54ff53a;
	(*hash_v)->h0[4] = 0x510e527f;
	(*hash_v)->h0[5] = 0x9b05688c;
	(*hash_v)->h0[6] = 0x1f83d9ab;
	(*hash_v)->h0[7] = 0x5be0cd19;
}

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
	while(i < 16)
	{
		w_bf[i] = words[i];
		i++;
	}
	while(j < 64)
	{
		w_bf[j] = swap_endian(w_bf[j]);
		j++;
	}
	return (w_bf);
}

uint32_t	*init_val_sha256(t_hash *hash_v, uint32_t *w_bf)
{
	int i;

	i = 16;
	while(i < 64)
	{
		hash_v->s0 = SSIG0(w_bf[i - 15]);
		hash_v->s1 = SSIG1(w_bf[i - 2]);
		w_bf[i] = w_bf[i - 16] + hash_v->s0 + w_bf[i - 7] + hash_v->s1;
		i++;
	}
	return w_bf;
}

uint8_t *sha256_hash(t_list *chunks, t_hash *hash_v)
{
	uint8_t		*digest;
	uint32_t	*words;
	uint32_t	*w_bf;
	int			i;	
	uint8_t		*chunk;



	digest = NULL;
	words = NULL;
	sha256_buff_init(&hash_v);
	chunk = NULL;
	while (chunks)
	{
		chunk = chunks->content;
		w_bf = set_w_bf(chunk);
		w_bf = init_val_sha256(hash_v, w_bf);
		// i = 16;
		// while(i < 64)
		// {
		// 	hash_v->s0 = SSIG0(w_bf[i - 15]);
		// 	hash_v->s1 = SSIG1(w_bf[i - 2]);
		// 	w_bf[i] = w_bf[i - 16] + hash_v->s0 + w_bf[i - 7] + hash_v->s1;
		// 	i++;
		// }
		hash_v->a = hash_v->h0[0];
		hash_v->b = hash_v->h0[1];
		hash_v->c = hash_v->h0[2];
		hash_v->d = hash_v->h0[3];
		hash_v->e = hash_v->h0[4];
		hash_v->f = hash_v->h0[5];
		hash_v->g = hash_v->h0[6];
		hash_v->h = hash_v->h0[7];
		i = 0;
		while(i < 64)
		{
			hash_v->s1 = BSIG1(hash_v->e);
			hash_v->ch = CH(hash_v->e, hash_v->f, hash_v->g);
			hash_v->tmp1 = hash_v->h + hash_v->s1 + hash_v->ch + g_sha256_key[i] + w_bf[i];
			hash_v->s0 = BSIG0(hash_v->a);
			hash_v->maj = MAJ(hash_v->a, hash_v->b, hash_v->c);
			hash_v->tmp2 = hash_v->s0 + hash_v->maj;
			hash_v->h = hash_v->g;
			hash_v->g = hash_v->f;
			hash_v->f = hash_v->e;
			hash_v->e = hash_v->d + hash_v->tmp1;
			hash_v->d = hash_v->c;
			hash_v->c = hash_v->b;
			hash_v->b = hash_v->a;
			hash_v->a = hash_v->tmp1 + hash_v->tmp2;
			i++;
		}
		hash_v->h0[0] += hash_v->a;
		hash_v->h0[1] += hash_v->b;
		hash_v->h0[2] += hash_v->c;
		hash_v->h0[3] += hash_v->d;
		hash_v->h0[4] += hash_v->e;
		hash_v->h0[5] += hash_v->f;
		hash_v->h0[6] += hash_v->g;
		hash_v->h0[7] += hash_v->h;
		chunks = chunks->next;
	}
	digest = ft_append_256bit(hash_v->h0);
	return (digest);
}
