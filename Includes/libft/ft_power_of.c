/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:33:52 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/17 19:34:00 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power_of(int n, int expo)
{
	int i;
	int power;

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
