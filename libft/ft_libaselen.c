/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libaselen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:40:00 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/15 11:40:04 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_libaselen(long long int n, int base, int f_flag)
{
	long long int	size;

	size = 0;
	if ((n < 0) && (base == 10) && f_flag == 0)
	{
		size++;
		n = n * -1;
	}
	else if (n < 0 && f_flag == 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}
