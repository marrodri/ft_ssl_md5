
#include "ssl.h"
#include <stdio.h>

//TODO IMPORTANT CHANGE ALL FUNCTIONS TO FT_FUNCTIONS
int	cmmnd_checker(char *str)
{
	int			i;
	const char	*hash_algo[] = HS_COM;

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

int flag_checker(char **str, int j, t_flag **flags)
{
	str = NULL;
	j = 0;
	flags = NULL;
	return 1;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_flag	*flags;
	t_hash	*hash;
	t_list	*list;
	int bytes;
	int		j;
	int i;

	i = 2;

	j = 1;
	if(argc == 1)
		printf("usage: ft_ssl command [command opts] [command args]\n");

	else if(cmmnd_checker(argv[1]) && flag_checker(argv, j, &flags))
	{
		printf("Command found '%s'\n", argv[1]);
		flags = malloc(sizeof(t_flag));
		hash = malloc(sizeof(t_hash));
		if (argc == 2)
		{
			fd = 0;
		}
		else 
		{
			while(i < argc)
			{
				// printf("file found encrypt\n");
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