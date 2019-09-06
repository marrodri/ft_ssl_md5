/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bytes_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:14:37 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/06 12:14:40 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	set_bytes_str(char *str, uint32_t bytes, t_list **list)
{
	int i;
	uint8_t *tmp;
	uint8_t chunk[bytes];
	uint32_t byte_len;
	uint64_t bit_len;

	i = 0;
	byte_len = 0;
	// ft_printf("str is |%s|\n", str);
	while (str[byte_len])
	{
		if (i % bytes == 0 && i != 0)
		{
			// ft_printf("!!!!! we got 64 bytes, setting chunk !!!!!!\n");
			i = 0;
			tmp = ft_memalloc(bytes);
			tmp = ft_memcpy(tmp, chunk, bytes);
			ft_bzero(chunk, bytes);
			add_new_chunk(list, tmp, bytes);
			// ft_printf("chunk is |%s|\n", tmp);
		}
		chunk[i] = str[byte_len];
		byte_len++;
		i++;
	}
	bit_len = byte_len * 8;
	// ft_printf("byte len is |%d| bit len|%lld|\n hex bit_len|%02x|\n", byte_len, bit_len, bit_len);
	tmp = ft_memalloc(bytes);
	tmp = ft_memcpy((char*)tmp, (char*)chunk, bytes);
	// ft_printf("tmp is |%s|\n", tmp); //
	// ft_printf("chunk is |%s| and i is |%d|\n", chunk, i); //
	tmp = ft_append_bytes(tmp, i, bytes);
	// for(int j = 0; j < 64; j++)
	// {
	// 	ft_printf("tmp[%d] is |%02x| c|%c|\n", j, tmp[j], tmp[j]);
	// }

	// ft_printf("i %d\n", i);
	if (i % bytes == 0)
	{
		// ft_printf("chunk is 64 bytes, setting new chunk\n");
		add_new_chunk(list, tmp, bytes);
		tmp = ft_memalloc(bytes);
		tmp = ft_append_bytes(tmp, 0, bytes);
		tmp = ft_append_bitlen(tmp, bytes, bit_len);
		add_new_chunk(list, tmp, bytes);
	}
	else
	{	
		if(!check_last8bytes(tmp, bytes))
		{
			// ft_printf("++++last 8 bytes are not empty, setting new chunk++++\n"); //
			add_new_chunk(list, tmp, bytes);
			tmp = ft_memalloc(bytes);
			ft_bzero(tmp, bytes);
			tmp = ft_append_bitlen(tmp, bytes, bit_len);
			// for(int j = 0; j < 64; j++)
			// {
			// 	ft_printf("tmp[%d] is |%02x| c|%c|\n", j, tmp[j], tmp[j]); //
			// }
			add_new_chunk(list, tmp, bytes);
			return ;
		}
		else
		{
			tmp = ft_append_bitlen(tmp, bytes, bit_len);
			add_new_chunk(list, tmp, bytes);
		}
	}
	return ;
}