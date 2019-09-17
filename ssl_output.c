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

void	s_output(t_list *list, t_flag **flags, t_hash **hash_v, t_app *app)
{
	if (app->av[app->i])
	{
		if ((*flags)->ci_flags[0])
		{
			(*hash_v)->mssg_dig = hash_func(app->input, list, *hash_v);
			ft_printf(" \"%s\"\n", app->av[app->i]);
		}
		else if (!(*flags)->ci_flags[1])
		{
			ft_printf("%s(\"%s\")= ", ft_strupper(app->av[1]), app->av[app->i]);
			(*hash_v)->mssg_dig = hash_func(app->input, list, *hash_v);
			ft_printf("\n");
		}
		else
		{
			(*hash_v)->mssg_dig = hash_func(app->input, list, *hash_v);
			ft_printf("\n");
		}
	}
	else
	{
		ft_printf("%s: option requires an argument --s\n", app->av[1]);
		ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", app->av[1]);
	}
	(*flags)->ci_flags[3] = 0;
}

void	p_output(t_list *list, t_flag **flags, t_hash **hash_v, t_app *app)
{
	if ((*flags)->ci_flags[2])
		ft_printf("%s", (*hash_v)->mssg);
	(*hash_v)->mssg_dig = hash_func(app->input, list, *hash_v);
	ft_printf("\n");
}

void	rq_output(t_list *list, t_flag **flags, t_hash **hash_v, t_app *app)
{
	if (!(*flags)->ci_flags[0] && !(*flags)->ci_flags[1])
		ft_printf("%s(%s)= ", ft_strupper(app->av[1]), app->av[app->i]);
	(*hash_v)->mssg_dig = hash_func(app->input, list, *hash_v);
	if ((*flags)->ci_flags[0])
		ft_printf(" %s", app->av[app->i]);
	ft_printf("\n");
}
