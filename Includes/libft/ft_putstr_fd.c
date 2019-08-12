/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:12:34 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/12 22:13:51 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (void)(NULL);
	str = (char *)s;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
