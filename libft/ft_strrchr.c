/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:44:01 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 19:45:44 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*src;

	i = 0;
	src = (char *)s;
	if (src[i] == '\0')
		return (NULL);
	while (src[i] != '\0')
		i++;
	while (src[i] != c && i > 0)
		i--;
	if (src[i] == c)
		return (&src[i]);
	else
		return (NULL);
}
