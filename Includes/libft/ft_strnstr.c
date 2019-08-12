/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:10:04 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 20:37:48 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_null(char *s, char *needle, int i)
{
	if (s[i] == needle[i] && (s[i + 1] == '\0' && needle[i + 1] == '\0'))
		return (1);
	if (needle[0] == '\0')
		return (1);
	else
		return (0);
}

static char	*ft_str_n_str(char *str, char *to_find, size_t i, size_t n)
{
	size_t index;
	size_t temp;

	while (str[i] != '\0' && i != n)
	{
		index = 0;
		if (str[i] == to_find[index])
		{
			temp = i;
			while (str[i] == to_find[index] && i <= n && to_find[index] != '\0')
			{
				index++;
				i++;
			}
			if (to_find[index] == '\0')
				return (&str[temp]);
			i = temp;
		}
		i++;
	}
	return (0);
}

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	if (!*str)
		return (NULL);
	if (ft_check_null((char *)str, (char *)to_find, i) == 1)
		return ((char *)str);
	return (ft_str_n_str((char *)str, (char *)to_find, i, n));
}
