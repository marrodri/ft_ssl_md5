/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:08:49 by marrodri          #+#    #+#             */
/*   Updated: 2019/01/01 21:27:28 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (void)(NULL);
	str = (char *)s;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
