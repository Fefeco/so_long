/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:02:33 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/30 10:59:53 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef WIDTH
# define WIDTH 600
#endif

#ifndef HEIGHT
# define HEIGHT 400
#endif

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ERROR_NO_MAP "Debe especificar un archivo de mapa."
# define ERROR_TO_MANY_ARGS "Demasiados argumentos."

typedef struct img_s {
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*render;
	int		pos_x;
	int		pos_y;
} img_t;

typedef struct back_s {
	void	*wall;
	void	*coin;
	void	*floor;
	void	*exit;
	int		width;
	int		height;
} back_t;

typedef	struct win_s {
	void	*connection;
	void	*window;
	char	*map;
	int		width;
	int		height;
	int		coins;
	img_t	player;
	back_t	background;
} win_t;

#endif

win_t	ft_create_window(int width, int height, char *str);
int		ft_movement(win_t *game, int key);
int		ft_load_textures(win_t *gamei, char *map);
int		ft_check_error(int argc);
int		ft_render_map(win_t *game);
int		ft_render_map_line(char *line);
