# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:57:02 by fcarranz          #+#    #+#              #
#    Updated: 2024/03/28 14:01:23 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=so_long
MLX_PATH=mlx/
SRC=so_long.c \
	utils.c
OBJS=$(SRC:%.c=%.o)
INC=mlx

# Link X11 and MLX, and use OpenGL and AppKit
MLX_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
X11_FLAGS=-L/usr/X11/lib -lXext -lX11

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -I$(INC) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	make clean -C $(MLX_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
