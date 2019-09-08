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

void	append_last_chunk_fd(t_app *app, t_list **list, t_lstcon **lstv)
{
	uint64_t bit_len;

	(*lstv)->tmp = ft_memalloc(app->bytes);
	ft_bzero((*lstv)->tmp, app->bytes);
	(*lstv)->tmp[0] = 0x80;
	bit_len = (*lstv)->byte_len * 8;
	(*lstv)->tmp = bitlen_tb(app->input, (*lstv)->tmp, app->bytes, bit_len);
	add_new_chunk(list, (*lstv)->tmp, app->bytes);
}

void	append_new_chunk_fd(t_app *app, t_list **list, t_lstcon **lstv)
{
	add_new_chunk(list, (*lstv)->tmp, app->bytes);
	(*lstv)->tmp = ft_memalloc(app->bytes);
	ft_bzero((*lstv)->tmp, app->bytes);
	(*lstv)->tmp = bitlen_tb(app->input, (*lstv)->tmp, app->bytes, (*lstv)->bit_len);
	add_new_chunk(list, (*lstv)->tmp, app->bytes);
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

void	set_bytes_fd(t_app *app, t_list **list, t_hash **hash_v)
{
	uint32_t	ret;
	t_lstcon	*lstv;

	init_varlst(&lstv, app->bytes);
	while ((ret = read(app->fd, lstv->buff, app->bytes)) > 0)
	{
		set_buff_fd(&lstv, hash_v, app->bytes, ret);
		if (ret < (uint32_t)app->bytes)
		{
			lstv->bit_len = lstv->byte_len * 8;
			lstv->tmp = ft_append_bytes(lstv->tmp, ret, app->bytes);
			if (!check_last8bytes(lstv->tmp, app->bytes))
			{
				append_new_chunk_fd(app, list, &lstv);
				free(lstv);
				return ;
			}
			else
				lstv->tmp = bitlen_tb(app->input,lstv->tmp, app->bytes, lstv->bit_len);
		}
		add_new_chunk(list, lstv->tmp, app->bytes);
	}
	if (lstv->byte_len % app->bytes == 0)
		append_last_chunk_fd(app, list, &lstv);
	free(lstv);
}
