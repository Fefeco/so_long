# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:57:02 by fcarranz          #+#    #+#              #
#    Updated: 2024/04/04 09:56:50 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g

MLX_PATH=mlx/
LIBFT_PATH=libft/
LIBFT=-Llibft -l ftprintf
SRC=so_long.c \
	so_long_utils.c \
	map.c
OBJS=$(SRC:%.c=%.o)
INC=mlx

# Link X11 and MLX, and use OpenGL and AppKit
MLX_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
X11_FLAGS=-L/usr/X11/lib -lXext -lX11

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) Makefile so_long.h
	make -C $(LIBFT_PATH) 
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -I$(INC) -o $@

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
