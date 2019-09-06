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

	while(*list)
	{
		tmp = (*list)->next;
		if((*list)->content)
		{
			(*list)->content_size = 0;
			(*list)->content = NULL;
		}
		free(*list);
		(*list) = NULL;
		*list = tmp;
	}
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
		if (argc == 2 || flags->ci_flags[2] || !argv[i]) //-p flag
		{
			fd = 0;
			bytes = MD5_BYTES;
			set_bytes_fd(fd, bytes, &list, &hash_v);
			hash_v->mssg_dig = hash_func(input, list, hash_v);
			p_flag(&flags, &hash_v);
			free_list(&list);
		}
		while (i <= argc && argc != 2)
		{
			if (flags->ci_flags[3] == 1)
			{
				s_flag(argv, &flags, &hash_v, i);
			}
			else
			{
				fd = open(argv[i], O_RDONLY);
				if (fd == -1 && argv[i])
					ft_printf("ft_ssl: %s: %s: No such file or directory\n", argv[1], argv[i]);
				else if(argv[i])
				{
					bytes = MD5_BYTES;
					set_bytes_fd(fd, bytes, &list, &hash_v);
					hash_v->mssg_dig = hash_func(input, list, hash_v);
					rq_flag(argv, &flags, &hash_v, i);
					free_list(&list);
				}
			}
			i++;
		}
	}
	return (0);
}
