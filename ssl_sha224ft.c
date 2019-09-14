
#include "ssl.h"

void		*ft_append_224bit(uint32_t *input)
{
	static uint8_t	output[32];
	uint32_t		i;
	uint32_t		j;
	ft_printf("here?!!!!!!\n");
	i = -1;
	while (++i < 8)
		input[i] = swap_endian(input[i]);
	i = 0;
	j = 0;
	while (j < 32)
	{
		output[j] = (input[i] & 0xff);
		output[j + 1] = ((input[i] >> 8) & 0xff);
		output[j + 2] = ((input[i] >> 16) & 0xff);
		output[j + 3] = ((input[i] >> 24) & 0xff);
		output[j + 4] = (input[i + 1] & 0xff);
		output[j + 5] = ((input[i + 1] >> 8) & 0xff);
		output[j + 6] = ((input[i + 1] >> 16) & 0xff);
		output[j + 7] = ((input[i + 1] >> 24) & 0xff);
		j += 8;
		i += 2;
	}
	return (output);
}
