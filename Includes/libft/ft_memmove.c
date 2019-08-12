/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:11:46 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 19:14:42 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *dptr;
	char *sptr;

	dptr = (char *)dst;
	sptr = (char *)src;
	if (sptr < dptr)
	{
		dptr += n;
		sptr += n;
		while (n--)
			*--dptr = *--sptr;
	}
	else
		while (n--)
			*dptr++ = *sptr++;
	return (dst);
}
