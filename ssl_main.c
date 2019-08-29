
#include "ssl.h"
#include <stdio.h>

//TODO IMPORTANT CHANGE ALL FUNCTIONS TO FT_FUNCTIONS
int	cmmnd_checker(char *str)
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
	return (0);
}

int ci_checker(char **str, int lim ,int *i, t_flag **flags)
{
	const char ci_flags[CI_SZ] = CI_COM;
	int j;
	int flag;

	flag = 0;
	if(lim == 2)
		flag = 1;
	while(str[*i][0] == '-' && *i < lim)
	{
		printf("new command found\n");
		j = 0;
		while(j < CI_SZ)
		{
			if(ci_flags[j] == str[*i][1])
			{
				printf("comm is |%c|\n", str[*i][1]);
				(*flags)->ci_flags[j] = 1;
				flag = 1;
			}
			j++;
		}
		*i += 1;
	}
	if(flag)
		return 1;
	else
	{
		return 0;
	}
	
}

int	main(int argc, char **argv)
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
			// while(argv[i][0] == '-')
			// {
			// 	printf("flag founded\n");
			// 	i++;
			// }
			while(i < argc)
			{
				// printf("file found encrypt\n");
				printf("fd is %d\n", fd);
				fd = open(argv[i], O_RDONLY);
				bytes = MD5_BYTES;
				hash->chunk_len = ft_set_bytes(fd, bytes, &list);
				hash->md_128bit = md5_hash(list);
				i++;
			}
		}
	}

	else
	{
		printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
			Standard commands:\n\nMessage Digest commands:\nmd5\
			\nsha256\n\nCipher commands:\n", argv[1]);
	}

	return (0);
}