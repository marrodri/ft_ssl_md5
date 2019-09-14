/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:33:11 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/17 20:33:15 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FI_FLAG_SIZE 5
# define FO_FLAG_SIZE 3
# define SPEC_FORM_SIZE 9
# define FI_FLAG {'#','0','-','+',' '};
# define FO_FLAG {'h','l', 'L'};
# define SPEC_FORM {'c','s','p','d','o','u','x','X','f'};
# include "libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int		fo_flag[FO_FLAG_SIZE];
	int		fi_flag[FI_FLAG_SIZE];
	int		fi_width;
	int		prec;
	int		prec_flag;
}				t_flags;

typedef char	*t_char_form(va_list args, t_flags *st_flag);
int				ft_printf(char *str, ...);
void			set_fflags(char *str, int *i, t_flags **st_flag);
void			check_fi_flags(char f, t_flags *st_flag);
void			check_field(char *str, int *i, t_flags *st_flag);
void			check_prec(char *str, int *i, t_flags *st_flag);
void			check_fo_flags(char f, t_flags *st_flag);
void			ignore_case(t_flags *st_flag);
char			*set_form(char f, va_list args, t_flags *st_flag);
int				check_form(char f);
char			*c_form(va_list args, t_flags *st_flag);
char			*percen_char(va_list args, t_flags *st_flag);
char			*s_form(va_list args, t_flags *st_flag);
char			*p_form(va_list args, t_flags *st_flag);
char			*d_form(va_list args, t_flags *st_flag);
char			*x_form(va_list args, t_flags *st_flag);
char			*uppx_form(va_list args, t_flags *st_flag);
char			*o_form(va_list args, t_flags *st_flag);
char			*u_form(va_list args, t_flags *st_flag);
char			*f_form(va_list args, t_flags *st_flag);
char			*format_str(char *str, char f, t_flags *st_flags);
char			*zero_flag(char *fstr, t_flags *st_flag);
char			*default_field(char *fstr, char f, t_flags *st_flag);
char			*minus_flag(char *fstr, char f, t_flags *st_flag);
char			*hash_flag(char *str, char f, t_flags *st_flags);
char			*plus_flag(char *fstr, char f);
char			*space_flag(char *fstr, char f);
char			*s_prec(char *fstr, t_flags *st_flags);
char			*dux_prec(char *fstr, t_flags *st_flag);
char			*o_prec(char *fstr, t_flags *st_flags);
#endif
