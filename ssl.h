/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:30:48 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/12 10:30:50 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H
# include "./libft/libft.h"
// # include "Includes/ft_printf/ft_printf.h"
# include <fcntl.h>
# define CI_COM {'p','q','r','s'}
# define HS_COM {"md5", "sha256"}
# define HS_SZ 2
# define CI_SZ 4
# define A0 0x67452301
# define B0	0xefcdab89
# define C0 0x98badcfe
# define D0 0x10325476
# define F_DIG(B,C,D) ((B & C) | ((~B) & D))
# define G_DIG(B,C,D) ((B & D) | (C & (~D)))
# define H_DIG(B,C,D) (B ^ C ^ D)
# define I_DIG(B,C,D) (C ^ (B | (~D)))
# define R_LEFT(F,S) ((F << S) | (S >> (32 - S)))


typedef struct		s_flag
{
	unsigned int	flags[4];
}					t_flag;

typedef struct		s_md5v
{
	unsigned int	A;
	unsigned int	B;
	unsigned int	C;
	unsigned int	D;
}					t_md5v;

typedef struct		s_hash
{
	int		chunks;
	uint8_t	**msg_chunk;
}					t_hash;

// typedef		*hash_funct();

typedef unsigned int t_uint;
void	md5_hash(char *mssg, t_flag *flags);
int		ft_set_bytes(const int fd, int bytes, t_list **list);

#endif

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
