/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:34:46 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/17 19:34:50 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_size(int n)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	while (i <= n)
	{
		size++;
		i = i * 16;
	}
	return (size);
}

char	set_hex(int *n, int size)
{
	int		ans;
	char	hex;
	int		power;
	char	*index;

	ans = 0;
	power = 0;
	index = "0123456789abcdef";
	power = (ft_power_of(16, size - 1));
	ans = *n / power;
	*n = *n - (ans * power);
	hex = index[ans];
	return (hex);
}

char	*ft_int_to_hex(int n)
{
	char	*hex;
	int		size;
	int		i;

	i = 0;
	size = check_size(n);
	hex = (char*)malloc((size) * sizeof(char));
	hex[size] = '\0';
	while (size > 0)
	{
		hex[i] = set_hex(&n, size);
		i++;
		size--;
	}
	return (hex);
}
