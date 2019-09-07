/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_cmnds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:22:34 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/05 17:22:37 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	s_output(char **argv, t_flag **flags, t_hash **hash_v, int i)
{
	if (argv[i])
	{
		if ((*flags)->ci_flags[0])
		{
			put_md5hash((*hash_v)->mssg_dig);
			ft_printf(" \"%s\"\n", argv[i]);
		}
		else if (!(*flags)->ci_flags[1])
		{
			ft_printf("%s (\"%s\") = ", ft_strupper(argv[1]), argv[i]);
			put_md5hash((*hash_v)->mssg_dig);
			ft_printf("\n");
		}
		else
		{
			put_md5hash((*hash_v)->mssg_dig);
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

void	p_output(t_flag **flags, t_hash **hash_v)
{
	if ((*flags)->ci_flags[2])
		ft_printf("%s", (*hash_v)->mssg);
	put_md5hash((*hash_v)->mssg_dig);
	ft_printf("\n");
}

void	rq_output(char **argv, t_flag **flags, t_hash **hash_v, int i)
{
	if (!(*flags)->ci_flags[0] && !(*flags)->ci_flags[1])
		ft_printf("%s (%s) = ", ft_strupper(argv[1]), argv[i]);
	put_md5hash((*hash_v)->mssg_dig);
	if ((*flags)->ci_flags[0])
		ft_printf(" %s", argv[i]);
	ft_printf("\n");
}
