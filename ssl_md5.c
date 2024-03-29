/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:05:42 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/27 16:05:44 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

const uint32_t	g_md5_key[64] =
{0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

const uint32_t	g_md5_s[64] =
{7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

uint8_t		*ft_append_128bit(uint32_t *input)
{
	static uint8_t	output[16];
	uint32_t		i;
	uint32_t		j;

	i = 0;
	j = 0;
	while (j < 16)
	{
		output[j] = (input[i] & 0xff);
		output[j + 1] = ((input[i] >> 8) & 0xff);
		output[j + 2] = ((input[i] >> 16) & 0xff);
		output[j + 3] = ((input[i] >> 24) & 0xff);
		j += 4;
		i++;
	}
	return (output);
}

void		md5_buff_init(t_hash **hash_v)
{
	(*hash_v)->h0 = (uint32_t*)malloc(4 * sizeof(uint32_t));
	(*hash_v)->h_bf = (uint32_t*)malloc(4 * sizeof(uint32_t));
	(*hash_v)->h0[0] = 0x67452301;
	(*hash_v)->h0[1] = 0xefcdab89;
	(*hash_v)->h0[2] = 0x98badcfe;
	(*hash_v)->h0[3] = 0x10325476;
	(*hash_v)->h_bf[0] = (*hash_v)->h0[0];
	(*hash_v)->h_bf[1] = (*hash_v)->h0[1];
	(*hash_v)->h_bf[2] = (*hash_v)->h0[2];
	(*hash_v)->h_bf[3] = (*hash_v)->h0[3];
}

void		md5_buff_upadte(t_hash *hash_v)
{
	hash_v->h_bf[0] += hash_v->h0[0];
	hash_v->h_bf[1] += hash_v->h0[1];
	hash_v->h_bf[2] += hash_v->h0[2];
	hash_v->h_bf[3] += hash_v->h0[3];
	hash_v->h0[0] = hash_v->h_bf[0];
	hash_v->h0[1] = hash_v->h_bf[1];
	hash_v->h0[2] = hash_v->h_bf[2];
	hash_v->h0[3] = hash_v->h_bf[3];
}

void		md5_proc(t_hash *hash_v, uint32_t i, uint32_t g, uint32_t *words)
{
	if (i <= 15)
	{
		hash_v->f = F_DIG(hash_v->h_bf[1], hash_v->h_bf[2], hash_v->h_bf[3]);
		g = i;
	}
	else if (i >= 16 && i <= 31)
	{
		hash_v->f = G_DIG(hash_v->h_bf[1], hash_v->h_bf[2], hash_v->h_bf[3]);
		g = (0x5 * i + 0x1) % 0x10;
	}
	else if (i >= 32 && i <= 47)
	{
		hash_v->f = H_DIG(hash_v->h_bf[1], hash_v->h_bf[2], hash_v->h_bf[3]);
		g = (0x3 * i + 0x5) % 0x10;
	}
	else if (i >= 48 && i <= 63)
	{
		hash_v->f = I_DIG(hash_v->h_bf[1], hash_v->h_bf[2], hash_v->h_bf[3]);
		g = (0x7 * i) % 0x10;
	}
	hash_v->f = hash_v->f + hash_v->h_bf[0] + g_md5_key[i] + words[g];
	hash_v->h_bf[0] = hash_v->h_bf[3];
	hash_v->h_bf[3] = hash_v->h_bf[2];
	hash_v->h_bf[2] = hash_v->h_bf[1];
	hash_v->h_bf[1] = hash_v->h_bf[1] + ROT_LEFT(hash_v->f, g_md5_s[i]);
}

uint8_t		*md5_hash(t_list *chunks, t_hash *hash_v)
{
	uint32_t	*words;
	uint8_t		*chunk;
	uint32_t	i;
	uint32_t	g;
	uint8_t		*digest;

	md5_buff_init(&hash_v);
	chunk = NULL;
	g = 0;
	while (chunks)
	{
		i = 0;
		chunk = chunks->content;
		words = (uint32_t*)(chunk);
		while (i < 64)
		{
			md5_proc(hash_v, i, g, words);
			i++;
		}
		md5_buff_upadte(hash_v);
		chunks = chunks->next;
	}
	digest = ft_append_128bit(hash_v->h0);
	put_md5hash(digest);
	return (digest);
}
