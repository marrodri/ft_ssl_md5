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

void	put_md5hash(uint8_t *md)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
}

void	put256hash(uint8_t *md)
{
	int i;

	i = 0;
	while (i < 32)
	{
		ft_printf("%02x", md[i]);
		i++;
	}
}

void	put_hashmd(int input, char *algo, uint8_t *md)
{
	t_puthash *pr_hash[HS_SZ];
	pr_hash[0]= put_md5hash;
	pr_hash[1]= put256hash;

	pr_hash[input](md);
}
