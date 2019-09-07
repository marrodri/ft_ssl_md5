/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:24:12 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/29 12:24:14 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	put_md5hash(uint8_t *md)
{
	int j;

	j = 0;
	while (j < 16)
	{
		ft_printf("%02x", md[j]);
		j++;
	}
}

void	init_main(t_flag **flags, t_hash **hash_v, t_app **app, char **argv)
{
	*flags = malloc(sizeof(t_flag));
	*app = malloc(sizeof(t_app));
	*hash_v = malloc(sizeof(t_hash));
	(*app)->av = argv;
	(*app)->bytes = MD5_BYTES;
}

void	init_input(t_app **app, int argc)
{
	if (argc == 2)
		(*app)->i = 1;
	else
		(*app)->i = 2;
}

int		main(int argc, char **argv)
{
	t_flag	*flags;
	t_hash	*hash_v;
	t_list	*list;
	t_app	*app;

	init_main(&flags, &hash_v, &app, argv);
	init_input(&app, argc);
	list = NULL;
	hash_v->mssg = NULL;
	if (argc == 1)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else if ((app->input = hash_checker(argv[1])) != -1
		&& ci_set(argv, argc, &app->i, &flags))
	{
		if (argc == 2 || flags->ci_flags[2] || !argv[app->i])
			stdin_p_input(app, list, flags, hash_v);
		while (app->i <= argc && argc != 2)
		{
			if (flags->ci_flags[3] == 1)
				str_input(app, list, hash_v, flags);
			else
				fd_input(app, list, hash_v, flags);
			app->i++;
		}
	}
	return (0);
}
