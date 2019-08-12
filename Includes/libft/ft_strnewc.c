/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:36:51 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/27 14:36:56 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewc(char f, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(size);
	while (i < size)
	{
		str[i] = f;
		i++;
	}
	return (str);
}
