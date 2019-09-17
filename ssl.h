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
# define HS_COM {"md5", "sha256", "sha224", "sha1"}
# define HS_SZ 4
# define CI_SZ 4
# define F_DIG(B,C,D) ((B & C) | ((~B) & D))
# define G_DIG(B,C,D) ((B & D) | (C & (~D)))
# define H_DIG(B,C,D) (B ^ C ^ D)
# define I_DIG(B,C,D) (C ^ (B | (~D)))
# define J_DIG(B,C,D) ((B & C) | (B & D) | (C & D))
# define ROT_LEFT(F,S) ((F << S) | (F >> (32 - S)))
# define ROT_RIGHT(F,S) ((F >> S) | (F << (32 - S)))

# define SSIG0(x) ((ROT_RIGHT(x, 7)) ^ (ROT_RIGHT(x, 18)) ^ (x >> 3))
# define SSIG1(x) ((ROT_RIGHT(x, 17)) ^ (ROT_RIGHT(x, 19)) ^ (x >> 10))

# define CH(E,F,G) ((E & F) ^ ((~E) & G))
# define MAJ(A,B,C) ((A & B) ^ (A & C) ^ (B & C))

# define BSIG1(x) ((ROT_RIGHT(x, 6)) ^ (ROT_RIGHT(x, 11)) ^ (ROT_RIGHT(x, 25)))
# define BSIG0(x) ((ROT_RIGHT(x, 2)) ^ (ROT_RIGHT(x, 13)) ^ (ROT_RIGHT(x, 22)))

typedef struct		s_flag
{
	unsigned int	ci_flags[CI_SZ];
}					t_flag;

typedef struct		s_hash
{
	int			chunk_len;
	char		*mssg;
	uint8_t		*mssg_dig;
	uint32_t	*h0;
	uint32_t	*h_bf;
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	uint32_t	k;
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	tmp1;
	uint32_t	tmp2;
	uint32_t	maj;
	uint32_t	ch;
}					t_hash;

typedef struct		s_app
{
	int			input;
	int			fd;
	char		*file;
	char		**av;
	char		*hash_name;
	int			i;
	int			bytes;
}					t_app;

typedef	struct		s_lstcon
{
	uint8_t		*buff;
	uint32_t	byte_len;
	uint64_t	bit_len;
	uint8_t		*tmp;
}					t_lstcon;

typedef	uint8_t 	*t_hash_ft(t_list *list, t_hash *hash_v);
typedef uint8_t		*t_bitlen_ft(uint8_t *chunk, int bytes, uint64_t bit_len);

typedef	struct	s_table
{
	char			*hash_name;
	t_hash_ft		*hash_ft;
	t_bitlen_ft		*bitlen_ft;
	uint32_t		bytes;
}				t_table;

typedef	uint8_t		*t_hash_algo(t_list *list, t_hash *hash_v);
typedef uint8_t		*t_bitlen_app(uint8_t *chunk, int bytes, uint64_t bit_len);
typedef int			*t_puthash(uint8_t *md);
uint8_t				*hash_func(int input, t_list *list, t_hash *hash_v);
int					hash_checker(char *str);
uint64_t			byte_length(uint64_t val);
uint8_t				*md5_hash(t_list *chunks, t_hash *hash_v);
uint8_t				*sha1_hash(t_list *chunks, t_hash *hash_v);
uint8_t				*sha256_hash(t_list *list, t_hash *hash_v);
uint8_t				*sha224_hash(t_list *chunks, t_hash *hash_v);
void				*ft_append_224bit(uint32_t *input);
uint32_t			*set_w_bf(uint8_t *chunk);
void				*ft_append_256bit(uint32_t *input);
void				set_bytes_fd(t_app *app, t_list **list, t_hash **hash_v);
void				set_bytes_str(t_app *app, char *str, t_list **list);
int					check_last8bytes(uint8_t *chunk, int bytes);
uint8_t				*ft_append_bytes(uint8_t *chunk, int ret, int bytes);
u_int8_t			*bitlen_tb(int input, uint8_t *chunk,
	int bytes, uint64_t bit_len);
uint8_t				*app_bitlen_md5(uint8_t *chunk, int bytes,
	uint64_t bit_len);
uint8_t				*app_bitlen_sha256(uint8_t *chunk,
	int bytes, uint64_t bit_len);
void				add_new_chunk(t_list **list, uint8_t *chunk, int bytes);
void				ft_lstaddend(t_list **alst, t_list *new);
void				free_list(t_list **list);
void				init_varlst(t_lstcon **lst_v, uint32_t bytes);
int					ci_set(char **str, int lim, int *i, t_flag **flags);
void				stdin_p_input(t_app *app, t_list *list,
	t_flag *flags, t_hash *hash_v);
void				str_input(t_app *app, t_list *list,
	t_hash *hash_v, t_flag *flags);
void				fd_input(t_app *app, t_list *list,
	t_hash *hash_v, t_flag *flags);
// void				put_hashmd(int input, uint8_t *md);
void		put224hash(uint8_t *md);
void		put256hash(uint8_t *md);
void		put_md5hash(uint8_t *md);
void				s_output(t_list *list, t_flag **flags,
	t_hash **hash_v, t_app *app);
void				p_output(t_list *list, t_flag **flags, t_hash **hash_v, t_app *app);
void				rq_output(t_list *list, t_flag **flags, t_hash **hash_v, t_app *app);

// const t_table	data[] = {
// 	//name, function, bytes;
// 	{"md5", md5_hash, app_bitlen_md5, 64},
// 	{"sha256", sha256_hash, app_bitlen_sha256, 64},
// 	{"sha224", sha224_hash, app_bitlen_sha256, 64},
// 	{"sha1", sha1_hash, app_bitlen_sha256, 64},
// };

#endif
