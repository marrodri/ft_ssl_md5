/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:02 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/17 19:31:05 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dec_to_oct(int n)
{
	int oct;
	int dec;
	int i;
	int tmp;

	n = (long int)n;
	oct = 0;
	dec = 0;
	tmp = 0;
	i = 0;
	while (n > 0)
	{
		dec = n / 8;
		tmp = n % 8;
		oct = oct + (tmp * (ft_power_of(10, i)));
		i++;
		n = dec;
	}
	return (oct);
}
