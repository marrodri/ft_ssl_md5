# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 10:21:34 by marrodri          #+#    #+#              #
#    Updated: 2019/08/16 10:21:36 by marrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ssl

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I ./Includes/
CFLAGS += -I ./libft
CFLAGS += -I /Includes/ft_printf/libft
RM = rm -f
HDR = ./Includes/

SRC = ssl_main.c ssl_md5.c set_bytes_fd.c \
	ft_lstaddend.c ssl_ci_set_ch.c ssl_bitlen.c\
	ssl_hash_algo.c ssl_sha256.c ssl_sha256ft.c\
	set_bytes_str.c ssl_inputs.c ssl_list.c\
	ssl_bit_op.c ssl_put_hash.c ssl_output.c\
	ssl_sha224.c ssl_sha1.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@ -g
 
$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all


# use this for windows
# gcc -lft -L./libft ssl_main.c get_next_bytes.c ft_lstaddend.c ./libft/ft_lstnew.c ./libft/ft_memcpy.c