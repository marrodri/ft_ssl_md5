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

uint8_t		*ft_append_128bit(uint32_t a0, uint32_t b0, uint32_t c0, uint32_t d0)
{
	static uint8_t	output[16];
	int i;

	i = 0;
	while(i < 4)
	{
		output[i] = output[i] | a0;
		a0 = a0 >> 8;
		i++;	
	}
	while(i < 8)
	{
		output[i] = output[i] | b0;
		b0 = b0 >> 8;
		i++;	
	}
	while(i < 12)
	{
		output[i] = output[i] | c0;
		c0 = c0 >> 8;
		i++;	
	}
	while(i < 16)
	{
		output[i] = output[i] | d0;
		d0 = d0 >> 8;
		i++;	
	}
	return output;
}

t_uint128_t		md5_hash(t_list *chunks)
{
	t_md5v		*md5Vr;
	uint32_t	*words;
	uint8_t		*chunk;
	

	uint32_t	i;
	uint32_t	g;
	uint32_t	F;
	uint32_t	a0 = A0;
	uint32_t	b0 = B0;
	uint32_t	c0 = C0;
	uint32_t	d0 = D0;
	uint32_t	A = a0;
	uint32_t	B = b0;
	uint32_t	C = c0;
	uint32_t	D = d0;
	uint32_t	R;
	chunk = NULL;
	md5Vr = malloc(sizeof(t_md5v));

	while(1)
	{
		i = 0;
		chunk = chunks->content;
		// printf("chunk is |%s|\n", chunk);
		words = split_32bitwords(chunk);
		for(int i = 0; i < 16; i++)
		{
			printf("word[%d] are in hex |%x|\n", i, words[i]);
		}
		while(i < 64)
		{
			if(i <= 15)
			{
				F = F_DIG(B,C,D);
				// printf("F i.%d is |%x|\n", i, F);
				g = i;
			}
			else if(i >= 16 && i <= 31)
			{
				F = G_DIG(B,C,D);
				g = (0x5 * i + 0x1) % 0x10;
			}
			else if(i >= 32 && i <= 47)
			{
				F = H_DIG(B,C,D);
				g = (0x3 * i + 0x5) % 0x10;
			}
			else if(i >= 48 && i <= 63)
			{
				F = I_DIG(B,C,D);
				g = (0x7 * i) % 0x10;
			}
			F = F + A + g_md5_key[i] + words[g];
			A = D;
			D = C;
			C = B;
			R = R_LEFT(F, g_md5_s[i]);
			B = B + R;
			// printf("hasshed F|%x|\n", F);
			// printf("A|%x|\n", A);
			// printf("D|%x|\n", D);
			// printf("C|%x|\n", C);
			// printf("rotation left|%x|\n", R);
			// printf("Rotated B|%x|\n", B);
			i++;
		}
		a0 = a0 + A;
		b0 = b0 + B;
		c0 = c0 + C;
		d0 = d0 + D;
		if(!chunks->next)
			break;
		chunks = chunks->next;
	}
	// uint8_t *digest;
	// digest = ft_append_128bit(a0, b0, c0, b0);
	printf("a0|%x|\nb0|%x|\nc0|%x|\nd0|%x|\n", a0,b0,c0,d0);
	//TO FIX OUTPUT IS BAD ASK FOR ALGO HELP
	// for(int i = 0; i < 16; i++)
	// {
	// 	printf("%x",digest[i]);
	// }
	printf("|\n");
	return 0;
}
