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

uint8_t 	*hash_func(int input, t_list *list, t_hash *hash_v)
{
	t_hash_algo *hash_arr[HS_SZ];
	hash_arr[0] = md5_hash;
	hash_arr[1] = sha256_algo;
	
	return(hash_arr[input](list, hash_v));
}
