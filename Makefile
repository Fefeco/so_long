# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:57:02 by fcarranz          #+#    #+#              #
#    Updated: 2024/04/08 13:05:25 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g

ifeq ($(shell uname), Linux)
	MLX_FLAGS=-Lmlx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 
else
	MLX_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
endif

ifeq ($(shell uname), Linux)
	MLX_PATH=mlx-linux 
	INC=-Imlx-linux
else
	MLX_PATH=mlx
	INC=-Imlx
endif

#MLX_PATH=mlx/
LIBFT_PATH=libft/
LIBFT=-Llibft -l ftprintf
SRC=so_long.c \
	so_long_utils.c \
	map.c \
	render.c \
	algorithm.c \
	movement.c
OBJS=$(SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) Makefile so_long.h
	make -C $(LIBFT_PATH) 
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(INC) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I libft/inc -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all
