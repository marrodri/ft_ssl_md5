
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

void	init_ci_flags(t_flag **flags)
{
	int i;

	i= 0;
	while(i < CI_SZ)
	{
		(*flags)->ci_flags[i] = 0;
		i++;
	}
}

int		ci_checker(char **str, int lim ,int *i, t_flag **flags)
{
	const char ci_flags[CI_SZ] = CI_COM;
	int j;
	int check;

	if (lim == 2)
		check = 1;
	init_ci_flags(flags);
	while (str[*i][0] == '-')
	{
		j = 0;
		while (j < CI_SZ)
		{
			if (ci_flags[j] == str[*i][1])
			{
				(*flags)->ci_flags[j] = 1;
				check = 1;
			}
			j++;
		}
		if (str[*i][1] == 's')
		{
			*i += 1;
			break;
		}
		*i += 1;
		if (*i >= lim)
			break;
	}
	if(check)
		return (1);
	else
	{
		printf("usage: %s [-pqr] [-s string] [files ...]", str[1]);
		return (0);
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_flag	*flags;
	t_hash	*hash;
	t_list	*list;
	int bytes;
	int 	i;
	if(argc == 2)
		i = 1;
	else
		i = 2;

		flags = malloc(sizeof(t_flag));
		hash = malloc(sizeof(t_hash));
	if(argc == 1)
		printf("usage: ft_ssl command [command opts] [command args]\n");

	else if(cmmnd_checker(argv[1]) && ci_checker(argv, argc, &i, &flags))
	{
		printf("Command found '%s'\n", argv[1]);
		// ci_checker(argv, &i, &flags);
		if (argc == 2)
		{
			fd = 0;
			bytes = MD5_BYTES;
			hash->chunk_len = ft_set_bytes(fd, bytes, &list);
			hash->md_128bit = md5_hash(list);
		}
		else 
		{
			while(i < argc)
			{
				// printf("file found encrypt\n");
				if(flags->ci_flags[3] == 1)
				{
					if(argv[i])
					printf("read string %s\n", argv[i]);
					else
					{
						printf("%s: option requires an argument --s\n", argv[1]);
						printf("usage: %s [-pqr] [-s string] [files ...]\n", argv[1]);
					}
				}
				else
				{
					fd = open(argv[i], O_RDONLY);
					if (fd == -1)
					{
						printf("md5: %s: No such file or directory", argv[i]);
					}
					else
					{
						printf("read args fd is %d\n", fd);
						bytes = MD5_BYTES;
						hash->chunk_len = ft_set_bytes(fd, bytes, &list);
						hash->md_128bit = md5_hash(list);
					}
				}
				i++;
			}
		}
	}

	// else
	// {
	// 	printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
	// 		Standard commands:\n\nMessage Digest commands:\nmd5\
	// 		\nsha256\n\nCipher commands:\n", argv[1]);
	// }

	return (0);
}