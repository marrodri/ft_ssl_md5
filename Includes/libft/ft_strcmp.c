/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:50:59 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/20 22:34:55 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	c1;
	unsigned int	c2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	c1 = 0;
	c2 = 0;
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
	{
		c1 = *str1;
		c2 = *str2;
	}
	return (c1 - c2);
}
