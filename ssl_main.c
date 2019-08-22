
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
	return 1;
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[20];
	int		j;
	int		ret;
	int		byte_found = 0;
	t_flag	*flags;
	t_hash	*hash;
	t_list	*list;
	int bytes = 4;
	j = 2;
	flags = malloc(sizeof(t_flag));
	if(argc == 1)
		printf("usage: ft_ssl command [command opts] [command args]\n");

	else if(cmmnd_checker(argv[1]) && flag_checker(argv, j, &flags))
	{
		printf("Command found '%s'\n", argv[1]);
		fd = 0;
		flags = malloc(sizeof(t_flag));
		hash = malloc(sizeof(t_hash));
		hash->chunks = ft_set_bytes(fd, bytes, &list);
		printf("we have |%d| chunks of %d bytes\n", hash->chunks, bytes);
		// while((ret = read(fd, buffer, 5)) > 0)
		// {
		// 	byte_found =  byte_found + ret;
		// 	printf("ret is |%d|\n", ret);
		// 	printf("buffer |%s|\n", buffer);
		// }
			printf("chunk |%s|\n", list->content);
		// while(list->content)
		// {
		// 	list = list->next;
		// }
	}

	else
	{
		printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
			Standard commands:\n\nMessage Digest commands:\nmd5\
			\nsha256\n\nCipher commands:\n", argv[1]);
	}

	return (0);
}