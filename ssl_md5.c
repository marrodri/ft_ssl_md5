
//TODO md5 algo implemented

//  unsigned int[64] s; shifts
//	unsigned int[64] K; KEYS

// leftrotate bits function by 32 bits

//check header for the exact numbers
// # define K0 { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee }
// # define K1 { 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 }
// # define K2 { 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be }
// # define K3 { 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 }

// # define K4	{ 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa }
// # define K5	{ 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 }
// # define K6	{ 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed }
// # define K7	{ 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a }

// # define K8	{ 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c }
// # define K9	{ 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 }
// # define K10{ 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 }
// # define K11{ 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 }

// # define K12 { 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 }
// # define K13 { 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 }
// # define K14 { 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 }
// # define K15 { 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 }

// s[ 0..15] := { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22 }
// s[16..31] := { 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20 }
// s[32..47] := { 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23 }
// s[48..63] := { 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 }

#include "ssl.h"

// void	md5v_init(t_md5v **md5Vr)
// {
// 	(*md5Vr)->a0 = A0;
// 	(*md5Vr)->b0 = B0;
// 	(*md5Vr)->c0 = C0;
// 	(*md5Vr)->d0 = D0;
// }

uint32_t ft_32bitpad(uint8_t *chunk, int *j)
{
	int i;
	uint32_t word;
	i = 0;
	word = 0;
	while(i < 4)
	{
		word = (word << 8) | chunk[*j];
		*j+= 1;
		i++;
	}
	return word;
}

uint32_t *split_32bitwords(uint32_t *words, uint8_t *chunk)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		words[i] = (chunk, &j);
		printf("dec is|%u| hex is|%x|\n", words[i]);
		i++;
	}
	return words;
}

void	md5_hash(t_list *chunks, t_hash *hash)
{
	t_md5v *md5Vr;
	uint32_t words[16];
	uint8_t md[16];
	int j;

	j = 0;
	md5Vr = malloc(sizeof(t_md5v));
	// md5v_init(&md5Vr);
	uint8_t *chunk = chunks->content;
	words = split_32bitwords(words, chunk);
	for(int i = 0; i < 16; i++)
	{

	}
}
	// while(1)
	// {
	// 	j = 0;
	// 	while(j < 16)
	// 	{

	// 	}
	// 	if(!chunks->next)
	// 		break;
	// 	chunks = chunks->next;
	// }

	//proccess the message in successive 512-bit chunks 2 while loops
	//t_uint M[j] M[16]
	// while(j < 16) //while chunks of message still 512bits
	// {
	// 	//here it should 
	// 	a = a0;
	// 	b = b0;
	// 	c = c0;
	// 	d = d0;
	// 	i = 0;
	// 	while(i < 64)
	// 	{
	// 		if(i >= 0 && i < 16)
	// 		{
	// 			f = F_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		else if(i >= 16 && i < 32)
	// 		{
	// 			f = G_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		else if(i >= 32 && i < 48)
	// 		{
	// 			f = H_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		else if(i >= 48 && i < 64)
	// 		{
	// 			f = I_DIG(b,c,d);
	// 			g = i;
	// 		}
	// 		i++;
	// 		f = f + a + k[i] = m[g];
	// 		a = d;
	// 		d = c;
	// 		c = b;
	// 		b = b + R_LEFT(f, s[i]);
	// 	}
	// 	a0 = a0 + a;
	// 	b0 = b0 + b;
	// 	c0 = c0 + c;
	// 	d0 = d0 + d;
	// }


// unsigned int digest[16] = a0 append b0 append c0 append d0;

// return digest;

