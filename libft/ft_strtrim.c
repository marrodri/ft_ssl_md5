/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:10:36 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/13 14:10:05 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_space_beg(char const *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	return (i);
}

static int	ft_check_space_end(char const *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	str = (char *)malloc((size + 1) * sizeof(char*));
	if (str == NULL)
		return (NULL);
	i = ft_check_space_beg(s, i);
	while (i < size)
	{
		str[j++] = s[i++];
		if (ft_check_space_end(s, i) == 1)
			break ;
	}
	str[j] = '\0';
	return (ft_strdup(str));
}
