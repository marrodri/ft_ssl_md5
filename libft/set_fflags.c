/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:32:38 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/22 15:32:42 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *st_flag)
{
	int i;

	i = 0;
	while (i < FI_FLAG_SIZE)
	{
		st_flag->fi_flag[i] = 0;
		i++;
	}
	i = 0;
	while (i < FO_FLAG_SIZE)
	{
		st_flag->fo_flag[i] = 0;
		i++;
	}
	st_flag->fi_width = 0;
	st_flag->prec = 0;
	st_flag->prec_flag = 0;
	return ;
}

void	ignore_case(t_flags *st_flag)
{
	if (st_flag->fi_flag[2] == 1)
		st_flag->fi_flag[1] = 0;
	if (st_flag->fi_flag[3] == 1)
		st_flag->fi_flag[4] = 0;
	return ;
}

void	set_fflags(char *str, int *i, t_flags **st_flag)
{
	int	pos;

	pos = 0;
	init_flags(*st_flag);
	while ((check_form(str[*i])) == -1 && (!(str[*i] == 'l' ||
		str[*i] == 'h' || str[*i] == 'L' || str[*i] == '.')) &&
			(!(str[*i] >= '1' && str[*i] <= '9')))
	{
		check_fi_flags(str[*i], *st_flag);
		*i += 1;
	}
	check_field(str, i, *st_flag);
	check_prec(str, i, *st_flag);
	while ((check_form(str[*i])) == -1)
	{
		check_fo_flags(str[*i], *st_flag);
		*i += 1;
	}
	return ;
}
