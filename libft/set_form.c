/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:32:36 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/17 20:32:59 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_form(char f)
{
	int			pos;
	const char	form[SPEC_FORM_SIZE] = SPEC_FORM;

	pos = 0;
	if (f == '%')
		return (1);
	if (f == 'i')
		return (3);
	while (f != form[pos] && pos < (SPEC_FORM_SIZE - 1))
		pos++;
	if (f == form[pos])
		return (pos);
	else
		return (-1);
}

char	*set_form(char f, va_list args, t_flags *st_flag)
{
	int				pos;
	t_char_form		*c_str[SPEC_FORM_SIZE];

	if (f == '%')
	{
		return ("%");
	}
	pos = check_form(f);
	c_str[0] = c_form;
	c_str[1] = s_form;
	c_str[2] = p_form;
	c_str[3] = d_form;
	c_str[4] = o_form;
	c_str[5] = u_form;
	c_str[6] = x_form;
	c_str[7] = uppx_form;
	c_str[8] = f_form;
	if (pos != -1)
		return (c_str[pos](args, st_flag));
	else
		return (NULL);
}
