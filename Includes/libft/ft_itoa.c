/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:01:03 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/13 20:24:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_libaselen(n, 10, 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char*)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	while (size >= i)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (ft_strdup(str));
}
