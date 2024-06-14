# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:56:58 by akeldiya          #+#    #+#              #
#    Updated: 2024/06/14 21:15:53 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
SRCS	= main.c	sources/mapchecker.c	sources/errors.c \
		sources/mapchecker_utils.c	sources/errors2.c	sources/open_free.c \
		sources/maplen.c

# Sources and objects
OBJS	:= $(SRCS:%.c=%.o)

# Constant strings

NAME	= so_long

CC = gcc

CFLAGS = -g #-Wall -Wextra -Werror

RM = rm -f

INCLULIBFT = -Ilibft
LIBFTFLAGS = $(INCLULIBFT) -Llibft -lft
INCLUDEMLX = -I/usr/include -Imlx-linux
MLXFLAGS = $(INCLUDEMLX) -Lmlx-linux -lmlx -lX11 -lXext -L/usr/lib/X11

# Rules

all: $(NAME)

%.o:	%.c
		${CC} ${CFLAGS} -c -o $@ $< $(INCLULIBFT) $(INCLUDEMLX)

$(NAME): $(OBJS) libft mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS)

libft:
	make -C libft

mlx:
	make -C mlx-linux

clean:
	make clean -C libft
	make clean -C mlx-linux
	${RM} ${OBJS}

fclean:		clean
	make fclean -C libft
	${RM} $(NAME)

re: fclean all

.PHONY:	 all clean fclean re libft mlx