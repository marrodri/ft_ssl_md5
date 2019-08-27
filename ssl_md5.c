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


//TODO md5 algo implemented



#include "ssl.h"

// void	md5v_init(t_md5v **md5Vr)
// {
// 	(*md5Vr)->a0 = A0;
// 	(*md5Vr)->b0 = B0;
// 	(*md5Vr)->c0 = C0;
// 	(*md5Vr)->d0 = D0;
// }

uint32_t ft_32bitpad(uint8_t *chunk, int *j)
{
	int i;
	uint32_t word;
	i = 0;
	word = 0;
	while(i < 4)
	{
		word = (word << 8) | chunk[*j];
		*j+= 1;
		i++;
	}
	return word;
}

uint32_t *split_32bitwords(uint32_t *words, uint8_t *chunk)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		words[i] = (chunk, &j);
		printf("dec is|%u| hex is|%x|\n", words[i]);
		i++;
	}
	return words;
}

t_uint128_t	md5_hash(t_list *chunks, t_hash *hash)
{
	t_md5v *md5Vr;
	uint32_t *words;
	uint8_t md[16];
	int j;
	t_uint128_t crypt;

	j = 0;
	md5Vr = malloc(sizeof(t_md5v));
	// md5v_init(&md5Vr);
	uint8_t *chunk = chunks->content;
	//memory allocate for 16 spaces of 32 bits
	words = split_32bitwords(words, chunk);
	for(int i = 0; i < 16; i++)
	{

	}
}
	// while(1)
	// {
	// 	j = 0;
	// 	while(j < 16)
	// 	{

	// 	}
	// 	if(!chunks->next)
	// 		break;
	// 	chunks = chunks->next;
	// }

	//proccess the message in successive 512-bit chunks 2 while loops
	//t_uint M[j] M[16]
	// while(j < 16) //while chunks of message still 512bits
	// {
	// 	//here it should 
	// 	a = a0;
	// 	b = b0;
	// 	c = c0;
	// 	d = d0;
	// 	i = 0;
	// 	while(i < 64)
	// 	{
	// 		if(i >= 0 && i < 16)
	// 		{
	// 			f = F_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		else if(i >= 16 && i < 32)
	// 		{
	// 			f = G_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		else if(i >= 32 && i < 48)
	// 		{
	// 			f = H_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		else if(i >= 48 && i < 64)
	// 		{
	// 			f = I_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		i++;
	// 		f = f + a + k[i] = m[g];
	// 		a = d;
	// 		d = c;
	// 		c = b;
	// 		b = b + R_LEFT(f, s[i]);
	// 	}
	// 	a0 = a0 + a;
	// 	b0 = b0 + b;
	// 	c0 = c0 + c;
	// 	d0 = d0 + d;
	// }


// unsigned int digest[16] = a0 append b0 append c0 append d0;

// return digest;

