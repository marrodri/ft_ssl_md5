/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:21:30 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/22 16:21:33 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"
#include <stdio.h>

int check_last8bytes(uint8_t *chunk, int bytes)
{
	int i;
	int dif;

	i = bytes - 1;
	dif = bytes - 8;
	while (i >= dif)
	{
		if (chunk[i] != 0x00)
			return (0);
		i--;
	}
	return (1);
}

uint64_t byte_length(uint64_t val)
{
	int i;

	i = 0;
	while(val)
	{
		val = val >> 8;
		i++;
	}
	return (i);
}

uint8_t *ft_append_bitlen(uint8_t *chunk, int bytes, uint64_t bit_len)
{
	int i;
	uint64_t push;
	uint64_t tmp;
	uint64_t lim;
	lim = byte_length(bit_len);
	i = (bytes - 8) + lim;
	push = (lim) * 8;
	while (i >= 56)
	{
		tmp = bit_len;
		tmp = bit_len >> push;
		chunk[i] = 0x00 | tmp;
		i--;
		push -= 8;
	}
	return (chunk);
}

uint8_t		*ft_append_bytes(uint8_t *chunk, int ret, int bytes)
{
	int i;
	int dif;

	i = ret + 1;
	dif = bytes - 8;
	chunk[ret] = (chunk[ret] << 8) | 0x80;
	while (i < bytes)
	{
		chunk[i] = (chunk[i] << 8) | 0x00;
		i++;
	}
	return (chunk);
}

t_list	*set_new_node(uint8_t *chunk, int bytes)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return NULL;
	if (chunk)
	{
		new->content = chunk;
		new->content_size = bytes;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return new;
}

void	add_new_chunk(t_list **list, uint8_t *chunk, int bytes)
{
	t_list *new_chunk;

	new_chunk = set_new_node(chunk, bytes);
	if (*list == NULL)
		*list = new_chunk;
	else
		ft_lstaddend(list, new_chunk);
}

void	set_bytes_fd(const int fd, uint32_t bytes, t_list **list, t_hash **hash_v)
{
	uint32_t ret; //32bit as 4byte
	uint8_t buff[bytes]; //8bit as 1 byte
	uint32_t byte_len; //int
	uint64_t bit_len; //unsigned long long
	int chunk;
	uint8_t *tmp;
	uint8_t *extra;

	bit_len = 0;
	chunk = 0;
	byte_len = 0;
	(*hash_v)->mssg = NULL;
	while((ret = read(fd, buff, bytes)) > 0)
	{
		byte_len = byte_len + ret;
		tmp = ft_memalloc(bytes);
		tmp = ft_memcpy(tmp, buff, bytes);

		if((*hash_v)->mssg)
		{
			(*hash_v)->mssg = ft_strjoin((char*)tmp, (char *)buff);
		}
		else
		{
			(*hash_v)->mssg = ft_strdup((char*)buff);
		}
		
		if (ret < bytes)
		{
			bit_len = byte_len * 8;
			tmp = ft_append_bytes(tmp, ret, bytes);
			if(!check_last8bytes(tmp, bytes))
			{
				add_new_chunk(list, tmp, bytes);
				extra = ft_memalloc(bytes);
				ft_bzero(extra, bytes);
				extra = ft_append_bitlen(extra, bytes, bit_len);
				add_new_chunk(list, extra, bytes);
				return ;
			}
			else
				tmp = ft_append_bitlen(tmp, bytes, bit_len);
		}
		add_new_chunk(list, tmp, bytes);
	}
	if(byte_len % bytes == 0)
	{
		// ft_printf("we got congruent %d, setting new node to append", bytes);
		tmp = ft_memalloc(bytes);
		ft_bzero(tmp, bytes);
		tmp[0] = 0x80;
		bit_len = byte_len * 8;
		tmp = ft_append_bitlen(tmp, bytes, bit_len);
		add_new_chunk(list, tmp, bytes);
	}
	return ;
}




// 2:05 sun
// 4:36 mon
// _____
// 6:41
// 3:05 tues
// ---------
// 9:46
// 6:09 wed
// ____
// 15:55
//	5:19 thurs
//______
// 21:14