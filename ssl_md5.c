
//TODO md5 algo implemented

//  unsigned int[64] s; shifts
//	unsigned int[64] K; KEYS
//check header for the exact numbers

// leftrotate bits function

unsigned int rotate_left(unsigned int F, unsigned int s)
{
	return (F << s) | (s >> (32 - s));
}

#include "ssl.h"

unsigned int a0 = 0x67452301;
unsigned int b0 = 0xefcdab89;
unsigned int c0 = 0x98badcfe;
unsigned int d0 = 0x10325476;

//first add 1 bit to the message
