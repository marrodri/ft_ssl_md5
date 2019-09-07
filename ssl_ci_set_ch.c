/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_ci_set_ch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:22:11 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/29 12:22:13 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	init_ci_flags(t_flag **flags)
{
	int i;

	i = 0;
	while (i < CI_SZ)
	{
		(*flags)->ci_flags[i] = 0;
		i++;
	}
}

int		ci_checker(char *input, int *j)
{
	int			i;
	const char	ci_flags[CI_SZ] = CI_COM;

	i = 0;
	while (i < CI_SZ)
	{
		if (ci_flags[i] == input[1])
		{
			*j = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ci_set(char **str, int lim, int *i, t_flag **flags)
{
	int j;
	int check;

	check = 1;
	j = 0;
	init_ci_flags(flags);
	while (str[*i][0] == '-' && check && (*i != lim))
	{
		if ((check = ci_checker(str[*i], &j)) == 1)
			(*flags)->ci_flags[j] = 1;
		if (str[*i][1] == 's')
		{
			*i += 1;
			break ;
		}
		*i += 1;
	}
	if ((*flags)->ci_flags[1])
		(*flags)->ci_flags[0] = 0;
	if (check)
		return (1);
	ft_printf("%s: illegal option -- %c\n", str[1], str[*i - 1][1]);
	ft_printf("usage: %s [-pqr] [-s string] [files ...]", str[1]);
	return (0);
}
