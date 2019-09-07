/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bytes_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:14:56 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/06 12:14:59 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"


void	set_bytes_fd(const int fd, uint32_t bytes, t_list **list, t_hash **hash_v)
{
	uint32_t ret;
	uint8_t buff[bytes];
	uint32_t byte_len;
	uint64_t bit_len;
	uint8_t *tmp;
	uint8_t *extra;

	bit_len = 0;
	byte_len = 0;
	(*hash_v)->mssg = NULL;
	while((ret = read(fd, buff, bytes)) > 0)
	{
		byte_len = byte_len + ret;
		tmp = ft_memalloc(bytes);
		tmp = ft_memcpy(tmp, buff, bytes);
		if((*hash_v)->mssg)
			(*hash_v)->mssg = ft_strjoin((char*)tmp, (char *)buff);
		else
			(*hash_v)->mssg = ft_strdup((char*)buff);
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
		tmp = ft_memalloc(bytes);
		ft_bzero(tmp, bytes);
		tmp[0] = 0x80;
		bit_len = byte_len * 8;
		tmp = ft_append_bitlen(tmp, bytes, bit_len);
		add_new_chunk(list, tmp, bytes);
	}
	return ;
}
