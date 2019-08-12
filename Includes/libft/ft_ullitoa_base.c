/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:32:44 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/03 17:32:47 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_size_base(unsigned long long int n, int base)
{
	unsigned long long int	size;

	size = 0;
	while (n > 0)
	{
		n = n / base;
		size++;
	}
	return (size - 1);
}

char			*ft_ullitoa_base(unsigned long long int value, int base)
{
	char					*str;
	char					*b_val;
	int						size;
	int						i;
	unsigned long long int	rem;

	b_val = "0123456789abcdef";
	i = 0;
	if (value == 0)
	{
		return (ft_strdup("0"));
	}
	size = check_size_base(value, base);
	if ((str = (char*)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[size + 1] = '\0';
	while (size >= i)
	{
		rem = value % base;
		str[size] = b_val[rem];
		value = value / base;
		size--;
	}
	return (str);
}
