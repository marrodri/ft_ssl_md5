
#include <stdio.h>
#include "ssl.h"

uint32_t swap_endian(uint32_t num)
{
	return (((num & 0x000000ff) << 24u) |
			((num & 0x0000ff00) << 8u) |
			((num & 0x00ff0000) >> 8u) |
			((num & 0xff000000) >> 24u)); 
}

int main()
{
	uint32_t a = 0x18;
	uint32_t b = ROT_RIGHT(a, 17) ^ ROT_RIGHT(a, 19) ^ (a >> 10);
	uint32_t b1 = ROT_RIGHT(a, 17);
	uint32_t b2 = ROT_RIGHT(a, 19);
	uint32_t b3 =(a >> 10);

	printf("before |%08x|\n", a);

	printf("b1 |%08x|\n", b1);
	printf("b2 |%08x|\n", b2);
	printf("b3 |%08x|\n", b3);
	// b = swap_endian(a);
	printf("after %x\n", b);
}