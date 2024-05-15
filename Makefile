# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:56:58 by akeldiya          #+#    #+#              #
#    Updated: 2024/05/14 11:37:01 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
SRCS	= main.c	sources/mapchecker.c	sources/errors.c \
		sources/mapchecker_utils.c	sources/errors2.c

# Sources and objects
OBJS	:= $(SRCS:%.c=%.o)

# Constant strings

NAME	= so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

INCLULIBFT = -Ilibft
INCLUDEMLX = -Iminilibx-linux

# Rules

all: $(NAME)

%.o:	%.c
		${CC} ${CFLAGS} $(INCLULIBFT) $(INCLUDEMLX) -c $< -o $@

$(NAME): $(OBJS) libft mlx
	$(CC) $(CFLAGS) $(INCLULIBFT) $(INCLUDEMLX) -o $(NAME) $(OBJS) -Llibft -lft -Lminilibx

libft:
	make -C libft

mlx:
	make -C minilibx-linux

clean:
	make clean -C libft
	make -C minilibx-linux
	cd minilibx-linux && make clean
	${RM} ${OBJS}

fclean:		clean
	make fclean -C libft
	${RM} $(NAME)

re: fclean all

.PHONY:	 all clean fclean re libft mlx
