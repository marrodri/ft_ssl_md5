/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldeduct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:46:01 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/15 11:46:04 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_llideduct(long long int num)
{
	long long int tmp;

	tmp = num;
	if (num > 10)
	{
		while (tmp > 10)
			tmp = tmp % 10;
	}
	if (tmp >= 5)
	{
		tmp = 10 - tmp;
		num = num + tmp;
	}
	return (num);
}
