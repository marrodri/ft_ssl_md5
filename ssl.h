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
# include "./libft/ft_printf.h"
# include <fcntl.h>
# include <stdint.h>
# include <string.h>
# define MD5_BYTES	64
# define SHA256		256
# define CI_COM {'r','q','p','s'}
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
# define R_LEFT(F,S) ((F << S) | (F >> (32 - S)))

typedef __uint128_t	t_uint128_t;

typedef struct		s_flag
{
	unsigned int	ci_flags[CI_SZ];
}					t_flag;

typedef struct		s_hash
{
	int				chunk_len;
	t_uint128_t		md_128bit;
	t_uint128_t		*md_256bit;
}					t_hash;

typedef struct		s_md5v
{
	uint32_t		a0;
	uint8_t			output[16]; //this is 128bit all together
}					t_md5v;

typedef	uint8_t		*t_hash_algo(t_list *list);
uint8_t				*md5_hash(t_list *chunks);
int					ft_set_bytes_fd(const int fd, uint32_t bytes, t_list **list);
int					ci_set(char **str, int lim ,int *i, t_flag **flags);
void				ft_lstaddend(t_list **alst, t_list *new);
uint32_t			ft_32bitpad(uint8_t *chunk, int *j);
uint32_t			*split_32bitwords(uint8_t *chunk);
#endif
