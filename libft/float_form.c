/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:27:03 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/10 16:27:05 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_form(va_list args, t_flags *st_flag)
{
	char		*f_n;
	long double	n;

	if (st_flag->prec_flag == 0)
		st_flag->prec = 6;
	if (st_flag->fo_flag[1] == 1)
		n = va_arg(args, double);
	else if (st_flag->fo_flag[2] == 1)
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	f_n = ft_ldtoa(n, st_flag->prec);
	return (f_n);
}
