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

void	free_list(t_list **list)
{
	t_list *tmp;

	// ft_printf("!!!!!!!FREEE HERE !!!!!!!!!!!\n");
	while(*list)
	{
		tmp = (*list)->next;
		// if(list)
		// 	ft_printf("list is not null content|%s|\n", (*list)->content);
		// else
		// 	ft_printf("list is null\n");
		if((*list)->content)
		{
			(*list)->content_size = 0;
			(*list)->content = NULL;
			// free((*list)->content);
		}
		free(*list);
		(*list) = NULL;
		*list = tmp;
	}
		// ft_printf("=============FINISH FREE =============\n");
}


int		main(int argc, char **argv)
{
	int		fd;
	t_flag	*flags;
	t_hash	*hash_v;
	t_list	*list;
	int 	bytes;
	int 	i;
	int		input;

	flags = malloc(sizeof(t_flag));
	hash_v = malloc(sizeof(t_hash));
	if (argc == 2)
		i = 1;
	else
		i = 2;
	if (argc == 1)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");

	else if ((input = hash_checker(argv[1])) != -1 && ci_set(argv, argc, &i, &flags))
	{
		// for(int j = 0; j < 4; j++)
		// {
		// 	ft_printf("flag[%d]=|%d|\n",j,flags->ci_flags[j]);
		// }
		if (argc == 2 || flags->ci_flags[2] || !argv[i]) //-p flag
		{
			fd = 0;
			bytes = MD5_BYTES;
			set_bytes_fd(fd, bytes, &list, &hash_v);
			hash_v->mssg_dig = hash_func(input, list, hash_v);
			// if(flags->ci_flags[2])
			// 	ft_printf("%s", hash_v->mssg);
			// put_md5hash(hash_v->mssg_dig);
			// ft_printf("\n");
			p_flag(&flags, &hash_v);
			free_list(&list);
		}
		while (i <= argc && argc != 2)
		{
			if (flags->ci_flags[3] == 1) //-s input activated
			{
				s_flag(argv, &flags, &hash_v, i);
				// if (argv[i])
				// 	ft_printf("read string %s\n", argv[i]);
				// else
				// {
				// 	ft_printf("%s: option requires an argument --s\n", argv[1]);
				// 	ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", argv[1]);
				// }
				// flags->ci_flags[3] = 0;
			}
			else
			{
				fd = open(argv[i], O_RDONLY);
				if (fd == -1 && argv[i])
					ft_printf("%s: %s: No such file or directory\n", argv[1], argv[i]);
				else if(argv[i])
				{
					// ft_printf("no seg fault here continue\n");
					bytes = MD5_BYTES;
					set_bytes_fd(fd, bytes, &list, &hash_v);
					// ft_printf("list node is inside in rq flag|%s|\n", list->content);
					hash_v->mssg_dig = hash_func(input, list, hash_v);
					rq_flag(argv, &flags, &hash_v, i);
					// ft_printf("here\n");
					free_list(&list);
				}
				// else if (argv[i])
				// {
				// 	if (!flags->ci_flags[0] && !flags->ci_flags[1])
				// 		ft_printf("%s (%s) = ", ft_strupper(argv[1]), argv[i]);
				// 	bytes = MD5_BYTES;
				// 	set_bytes_fd(fd, bytes, &list, &hash_v);
				// 	hash_v->mssg_dig = hash_func(input, list, hash_v);
				// 	put_md5hash(hash_v->mssg_dig);
				// 	if(flags->ci_flags[0])
				// 		ft_printf(" %s\n", argv[i]);
				// 	ft_printf("\n");
				// }
			}
			i++;
		}
	}
	return (0);
}
