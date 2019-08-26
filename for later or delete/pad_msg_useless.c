
#include "ssl.h"
#include <stdio.h>

t_uint append_byte(t_uint val, t_uint b)
{
	val = (val << 8) | b;
	return val;
}

int		read_chunks(char *str, int bytes)
{
	int i;
	int len;

	len = 1;
	i = 0;
	while(str[i++])
	{
		if(i % bytes == 0)
		{
			len++;
		}
	}
	return len;
}

void	preprocess(t_hash **hash, int bytes, int fd)
{
	uint8_t *chunk;
}