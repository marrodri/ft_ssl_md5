/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:51:13 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/01 15:51:16 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hash_flag(char *str, char f, t_flags *st_flags)
{
	if (f == 'o')
	{
		if (str[0] != '0')
			str = ft_strjoin("0", str);
	}
	else if (f == 'x')
	{
		if (str[0] != '\0')
			if ((ft_strischar(str, '0')) == 0)
				str = ft_strjoin("0x", str);
	}
	else if (f == 'X')
	{
		if (str[0] != '\0')
			if ((ft_strischar(str, '0')) == 0)
				str = ft_strjoin("0X", str);
	}
	else if (f == 'f')
	{
		if (st_flags->prec == 0)
			str = ft_strjoin(str, ".");
	}
	return (str);
}

char	*plus_flag(char *fstr, char f)
{
	if ((f == 'd' || f == 'i' || f == 'f') && fstr[0] != '-')
		fstr = ft_strjoin("+", fstr);
	return (fstr);
}

char	*space_flag(char *fstr, char f)
{
	if ((f == 'd' || f == 'i' || f == 'f') && fstr[0] != '-')
		fstr = ft_strjoin(" ", fstr);
	return (fstr);
}
