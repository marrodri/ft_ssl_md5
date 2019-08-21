
#include "ssl.h"
#include <stdio.h>

t_uint append_byte(t_uint val, t_uint b)
{
	val = (val << 8) | b;
	return val;
}

t_uint bit_str_len(char *mssg)
{
	unsigned int bit_str;
	unsigned int bitstr_len;
	unsigned int i;

	i = 0;
	bit_str = 0;
	while(mssg[i])
	{
		if(i != 0)
		{
			bit_str = bit_str << 8;
		}
		bit_str = (bit_str | mssg[i]);
		i++;
	}
	printf("%s is |%x|\n", mssg, bit_str);
	bit_str = ((bit_str << 1) | 1);
	printf("after append 1 bit is |%x|\n", bit_str);
	// while(bit_str % 512 != 448)
	// {
	// 	bit_str = bit_str << 1;
	// }
	// printf("after while loop bit is |%x|\n", bit_str);
	return bit_str;
}

// void	*padded_msg(char *mssg)
// {
// 	t_uint pad_val;
// 	t_uint val;
// 	char *pad_mssg;


// 	//first add 1 bit to the message padded
// 	pad_val = ((val << 1) | 1);


// 	//if the added 1 bit doesn't return the exact val mod 512
// 	//then padd the value with 0 bits until getting the value mod 512

// 	while(pad_val % 512 != 448)
// 	{
// 		pad_val << 8;
// 	}
// 	return pad_val;
// }
int main(int ac, char **av)
{
	char *str;
	t_uint test;
	test = bit_str_len(av[1]);

}