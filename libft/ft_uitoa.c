/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:30:41 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/18 16:30:43 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_uitoa(unsigned int n)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_check_size(n);
	str = (char*)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[--size] = '\0';
	while (size >= i)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}
