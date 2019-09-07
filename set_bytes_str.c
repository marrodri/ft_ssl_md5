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
	while (str[byte_len])
	{
		if (i % bytes == 0 && i != 0)
		{
			i = 0;
			tmp = ft_memalloc(bytes);
			tmp = ft_memcpy(tmp, chunk, bytes);
			ft_bzero(chunk, bytes);
			add_new_chunk(list, tmp, bytes);
		}
		chunk[i] = str[byte_len];
		byte_len++;
		i++;
	}
	bit_len = byte_len * 8;
	tmp = ft_memalloc(bytes);
	tmp = ft_memcpy((char*)tmp, (char*)chunk, bytes);
	tmp = ft_append_bytes(tmp, i, bytes);
	if (i % bytes == 0)
	{
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
			add_new_chunk(list, tmp, bytes);
			tmp = ft_memalloc(bytes);
			ft_bzero(tmp, bytes);
			tmp = ft_append_bitlen(tmp, bytes, bit_len);
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