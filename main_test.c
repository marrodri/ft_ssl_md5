/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:41:17 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/27 15:41:19 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

//check header for the exact numbers
//md5 keys and loops
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

// int	main(void)
// {
// 	uint32_t test[64];
// 	const uint32_t key[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
// 			0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
// 			0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
// 			0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
// 			0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
// 			0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
// 			0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
// 			0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
// 			0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
// 			0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
// 			0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
// 			0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
// 			0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
// 			0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
// 			0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
// 			0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

// 	return (0);
// }

//TODO files to keep for printf
//ft_llitoa_base;
//ft_ullitoa_base;
//ft_strupper;
//ft_strsub;
//ft_strjoin;
//ft_swap_charstr;
//ft_strnewc;
//ft_strlen;
//ft_atoi;
//ft_ldtoa;

//inside printf libft, files to keep