/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:13:48 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/06 22:13:50 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	stdin_p_input(t_app *app, t_list *list, t_flag *flags, t_hash *hash_v)
{
	char	**argv;

	argv = app->av;
	app->fd = 0;
	set_bytes_fd(app, &list, &hash_v);
	hash_v->mssg_dig = hash_func(app->input, list, hash_v);
	p_output(&flags, &hash_v, app);
	free_list(&list);
}

void	str_input(t_app *app, t_list *list, t_hash *hash_v, t_flag *flags)
{
	char	**argv;
	int		i;

	i = app->i;
	argv = app->av;
	hash_v->mssg = argv[i];
	set_bytes_str(app, argv[i], &list);
	hash_v->mssg_dig = hash_func(app->input, list, hash_v);
	s_output(argv, &flags, &hash_v, app);
	free_list(&list);
}

void	fd_input(t_app *app, t_list *list, t_hash *hash_v, t_flag *flags)
{
	char	**argv;
	int		i;

	i = app->i;
	argv = app->av;
	app->fd = open(argv[i], O_RDONLY);
	if (app->fd == -1 && argv[i])
		ft_printf("ft_ssl: %s: %s: No such file or directory\n",
			argv[1], argv[i]);
	else if (argv[i])
	{
		set_bytes_fd(app, &list, &hash_v); //rename to get_mssg_fd(app, &hash_v) list will be moved inside the hash functions
		hash_v->mssg_dig = hash_func(app->input, list, hash_v);
		rq_output(argv, &flags, &hash_v, app);
		free_list(&list);
	}
}
