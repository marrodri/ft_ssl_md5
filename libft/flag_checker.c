/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:00:29 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/15 15:00:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_fi_flags(char f, t_flags *st_flag)
{
	int			pos;
	const char	fi_flags[FI_FLAG_SIZE] = FI_FLAG;

	pos = 0;
	while (pos < FI_FLAG_SIZE)
	{
		if (fi_flags[pos] == f)
			st_flag->fi_flag[pos] = 1;
		pos++;
	}
	ignore_case(st_flag);
	return ;
}

void	check_field(char *str, int *i, t_flags *st_flag)
{
	if (str[*i] >= '1' && str[*i] <= '9')
	{
		st_flag->fi_width = ft_atoi(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			*i += 1;
	}
	return ;
}

void	check_prec(char *str, int *i, t_flags *st_flag)
{
	if (str[*i] == '.')
	{
		st_flag->prec_flag = 1;
		st_flag->prec = 0;
		*i += 1;
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			st_flag->prec = ft_atoi(&str[*i]);
			while (str[*i] >= '0' && str[*i] <= '9')
				*i += 1;
		}
	}
}

void	check_fo_flags(char f, t_flags *st_flag)
{
	int			pos;
	const char	fo_flags[FO_FLAG_SIZE] = FO_FLAG;

	pos = 0;
	while (pos < FO_FLAG_SIZE)
	{
		if (fo_flags[pos] == f)
		{
			st_flag->fo_flag[pos] += 1;
		}
		pos++;
	}
	return ;
}
