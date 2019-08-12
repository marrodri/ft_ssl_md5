/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_charstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:12:51 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/01 16:12:57 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_swap_charstr(char *fstr, char c, int pos)
{
	int		i;
	char	tmp;

	i = 0;
	while (fstr[i])
	{
		if (fstr[i] == c)
		{
			tmp = fstr[pos];
			fstr[pos] = fstr[i];
			fstr[i] = tmp;
			return (fstr);
		}
		i++;
	}
	return (fstr);
}
