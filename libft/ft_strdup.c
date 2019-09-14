/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:37:07 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/20 22:23:17 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*n;
	int		i;
	int		j;
	int		size;

	size = ft_strlen(src);
	i = 0;
	j = 0;
	n = (char *)malloc((size + 1) * sizeof(char));
	while (src[i] != '\0')
	{
		if (n == NULL)
			return (NULL);
		n[j] = src[i];
		i++;
		j++;
	}
	n[i] = '\0';
	return (n);
}
