# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 09:57:02 by fcarranz          #+#    #+#              #
#    Updated: 2024/05/30 21:40:31 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=gcc
CFLAGS=-Wall -Werror -Wextra -MMD

ifeq ($(shell uname), Linux)
	MLX_FLAGS=-Lmlx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 
	MLX_PATH=mlx-linux 
	INC=-Imlx-linux
else
	MLX_FLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
	MLX_PATH=mlx
	INC=-Imlx
endif

LIBFT_PATH=libft/
LIBFT=-Llibft -l ftprintf
OBJ_PATH=objs/
OBJ_BONUS_PATH=objs_bonus/
DEP_PATH=deps/
SRC=so_long.c \
	so_long_utils.c \
	map.c \
	render.c \
	textures.c \
	movement.c
SRC_BONUS=so_long_bonus.c \
	so_long_utils.c \
	so_long_utils_bonus.c \
	map_bonus.c \
	render_bonus.c \
	textures_bonus.c \
	movement_bonus.c

OBJS=$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))
OBJS_BONUS=$(patsubst %.c, $(OBJ_BONUS_PATH)%.o, $(SRC_BONUS))
DEPS=$(patsubst %.c, $(OBJ_PATH)%.d, $(SRC))
DEPS_BONUS=$(patsubst %.c, $(OBJ_BONUS_PATH)%.d, $(SRC_BONUS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) Makefile so_long.h
	@make -C $(LIBFT_PATH) > /dev/null 
	@make -C $(MLX_PATH) &> /dev/null
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(INC) -o $@

bonus: $(OBJS_BONUS) Makefile so_long_bonus.h
	make -C $(LIBFT_PATH) 
	make -C $(MLX_PATH) &> /dev/null
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) $(INC) -o $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(OBJ_PATH) $(DEP_PATH)
	$(CC) $(CFLAGS) -Imlx -I libft/inc -c $< -o $@
	@mv $(OBJ_PATH)*.d $(DEP_PATH)

$(OBJ_BONUS_PATH)%.o: %.c
	@mkdir -p $(OBJ_BONUS_PATH) $(DEP_PATH)
	$(CC) $(CFLAGS) -Imlx -I libft/inc -c $< -o $@
	@mv $(OBJ_BONUS_PATH)*.d $(DEP_PATH)

clean:
	@make clean -C $(LIBFT_PATH) > /dev/null
	@make clean -C $(MLX_PATH) > /dev/null
	rm -rf $(OBJ_PATH) $(OBJ_BONUS_PATH) $(DEP_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH) > /dev/null
	rm -f $(NAME)

-include $(DEPS) $(DEPS_BONUS)

re: fclean all
