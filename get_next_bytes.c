#include <stdio.h>

#include "ssl.h"

int		ft_append_byte()
{
	return 0;
}

int		ft_set_bytes(const int fd, int bytes, t_list **list)
{
	int ret;
	uint8_t buff[bytes];
	int len;

	len = 0;
	while((ret = read(fd, buff, bytes)) > 0)
	{
		if(ret == bytes)
		{
			len++;
		}
		if(ret < bytes && ret != 0)
		{	
			len++;
			printf("ret is less than %d bytes appending!!!\n", bytes);
		}
	}
	return (len);
}

int		set_bytes(const int fd, int bytes, char *mssg)
{
	uint8_t buff[bytes]; //set of 8 bit by number of bytes //char
	uint64_t set; //64-bit
	uint32_t msg_chunk; //4-byte words
	
	return 0;
}