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
	while(j < 16)
	{
		ft_printf("%02x", md[j]);
		j++;
	}
}

void	stdin_p_input(t_app *app, t_list *list, t_flags *flags, t_hash *hash_v)
{
	app->fd = 0;
	set_bytes_fd(app->fd, app->bytes, &list, &hash_v);
	hash_v->mssg_dig = hash_func(app->input, list, hash_v);
	p_output(&flags, &hash_v);
	free_list(&list);
}

void	str_input(t_app *app, t_list *list, t_hash *hash_v, t_flags *flags)
{
	set_bytes_str(argv[i], app->bytes, &list);
	hash_v->mssg_dig = hash_func(app->input, list, hash_v);
	s_output(argv, &flags, &hash_v, i);
	free_list(&list);
}

void	fd_input(t_app *app, t_list *list, t_hash *hash_v, t_flags *flags)
{
	app->fd = open(argv[i], O_RDONLY);
	if (app->fd == -1 && argv[i])
		ft_printf("ft_ssl: %s: %s: No such file or directory\n", argv[1], argv[i]);
	else if(argv[i])
	{
		set_bytes_fd(app->fd, app->bytes, &list, &hash_v);
		hash_v->mssg_dig = hash_func(app->input, list, hash_v);
		rq_output(argv, &flags, &hash_v, i);
		free_list(&list);
	}
}

int		main(int argc, char **argv)
{
	t_flag	*flags;
	t_hash	*hash_v;
	t_list	*list;
	t_app	*app;
	int 	i;

	flags = malloc(sizeof(t_flag));
	app = malloc(sizeof(t_app));
	hash_v = malloc(sizeof(t_hash));
	app->bytes = MD5_BYTES;
	if (argc == 2)
		i = 1;
	else
		i = 2;
	if (argc == 1)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else if ((app->input = hash_checker(argv[1])) != -1 && ci_set(argv, argc, &i, &flags))
	{
		if (argc == 2 || flags->ci_flags[2] || !argv[i])
		{
			// app->fd = 0;
			// set_bytes_fd(app->fd, app->bytes, &list, &hash_v);
			// hash_v->mssg_dig = hash_func(app->input, list, hash_v);
			// p_output(&flags, &hash_v);
			// free_list(&list);
			stdin_p_input(app, list, flags, hash_v);
		}
		while (i <= argc && argc != 2)
		{
			if (flags->ci_flags[3] == 1)
			{
				// set_bytes_str(argv[i], app->bytes, &list);
				// hash_v->mssg_dig = hash_func(app->input, list, hash_v);
				// s_output(argv, &flags, &hash_v, i);
				// free_list(&list);
				str_input(app, list, hash_v, flags);
			}
			else
			{
				app->fd = open(argv[i], O_RDONLY);
				if (app->fd == -1 && argv[i])
					ft_printf("ft_ssl: %s: %s: No such file or directory\n", argv[1], argv[i]);
				else if(argv[i])
				{
					// set_bytes_fd(app->fd, app->bytes, &list, &hash_v);
					// hash_v->mssg_dig = hash_func(app->input, list, hash_v);
					// rq_output(argv, &flags, &hash_v, i);
					// free_list(&list);
					fd_input(app, list, hash_v, flags);
				}
			}
			i++;
		}
	}
	return (0);
}
