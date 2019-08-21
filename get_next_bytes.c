

#include "ssl.h"

int		ft_append_byte()
{

}

int		ft_chunk_bytes(const int fd, char *buff, char **str, int bytes)
{
	int ret;
	char *tmp;
	int len;

	len = 0;
	while((ret = read(fd, buff, bytes)) > 0)
	{
		if(ret == 64)
		{
			len++;
		}
	}
	len++;
	return (len);
}

int		get_next_bytes(const int fd, int bytes, char *mssg)
{
	uint8_t buff[bytes]; //set of 8 bit by number of bytes //char
	uint64_t set; //64-bit
	uint32_t msg_chunk; //4-byte words

	if(fd < 0 || !mssg || read(fd, buff, 0) < 0)
		return (-1);
	if()
	{

	}

}