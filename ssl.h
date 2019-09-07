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
# define MD5_BYTES		64
# define CI_COM {'r','q','p','s'}
# define HS_COM {"md5", "sha256"}
# define HS_SZ 2
# define CI_SZ 4
# define F_DIG(B,C,D) ((B & C) | ((~B) & D))
# define G_DIG(B,C,D) ((B & D) | (C & (~D)))
# define H_DIG(B,C,D) (B ^ C ^ D)
# define I_DIG(B,C,D) (C ^ (B | (~D)))
# define R_LEFT(F,S) ((F << S) | (F >> (32 - S)))

typedef struct		s_flag
{
	unsigned int	ci_flags[CI_SZ];
}					t_flag;

typedef struct		s_hash
{
	int				chunk_len;
	char			*mssg;
	uint8_t			*mssg_dig;
	uint32_t		a0;
	uint32_t		b0;
	uint32_t		c0;
	uint32_t		d0;
	uint32_t		a_bf;
	uint32_t		b_bf;
	uint32_t		c_bf;
	uint32_t		d_bf;
	uint32_t		g;
	uint32_t		f;
}					t_hash;

typedef struct		s_byte
{
	uint32_t		ret;
	uint8_t			*buff;
	uint32_t		byte_len;
	uint64_t		bit_len;
	uint8_t			*byte512_chunk;
}					t_byte;

typedef struct		s_app
{
	int				input;
	int				fd;
	char			*file;
	char			**av;
	char			*hash_name;
	int				i;
	int				bytes;
}					t_app;

typedef	uint8_t		*t_hash_algo(t_list *list, t_hash *hash_v);
typedef void		*t_puthash(uint8_t *md);
uint8_t				*hash_func(int input, t_list *list, t_hash *hash_v);
int					hash_checker(char *str);
uint8_t				*md5_hash(t_list *chunks, t_hash *hash_v);
uint8_t				*sha256_algo(t_list *list, t_hash *hash_v);
void				set_bytes_fd(const int fd, uint32_t bytes,
	t_list **list, t_hash **hash_v);
void				set_bytes_str(char *str, uint32_t bytes, t_list **list);
int					check_last8bytes(uint8_t *chunk, int bytes);
uint8_t				*ft_append_bytes(uint8_t *chunk, int ret, int bytes);
uint8_t				*ft_append_bitlen(uint8_t *chunk,
	int bytes, uint64_t bit_len);
void				add_new_chunk(t_list **list, uint8_t *chunk, int bytes);
int					ci_set(char **str, int lim, int *i, t_flag **flags);
void				ft_lstaddend(t_list **alst, t_list *new);
uint32_t			ft_32bitpad(uint8_t *chunk, int *j);
uint32_t			*split_32bitwords(uint8_t *chunk);
void				put_hashmd(int input, char *algo, uint8_t *md);
void				s_output(char **argv, t_flag **flags, t_hash **hash_v, int i);
void				p_output(t_flag **flags, t_hash **hash_v);
void				rq_output(char **argv, t_flag **flags,
	t_hash **hash_v, int i);
void				stdin_p_input(t_app *app, t_list *list, t_flag *flags, t_hash *hash_v);
void				str_input(t_app *app, t_list *list, t_hash *hash_v, t_flag *flags);
void				fd_input(t_app *app, t_list *list, t_hash *hash_v, t_flag *flags);
void				put_md5hash(uint8_t *md);
void				free_list(t_list **list);
#endif
