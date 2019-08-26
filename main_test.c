
#include "ssl.h"

uint32_t ft_32bitpad(uint8_t *chunk)
{
	int i;
	int j;
	uint32_t word;
	i = 0;
	j = 0;
	word = 0;
	while(i < 4)
	{
		word = (word << 8) | chunk[j];
		j+= 1;
		i++;
	}
	return word;
}

int main()
{
	uint8_t tst[4] = "abcd";
	uint8_t tst2[4] = "efgh";
	uint32_t word[2];

	word[0] = ft_32bitpad(tst);
	word[1] = ft_32bitpad(tst2);
	printf("word is dec|%u| hex|%x|\n", word[0], word[0]);
	printf("word is dec|%u| hex|%x|\n", word[1], word[1]);
}