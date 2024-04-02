/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:02:33 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/02 11:20:45 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define WIDTH 600
# define HEIGHT 400

# define ERROR_NO_MAP "Debe especificar un archivo de mapa."
# define ERROR_TO_MANY_ARGS "Demasiados argumentos."
# define EXTENSION ".ber"
# define ERROR_EXTENSION "**ERROR de archivo de mapa. Debe ser extension *.ber"

typedef struct s_img
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*render;
	int		pos_x;
	int		pos_y;
}	t_img;

typedef struct s_back
{
	void	*wall;
	void	*coin;
	void	*floor;
	void	*exit;
	int		width;
	int		height;
}	t_back;

typedef struct s_win
{
	void	*connection;
	void	*window;
	char	*map;
	int		width;
	int		height;
	int		coins;
	t_img	player;
	t_back	background;
}	t_win;

#endif

t_win	ft_create_window(int width, int height, char *str);
int		ft_movement(t_win *game, int key);
int		ft_load_textures(t_win *gamei, char *map);
int		ft_check_error(int argc);
int		ft_render_map(t_win *game);
int		ft_check_extension(const char *filename, const char *ext);
//int		ft_render_map_line(char *line);
