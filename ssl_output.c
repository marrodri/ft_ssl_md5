/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:39:32 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/07 14:39:34 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	s_output(char **argv, t_flag **flags, t_hash **hash_v, t_app *app)
{
	if (argv[app->i])
	{
		if ((*flags)->ci_flags[0])
		{
			put_hashmd(app->input, (*hash_v)->mssg_dig);
			ft_printf(" \"%s\"\n", argv[app->i]);
		}
		else if (!(*flags)->ci_flags[1])
		{
			ft_printf("%s(\"%s\")= ", ft_strupper(argv[1]), argv[app->i]);
			put_hashmd(app->input, (*hash_v)->mssg_dig);
			ft_printf("\n");
		}
		else
		{
			put_hashmd(app->input, (*hash_v)->mssg_dig);
			ft_printf("\n");
		}
	}
	else
	{
		ft_printf("%s: option requires an argument --s\n", argv[1]);
		ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", argv[1]);
	}
	(*flags)->ci_flags[3] = 0;
}

void	p_output(t_flag **flags, t_hash **hash_v, t_app *app)
{
	if ((*flags)->ci_flags[2])
		ft_printf("%s", (*hash_v)->mssg);
	put_hashmd(app->input, (*hash_v)->mssg_dig);
	ft_printf("\n");
}

void	rq_output(char **argv, t_flag **flags, t_hash **hash_v, t_app *app)
{
	if (!(*flags)->ci_flags[0] && !(*flags)->ci_flags[1])
		ft_printf("%s(%s)= ", ft_strupper(argv[1]), argv[app->i]);
	put_hashmd(app->input, (*hash_v)->mssg_dig);
	if ((*flags)->ci_flags[0])
		ft_printf(" %s", argv[app->i]);
	ft_printf("\n");
}
