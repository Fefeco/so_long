/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:02:33 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/05 20:03:14 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdlib.h>

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define TILE_W 64
# define TILE_H 64

# define EXTENSION ".ber"
# define ERROR_NO_MAP "Debe especificar un archivo de mapa."
# define ERROR_TO_MANY_ARGS "Demasiados argumentos."
# define ERROR_EXTENSION "**ERROR de archivo de mapa. Debe ser extension *.ber"
# define ERROR_MAP_SIZE "**ERROR de mapa. El mapa no es rectangular"
# define ERROR_MAP "**ERROR de mapa"
# define ERROR_STRIPES "**ERROR STRIPES. Cantidad player, coins o exit erronea"
# define ERROR_MOV "**ERROR Movimiento no permitido"

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

typedef struct s_map
{
	char	*filename;
	char	*base_map;
	int		fd;
	int		x;
	int		y;
	int		width;
	int		height;
	int		coins;
	char	*coins_lft;
}	t_map;

typedef struct s_win
{
	void	*connection;
	void	*window;
	int		width;
	int		height;
	//int		coins;
	t_img	player;
	t_back	background;
	t_map	*map;
}	t_win;

#endif

int		exit_program(t_win *game);
t_win	ft_create_window(int width, int height, char *str);
int		ft_movement(t_win *game, int key);
int		ft_load_textures(t_win *game);
int		ft_load_map(t_map *game);
int		ft_check_error(int argc);
int		ft_check_extension(const char *filename, const char *ext);
//void	ft_render_map(t_win *game);
int		ft_render(t_win *game);
//int		ft_render_map_line(char *line);
/*void	li(char *str)
{
	if (!str)
		ft_printf("LINEA AQUI\n");
	else
		ft_printf("LINEA %s\n", str);
}*/
