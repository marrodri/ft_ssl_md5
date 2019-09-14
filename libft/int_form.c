/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:39:20 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/23 15:39:23 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*d_form(va_list args, t_flags *st_flag)
{
	char			*num;
	long long int	n;

	if (st_flag->fo_flag[0] == 1)
		n = (short int)va_arg(args, int);
	else if (st_flag->fo_flag[0] == 2)
		n = (signed char)va_arg(args, int);
	else if (st_flag->fo_flag[1] == 1)
		n = va_arg(args, long int);
	else if (st_flag->fo_flag[1] == 2)
		n = va_arg(args, long long int);
	else
		n = va_arg(args, int);
	num = ft_llitoa_base(n, 10);
	if (n == 0 && st_flag->prec == 0 && st_flag->prec_flag == 1)
		return ("");
	return (num);
}

char	*x_form(va_list args, t_flags *st_flag)
{
	char					*hex;
	unsigned long long int	n;

	if (st_flag->fo_flag[0] == 1)
		n = (unsigned short int)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[0] == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[1] == 1)
		n = va_arg(args, unsigned long int);
	else if (st_flag->fo_flag[1] == 2)
		n = va_arg(args, unsigned long long int);
	else
		n = va_arg(args, unsigned int);
	if (n == 0 && st_flag->prec == 0 && st_flag->prec_flag == 1)
		return ("");
	hex = ft_llitoa_base(n, 16);
	return (hex);
}

char	*uppx_form(va_list args, t_flags *st_flag)
{
	char					*hex;
	unsigned long long int	n;

	if (st_flag->fo_flag[0] == 1)
		n = (unsigned short int)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[0] == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[1] == 1)
		n = va_arg(args, unsigned long int);
	else if (st_flag->fo_flag[1] == 2)
		n = va_arg(args, unsigned long long int);
	else
		n = va_arg(args, unsigned int);
	hex = ft_ullitoa_base(n, 16);
	if (n == 0 && st_flag->prec == 0 && st_flag->prec_flag == 1)
		return ("");
	hex = ft_strupper(hex);
	return (hex);
}

char	*o_form(va_list args, t_flags *st_flag)
{
	char					*oct;
	unsigned long long int	n;

	if (st_flag->fo_flag[0] == 1)
		n = (unsigned short int)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[0] == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[1] == 1)
		n = va_arg(args, unsigned long int);
	else if (st_flag->fo_flag[1] == 2)
		n = va_arg(args, unsigned long long int);
	else
		n = va_arg(args, unsigned int);
	oct = ft_ullitoa_base(n, 8);
	if (n == 0 && st_flag->prec == 0 && st_flag->prec_flag == 1)
		return ("");
	return (oct);
}

char	*u_form(va_list args, t_flags *st_flag)
{
	char					*u_num;
	unsigned long long int	n;

	if (st_flag->fo_flag[0] == 1)
		n = (unsigned short int)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[0] == 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (st_flag->fo_flag[1] == 1)
		n = va_arg(args, unsigned long int);
	else if (st_flag->fo_flag[1] == 2)
		n = va_arg(args, unsigned long long int);
	else
		n = va_arg(args, unsigned int);
	u_num = ft_ullitoa_base(n, 10);
	if (n == 0 && st_flag->prec == 0 && st_flag->prec_flag == 1)
		return ("");
	return (u_num);
}
