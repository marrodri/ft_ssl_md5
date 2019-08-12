
#include "ssl.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	unsigned int a = 10;

	int fd;
	if(argc >= 1)
	{
		fd = open(argv[1], O_RDWR);
		if(fd != -1)
		{
			write(fd, "test", 5);
		}
		// const int k;
		printf("%d\n", fd);
		return (0);
	}
}