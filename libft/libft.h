/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:14:37 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/21 16:33:29 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1
# define LLI long long int
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef long long int	t_lli;

char				*ft_strdup(char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strstr(char *str, char *to_find);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(char *str);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, const char *src, size_t nb);
size_t				ft_strlcat(char *dest, char *src, size_t size);
void				*ft_memset(void *b, int c, unsigned int len);
void				ft_bzero(void *s, unsigned int n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
void				*ft_memmove(void *dst, const void *src, size_t n);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_print_bits(unsigned char octet);
unsigned char		reverse_bits(unsigned char octet);
unsigned char		swap_bits(unsigned char octet);
int					ft_word_count(char const *s, char c);
int					get_next_line(const int fd, char **line);
int					ft_power_of(int n, int expo);
char				*ft_int_to_hex(int n);
int					ft_dec_to_oct(int n);
char				*ft_strupper(char *str);
char				*ft_itoa_base(int value, int base);
char				*ft_llitoa_base(long long int value, int base);
char				*ft_uitoa(unsigned int n);
char				*ft_ullitoa_base(unsigned long long int value, int base);
char				*ft_strnewc(char f, int size);
char				*ft_swap_charstr(char *fstr, char c, int pos);
int					ft_strischar(char *str, char c);
long long int		ft_libaselen(long long int n, int base, int f_flag);
long long int		ft_llideduct(long long int num);
long long int		ft_power_of_lli(long long int n, long long int expo);
char				*ft_ldtoa(long double ld_num, int prec);
#endif


// abcdefghjklzxcvb.,.fdfdfdfddffdfdfdfdfferfrfrf

//32byte len changes
// abcdefghjklzxcvb.,.fdfdfdf12QW12