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

void	append_last_chunk_str(t_lstcon **lstv, t_list **list, uint32_t bytes)
{
	add_new_chunk(list, (*lstv)->tmp, bytes);
	(*lstv)->tmp = ft_memalloc(bytes);
	ft_bzero((*lstv)->tmp, bytes);
	(*lstv)->tmp = ft_append_bitlen((*lstv)->tmp, bytes, (*lstv)->bit_len);
	add_new_chunk(list, (*lstv)->tmp, bytes);
}

void	append_1bit_chunk_str(t_lstcon **lstv, t_list **list, uint32_t bytes)
{
	add_new_chunk(list, (*lstv)->tmp, bytes);
	(*lstv)->tmp = ft_memalloc(bytes);
	(*lstv)->tmp = ft_append_bytes((*lstv)->tmp, 0, bytes);
	(*lstv)->tmp = ft_append_bitlen((*lstv)->tmp, bytes, (*lstv)->bit_len);
	add_new_chunk(list, (*lstv)->tmp, bytes);
}

void	set_buff_str(t_lstcon **lstv, uint32_t bytes, int i)
{
	(*lstv)->bit_len = (*lstv)->byte_len * 8;
	(*lstv)->tmp = ft_memalloc(bytes);
	(*lstv)->tmp = ft_memcpy((char*)(*lstv)->tmp, (char*)(*lstv)->buff, bytes);
	(*lstv)->tmp = ft_append_bytes((*lstv)->tmp, i, bytes);
}

void	set_new_chunk_str(t_lstcon **lstv, t_list **list, uint32_t bytes)
{
	(*lstv)->tmp = ft_memalloc(bytes);
	(*lstv)->tmp = ft_memcpy((*lstv)->tmp, (*lstv)->buff, bytes);
	ft_bzero((*lstv)->buff, bytes);
	add_new_chunk(list, (*lstv)->tmp, bytes);
}


void	set_bytes_str(char *str, uint32_t bytes, t_list **list)
{
	int i;
	t_lstcon *lstv;

	// uint8_t *tmp;
	// uint8_t chunk[bytes];
	// uint32_t byte_len;
	// uint64_t bit_len;
	// byte_len = 0;

	init_varlst(&lstv, bytes);
	i = 0;
	while (str[lstv->byte_len])
	{
		if (i % bytes == 0 && i != 0)
		{
			i = 0;
			set_new_chunk_str(&lstv, list, bytes);
			// lstv->tmp = ft_memalloc(bytes);
			// lstv->tmp = ft_memcpy(lstv->tmp, lstv->buff, bytes);
			// ft_bzero(lstv->buff, bytes);
			// add_new_chunk(list, lstv->tmp, bytes);
		}
		lstv->buff[i] = str[lstv->byte_len];
		lstv->byte_len++;
		i++;
	}
	set_buff_str(&lstv, bytes, i);
	// lstv->bit_len = lstv->byte_len * 8;
	// lstv->tmp = ft_memalloc(bytes);
	// lstv->tmp = ft_memcpy((char*)lstv->tmp, (char*)lstv->buff, bytes);
	// lstv->tmp = ft_append_bytes(lstv->tmp, i, bytes);
	if (i % bytes == 0)
	{
		append_1bit_chunk_str(&lstv, list, bytes);
		// add_new_chunk(list, lstv->tmp, bytes);
		// lstv->tmp = ft_memalloc(bytes);
		// lstv->tmp = ft_append_bytes(lstv->tmp, 0, bytes);
		// lstv->tmp = ft_append_bitlen(lstv->tmp, bytes, lstv->bit_len);
		// add_new_chunk(list, lstv->tmp, bytes);
	}
	else
	{	
		if(!check_last8bytes(lstv->tmp, bytes))
		{
			append_last_chunk_str(&lstv, list, bytes);
			// add_new_chunk(list, lstv->tmp, bytes);
			// lstv->tmp = ft_memalloc(bytes);
			// ft_bzero(lstv->tmp, bytes);
			// lstv->tmp = ft_append_bitlen(lstv->tmp, bytes, lstv->bit_len);
			// add_new_chunk(list, lstv->tmp, bytes);
			free(lstv);
			return ;
		}
		else
		{
			lstv->tmp = ft_append_bitlen(lstv->tmp, bytes, lstv->bit_len);
			add_new_chunk(list, lstv->tmp, bytes);
		}
	}
	free(lstv);
}