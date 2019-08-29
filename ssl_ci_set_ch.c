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

	i= 0;
	while(i < CI_SZ)
	{
		(*flags)->ci_flags[i] = 0;
		i++;
	}
}

int		ci_checker(char *input)
{
	int i;
	const char ci_flags[CI_SZ] = CI_COM;
	i = 0;

	while(i < CI_SZ)
	{
		if(ci_flags[i] == input[1])
			return 1;
		i++;
	}
	return 0;
}

int		ci_set(char **str, int lim ,int *i, t_flag **flags)
{
	// const char ci_flags[CI_SZ] = CI_COM;
	int j;
	int check;

	check = 1;
	init_ci_flags(flags);
	// if (lim == 2)
	// 	check = 1;
	while (str[*i][0] == '-' && check)
	{
		j = 0;
		while (j < CI_SZ)
		{
			if ((check = ci_checker(str[*i])) == 1)
			{
				(*flags)->ci_flags[j] = 1;
			}
			j++;
		}
		if (str[*i][1] == 's')
		{
			*i += 1;
			break;
		}
		*i += 1;
		if (*i >= lim)
			break;
	}
	if(check)
		return (1);
	else
	{
		printf("%s: illegal option -- %c\n",str[1] ,str[*i - 1][1]);
		printf("usage: %s [-pqr] [-s string] [files ...]", str[1]);
		return (0);
	}
}
