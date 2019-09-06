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

int		cmmnd_checker(char *str)
{
	int			i;
	const char	*hash_algo[HS_SZ] = HS_COM;

	i = 0;
	while(i < HS_SZ)
	{
		if(!strcmp(str, hash_algo[i]))
		{
			return (i);
		}
		i++;
	}
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
			Standard commands:\n\nMessage Digest commands:\nmd5\
			\nsha256\n\nCipher commands:\n", str);
	return (-1);
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
	int		j;

	j =0;
	if(argc == 2)
		i = 1;
	else
		i = 2;
	flags = malloc(sizeof(t_flag));
	hash_v = malloc(sizeof(t_hash));
	if (argc == 1)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");

	else if((input = cmmnd_checker(argv[1])) != -1 && ci_set(argv, argc, &i, &flags))
	{
		if (argc == 2 || flags->ci_flags[2])
		{
			fd = 0;
			bytes = MD5_BYTES;
			set_bytes_fd(fd, bytes, &list, &hash_v);
			hash_v->mssg_dig = hash_func(input, list, hash_v);
			if(flags->ci_flags[2])
				ft_printf("%s", hash_v->mssg);
			put_md5hash(hash_v->mssg_dig);
			ft_printf("\n");
		}
		while(i <= argc && argc != 2)
		{
			if(flags->ci_flags[3] == 1) //-s input activated
			{
				if(argv[i])
					ft_printf("read string %s\n", argv[i]);
				else
				{
					ft_printf("%s: option requires an argument --s\n", argv[1]);
					ft_printf("usage: %s [-pqr] [-s string] [files ...]\n", argv[1]);
				}
				flags->ci_flags[3] = 0;
			}
			else
			{
				fd = open(argv[i], O_RDONLY);
				if (fd == -1 && argv[i])
					ft_printf("md5: %s: No such file or directory\n", argv[i]);
				else if(argv[i])
				{
					if(!flags->ci_flags[0] && !flags->ci_flags[1])
						ft_printf("%s (%s) = ", argv[1], argv[i]);
					bytes = MD5_BYTES;
					set_bytes_fd(fd, bytes, &list, &hash_v);
					hash_v->mssg_dig = hash_func(input, list, hash_v);
					if(flags->ci_flags[0])
						ft_printf(" %s\n", argv[i]);
				}
			}
			i++;
		}
	}
	return (0);
}
