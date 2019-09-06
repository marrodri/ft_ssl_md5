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

//TODO implement command flags

#include "ssl.h"

//-s
//ft_printf("MD5 (/"%s/") = "); //use this separate for -r and -q flag
void	s_flag(char **argv, t_flag **flags, t_hash **hash_v, int i)
{
	if (argv[i])
	{
		if((*flags)->ci_flags[0])
		{
			put_md5hash((*hash_v)->mssg_dig);
			ft_printf(" \"%s\"\n", ft_strupper(argv[1]),argv[i]);
		}
		if(!(*flags)->ci_flags[1])
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
	(*hash_v)->mssg = argv[1];
	(*flags)->ci_flags[3] = 0;
	return ;
}

//-p
//ft_printf("%s\n%x\n", stdin, ft_md5(stdin));

void	p_flag(t_flag **flags, t_hash **hash_v)
{
	if((*flags)->ci_flags[2])
		ft_printf("%s", (*hash_v)->mssg);
	put_md5hash((*hash_v)->mssg_dig);
	ft_printf("\n");
}

//-r
//ft_printf("%x ",ft_md5(*file readed*));
//ft_printf(" %s\n", file name);
//ft_printf("/"%s/"", string); in case -s is implemented
//-q
//ft_printf("%x\n", ft_md5(*file readed*));

void	rq_flag(char **argv, t_flag **flags, t_hash **hash_v, int i)
{
	if (!(*flags)->ci_flags[0] && !(*flags)->ci_flags[1])
		ft_printf("%s (%s) = ", ft_strupper(argv[1]), argv[i]);
	// bytes = MD5_BYTES;
	// set_bytes_fd(fd, bytes, &list, &hash_v);
	// hash_v->mssg_dig = hash_func(input, list, hash_v);
	put_md5hash((*hash_v)->mssg_dig);
	if((*flags)->ci_flags[0])
		ft_printf(" %s", argv[i]);
	ft_printf("\n");
}