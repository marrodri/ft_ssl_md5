
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
	uint32_t a = 9;
	uint32_t b;
	printf("before %x\n", a);
	b = swap_endian(a);
	printf("after %x\n", b);
}