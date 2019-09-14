/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_man_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:50:58 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/01 15:51:01 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zero_flag(char *fstr, t_flags *st_flags)
{
	int		dif;
	char	*zero;
	int		i;

	i = 0;
	dif = st_flags->fi_width - ft_strlen(fstr);
	if (dif > 0)
	{
		zero = ft_strnewc('0', dif);
		fstr = ft_strjoin(zero, fstr);
		while (fstr[i])
		{
			if (fstr[i] == '+' || fstr[i] == '-' || fstr[i] == ' ')
			{
				fstr = ft_swap_charstr(fstr, fstr[i], 0);
			}
			else if (fstr[i] == 'X' || fstr[i] == 'x')
			{
				fstr = ft_swap_charstr(fstr, fstr[i], 1);
			}
			i++;
		}
	}
	return (fstr);
}

char	*minus_flag(char *fstr, char f, t_flags *st_flags)
{
	int		dif;
	char	*end_space;
	int		len;

	if (fstr[0] == '\0' && f == 'c')
		len = 1;
	else
		len = ft_strlen(fstr);
	dif = st_flags->fi_width - len;
	if (dif > 0)
	{
		end_space = ft_strnewc(' ', dif);
		fstr = ft_strjoin(fstr, end_space);
	}
	return (fstr);
}

char	*default_field(char *fstr, char f, t_flags *st_flags)
{
	int		dif;
	char	*space;
	int		len;

	if (fstr[0] == '\0' && f == 'c')
		len = 1;
	else
		len = ft_strlen(fstr);
	dif = st_flags->fi_width - len;
	if (dif > 0)
	{
		space = ft_strnewc(' ', dif);
		fstr = ft_strjoin(space, fstr);
	}
	return (fstr);
}
