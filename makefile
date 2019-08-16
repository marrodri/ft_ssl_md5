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

RM = rm -f

SRC = ssl_main.c ssl_md5.c

HDR = ./includes/

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME):
