/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:54:23 by marrodri          #+#    #+#             */
/*   Updated: 2019/01/02 12:42:57 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = (ft_strlen(s1)) + (ft_strlen(s2));
	if ((str = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[size] = '\0';
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && i < size)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
