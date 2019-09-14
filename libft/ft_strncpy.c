/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:04:58 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 19:24:52 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < n && dest[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n && src[i] == '\0' && dest[i] != '\0')
	{
		while (i < n)
		{
			dest[i] = '\0';
			++i;
		}
	}
	return (dest);
}
