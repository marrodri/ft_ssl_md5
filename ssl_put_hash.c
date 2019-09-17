/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_put_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:31:10 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/05 23:31:11 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		put_md5hash(uint8_t *md)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
	return ;
}

void		put256hash(uint8_t *md)
{
	int i;

	i = 0;
	while (i < 32)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
	return ;
}

void		put224hash(uint8_t *md)
{
	int i;

	i = 0;
	while (i < 28)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
	return ;
}

void		put1hash(t_hash *hash_v)
{
	int i;

	i = 0;
	while (i < 5)
	{
		ft_printf("%02x", hash_v->h0[i]);
		i++;
	}
	return ;
}
