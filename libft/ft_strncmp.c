/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:23:52 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/20 22:23:40 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	c1;
	unsigned int	c2;
	size_t			coun;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	c1 = 0;
	c2 = 0;
	coun = 1;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && !(*str1 == '\0' && *str2 == '\0') && n > coun)
	{
		str1++;
		str2++;
		coun++;
	}
	if (*str1 != *str2)
	{
		c1 = *str1;
		c2 = *str2;
	}
	return (c1 - c2);
}
