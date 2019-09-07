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

void	append_last_chunk(t_list **list, uint8_t *tmp, uint32_t bytes, uint32_t byte_len)
{
	uint64_t bit_len;

	tmp = ft_memalloc(bytes);
	ft_bzero(tmp, bytes);
	tmp[0] = 0x80;
	bit_len = byte_len * 8;
	tmp = ft_append_bitlen(tmp, bytes, bit_len);
	add_new_chunk(list, tmp, bytes);
}

void	append_new_chunk(t_list **list, uint8_t *tmp, uint32_t bytes, uint64_t bit_len)
{
	add_new_chunk(list, tmp, bytes);
	tmp = ft_memalloc(bytes);
	ft_bzero(tmp, bytes);
	tmp = ft_append_bitlen(tmp, bytes, bit_len);
	add_new_chunk(list, tmp, bytes);
}

void	set_mssg(t_hash **hash_v, char *tmp, char *buff)
{
	if ((*hash_v)->mssg)
		(*hash_v)->mssg = ft_strjoin(tmp, buff);
	else
		(*hash_v)->mssg = ft_strdup(buff);
}

void	set_bytes_fd(const int fd, uint32_t bytes, t_list **list, t_hash **hash_v)
{
	uint32_t	ret;
	t_lstcon 	*lst_v;
	// uint8_t		buff[bytes];
	// uint32_t	byte_len;
	// uint64_t	bit_len;
	// uint8_t		*tmp;

	lst_v = malloc(sizeof(t_lstcon));
	lst_v->bit_len = 0;
	lst_v->byte_len = 0;
	lst_v->buff = ft_memalloc(bytes);
	ft_bzero(lst_v->buff, bytes);
	(*hash_v)->mssg = NULL;
	while ((ret = read(fd, lst_v->buff, bytes)) > 0)
	{
		lst_v->byte_len = lst_v->byte_len + ret;
		lst_v->tmp = ft_memalloc(bytes);
		set_mssg(hash_v, (char*)lst_v->tmp, (char*)lst_v->buff);
		lst_v->tmp = ft_memcpy(lst_v->tmp, lst_v->buff, bytes);
		// ft_printf("!!!!!!!!!here seg\n");
		if (ret < bytes)
		{
			lst_v->bit_len = lst_v->byte_len * 8;
			lst_v->tmp = ft_append_bytes(lst_v->tmp, ret, bytes);
			if (!check_last8bytes(lst_v->tmp, bytes))
			{
				append_new_chunk(list, lst_v->tmp, bytes, lst_v->bit_len);
				free(lst_v);
				return ;
			}
			else
				lst_v->tmp = ft_append_bitlen(lst_v->tmp, bytes, lst_v->bit_len);
		}
		add_new_chunk(list, lst_v->tmp, bytes);
	}
	if (lst_v->byte_len % bytes == 0)
		append_last_chunk(list, lst_v->tmp, bytes, lst_v->byte_len);
	free(lst_v);
	return ;
}
