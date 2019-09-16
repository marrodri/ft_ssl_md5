/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_hash_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:01:18 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/31 03:12:15 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

const t_table	data[] = {
	//name, function, bytes;
	{"md5", md5_hash, app_bitlen_md5, 64},
	{"sha256", sha256_hash, app_bitlen_sha256, 64},
	{"sha224", sha224_hash, app_bitlen_sha256, 64},
	{"sha1", sha1_hash, app_bitlen_sha256, 64},
};

int			hash_checker(char *str)
{
	int			i;
	const char	*hash_algo[HS_SZ] = HS_COM;

	i = 0;
	while (i < HS_SZ)
	{
		if (!strcmp(str, hash_algo[i]))
			return (i);
		i++;
	}
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
			Standard commands:\n\nMessage Digest commands:\nmd5\
			\nsha256\nsha224\nsha1\nCipher commands:\n", str);
	return (-1);
}

uint8_t		*hash_func(int input, t_list *list, t_hash *hash_v)
{
	t_hash_algo *hash_arr[HS_SZ];

	hash_arr[0] = md5_hash;
	hash_arr[1] = sha256_hash;
	hash_arr[2] = sha224_hash;
	hash_arr[3] = sha1_hash;
	return (hash_arr[input](list, hash_v));
}
