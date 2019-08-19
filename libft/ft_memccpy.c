/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:51:21 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/08 20:53:10 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;
	char	chr;

	i = 0;
	chr = (char)c;
	dest = (char *)dst;
	source = (char *)src;
	while (i < n && (i == 0 || source[i - 1] != chr))
	{
		dest[i] = source[i];
		i++;
	}
	if (i > 0 && chr == source[i - 1])
		return (dest + i);
	else
		return (NULL);
}
