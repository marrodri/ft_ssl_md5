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

void	append_last_chunk_fd(t_list **list, uint8_t *tmp,
	uint32_t bytes, uint32_t byte_len)
{
	uint64_t bit_len;

	tmp = ft_memalloc(bytes);
	ft_bzero(tmp, bytes);
	tmp[0] = 0x80;
	bit_len = byte_len * 8;
	tmp = ft_append_bitlen(tmp, bytes, bit_len);
	add_new_chunk(list, tmp, bytes);
}

void	append_new_chunk_fd(t_list **list, uint8_t *tmp,
	uint32_t bytes, uint64_t bit_len)
{
	add_new_chunk(list, tmp, bytes);
	tmp = ft_memalloc(bytes);
	ft_bzero(tmp, bytes);
	tmp = ft_append_bitlen(tmp, bytes, bit_len);
	add_new_chunk(list, tmp, bytes);
}

void	set_mssg_fd(t_hash **hash_v, char *tmp, char *buff)
{
	if ((*hash_v)->mssg)
		(*hash_v)->mssg = ft_strjoin(tmp, buff);
	else
		(*hash_v)->mssg = ft_strdup(buff);
}

void	set_buff_fd(t_lstcon **lstv, t_hash **hash_v,
	uint32_t bytes, uint32_t ret)
{
	(*lstv)->byte_len = (*lstv)->byte_len + ret;
	(*lstv)->tmp = ft_memalloc(bytes);
	set_mssg_fd(hash_v, (char*)((*lstv)->tmp), (char*)((*lstv)->buff));
	(*lstv)->tmp = ft_memcpy((*lstv)->tmp, (*lstv)->buff, bytes);
}

void	set_bytes_fd(const int fd, uint32_t bytes,
	t_list **list, t_hash **hash_v)
{
	uint32_t	ret;
	t_lstcon	*lstv;

	init_var_fd(&lstv, hash_v, bytes);
	while ((ret = read(fd, lstv->buff, bytes)) > 0)
	{
		set_buff_fd(&lstv, hash_v, bytes, ret);
		if (ret < bytes)
		{
			lstv->bit_len = lstv->byte_len * 8;
			lstv->tmp = ft_append_bytes(lstv->tmp, ret, bytes);
			if (!check_last8bytes(lstv->tmp, bytes))
			{
				append_new_chunk_fd(list, lstv->tmp, bytes, lstv->bit_len);
				free(lstv);
				return ;
			}
			else
				lstv->tmp = ft_append_bitlen(lstv->tmp, bytes, lstv->bit_len);
		}
		add_new_chunk(list, lstv->tmp, bytes);
	}
	if (lstv->byte_len % bytes == 0)
		append_last_chunk_fd(list, lstv->tmp, bytes, lstv->byte_len);
	free(lstv);
}
