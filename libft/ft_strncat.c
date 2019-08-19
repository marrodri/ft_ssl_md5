/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:29:32 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 19:41:30 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t dst_i;
	size_t src_i;

	src_i = 0;
	dst_i = 0;
	if (src[0] == '\0')
		return (dest);
	while (dest[dst_i] != '\0')
		dst_i++;
	while (src_i < nb && src[src_i])
	{
		dest[dst_i] = src[src_i];
		src_i++;
		dst_i++;
	}
	dest[dst_i] = '\0';
	return (dest);
}
