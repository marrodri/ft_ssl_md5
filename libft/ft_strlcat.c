/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:42:09 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 19:43:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t total;
	size_t original;

	original = size;
	total = ft_strlen(dest) + ft_strlen(src);
	while (*dest != '\0' && 0 < size)
	{
		dest++;
		size--;
	}
	if (size == 0)
		return (ft_strlen(src) + original);
	while (size > 1 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
	return (total);
}
