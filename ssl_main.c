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
#include <stdio.h>

//TODO IMPORTANT CHANGE ALL FUNCTIONS TO FT_FUNCTIONS
int		cmmnd_checker(char *str)
{
	int			i;
	const char	*hash_algo[HS_SZ] = HS_COM;

	i = 0;
	while(i < HS_SZ)
	{
		if(!strcmp(str, hash_algo[i]))
		{
			return (1);
		}
		i++;
	}
	printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
			Standard commands:\n\nMessage Digest commands:\nmd5\
			\nsha256\n\nCipher commands:\n", str);
	return (0);
}



int		main(int argc, char **argv)
{
	int		fd;
	t_flag	*flags;
	t_hash	*hash;
	t_list	*list;
	int 	bytes;
	int 	i;

	if(argc == 2)
		i = 1;
	else
		i = 2;
	flags = malloc(sizeof(t_flag));
	hash = malloc(sizeof(t_hash));
	if (argc == 1)
		printf("usage: ft_ssl command [command opts] [command args]\n");

	else if(cmmnd_checker(argv[1]) && ci_set(argv, argc, &i, &flags))
	{
		if (argc == 2 || flags->ci_flags[2])
		{
			fd = 0;
			bytes = MD5_BYTES;
			hash->chunk_len = ft_set_bytes_fd(fd, bytes, &list);
			hash->md_128bit = md5_hash(list);
		}
		while(i < argc && argc != 2)
		{
			if(flags->ci_flags[3] == 1)// -s input activated
			{
				if(argv[i])
				printf("read string %s\n", argv[i]);
				else
				{
					printf("%s: option requires an argument --s\n", argv[1]);
					printf("usage: %s [-pqr] [-s string] [files ...]\n", argv[1]);
				}
				flags->ci_flags[3] = 0;
			}
			else
			{
				fd = open(argv[i], O_RDONLY);
				if (fd == -1)
				{
					printf("md5: %s: No such file or directory\n", argv[i]);
				}
				else
				{
					printf("read args fd is %d\n", fd);
					bytes = MD5_BYTES;
					hash->chunk_len = ft_set_bytes_fd(fd, bytes, &list);
					hash->md_128bit = md5_hash(list);
				}
			}
			i++;
		}
	}
	return (0);
}