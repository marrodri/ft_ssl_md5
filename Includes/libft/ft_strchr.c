/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:58:24 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/08 20:59:42 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*src;

	i = 0;
	src = (char *)str;
	while (c != src[i] && src[i] != '\0')
		i++;
	if (src[i] == c)
		return (&src[i]);
	else
		return (NULL);
}
