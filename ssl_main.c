
#include "ssl.h"
#include "stdio.h"

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

int	main(int argc, char **argv)
{
	int fd;
	char buffer[20];

	if(argc == 1)
	{
		//change to ft_printf
		printf("usage: ft_ssl command [command opts] [command args]\n");
	}
	else if(cmmnd_checker(argv[1]))
	{
		// fd = open(argv[1], O_RDWR);
		// if(fd != -1)
		// {
		// 	write(fd, "wsdfsdfsfdf hello", 20);
		// }
		// // const int k;
		while(read(STDIN_FILENO, buffer, 10))
		{
			printf("buffer |%s|\n", buffer);
		}
		printf("Command found '%s'\n", argv[1]);
	}
	else
	{
		printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
			Standard commands:\n\nMessage Digest commands:\nmd5\
			\nsha256\n\nCipher commands:\n", argv[1]);
	}
	return (0);
}