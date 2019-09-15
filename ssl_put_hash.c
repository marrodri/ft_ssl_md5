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

int		*put_md5hash(uint8_t *md)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
	return (0);
}

int		*put256hash(uint8_t *md)
{
	int i;

	i = 0;
	while (i < 32)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
	return (0);
}

int		*put224hash(uint8_t *md)
{
	int i;

	i = 0;
	while(i < 28)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
	return 0;
}

int		*put1hash(uint8_t *md)
{
	int i;

	i = 0;
	while(i < 20)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
	return 0;
}

void	put_hashmd(int input, uint8_t *md)
{
	t_puthash	*pr_hash[HS_SZ];
	int			*i;

	i = NULL;
	pr_hash[0] = put_md5hash;
	pr_hash[1] = put256hash;
	pr_hash[2] = put224hash;
	pr_hash[3] = put1hash;
	i = pr_hash[input](md);
}
