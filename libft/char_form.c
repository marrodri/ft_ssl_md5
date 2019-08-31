/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:39:40 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/23 15:39:44 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_form(va_list args, t_flags *st_flag)
{
	static char c[1];

	st_flag->fo_flag[0] = 0;
	st_flag->fo_flag[1] = 0;
	c[0] = (char)va_arg(args, int);
	return (c);
}

char	*s_form(va_list args, t_flags *st_flag)
{
	char *s;

	st_flag->fo_flag[0] = 0;
	st_flag->fo_flag[1] = 0;
	if ((s = va_arg(args, char *)) == NULL)
	{
		return ("(null)");
	}
	return (s);
}

char	*p_form(va_list args, t_flags *st_flag)
{
	void	*p;
	char	*s;

	st_flag->fo_flag[0] = 0;
	st_flag->fo_flag[1] = 0;
	p = va_arg(args, void *);
	s = ft_llitoa_base((long long int)p, 16);
	s = ft_strjoin("0x", s);
	return (s);
}
