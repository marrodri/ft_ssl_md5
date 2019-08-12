/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of_lli.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:51:25 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/15 11:51:30 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_power_of_lli(long long int n, long long int expo)
{
	long long int i;
	long long int power;

	i = 1;
	power = n;
	if (expo <= 0)
		return (1);
	else if (expo == 1)
		return (n);
	while (i < expo)
	{
		power = power * n;
		i++;
	}
	return (power);
}
