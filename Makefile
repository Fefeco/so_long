# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:57:02 by fcarranz          #+#    #+#              #
#    Updated: 2024/03/27 11:34:22 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
CFLAGS=-Wall -Werror -Wextra
NAME=so_long
OBJS=so_long.o
MLX_PATH=mlx/

# Link X11 and MLX, and use OpenGL and AppKit
MLX_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
X11_FLAGS=-L/usr/X11/lib -lXext -lX11

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	make clean -C $(MLX_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
