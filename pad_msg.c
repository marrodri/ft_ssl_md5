
#include "ssl.h"
#include <stdio.h>
long long int bit_str_len(char *mssg)
{
	unsigned int bit_str;
	int i;

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
	printf(" _a is |%u|\n", bit_str);
	return 0;
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
	long long int test;
	test = bit_str_len(av[1]);

}