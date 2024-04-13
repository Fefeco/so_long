/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:02:33 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/13 13:48:44 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>

# ifdef __APPLE__
#  define ESC 53
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
# else
#  define ESC 65307
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
# endif

# define TILE_W 64
# define TILE_H 64
# define EXTENSION ".ber"

# define ERROR_EXTENSION "Erro\nMapa debe ser extension *.ber"
# define ERROR_NO_MAP "Error\nDebe especificar un archivo de mapa."
# define ERROR_FILE "Error\nAbriendo archivo de mapa."
# define ERROR_TO_MANY_ARGS "ERROR\nDemasiados argumentos."
# define ERROR_MAP_SIZE "Error\nEl mapa no es rectangular"
# define ERROR_MAP "Error\nMapa"
# define ERROR_WALLS "Error\nMapa debe estar rodeado de paredes"
# define ERROR_STRIPES "ERROR\nCantidad player, coins, enemy o exit erronea"
# define ERROR_INVALID_CHAR "ERROR\nCaracter invalido en mapa"
# define ERROR_NO_PATH "ERROR\nNo hay camino posible"
# define ERROR_LOAD_TEX "ERROR\nCargando texturas"
# define ERROR_CONNECTION "ERROR\nFallo la conexion con el servidor X"
# define ERROR_MOV "ERROR\nMovimiento no permitido"
# define ERROR_EXIT "ERROR\nAun quedan coins por recoger!"
# define ERROR_TOUCHED_ENEMY "ERROR\nTocaste un enemigo. JUEGO TERMINADO!"
# define WIN "HAS GANADO!!"

typedef struct s_total_sprites
{
	int	exit;
	int	player;
	int	coins;
	int	enemys;
}	t_spr;

typedef struct s_check_path
{
	int	coins;
	int	exit;
	int	valid;
	int	*visited;
}	t_chpath;

typedef struct s_imgage
{
	void	**up;
	void	**down;
	void	**left;
	void	**right;
	void	**render;
	int		pos_x;
	int		pos_y;
}	t_img;

typedef struct s_background
{
	void	*wall;
	void	*coin;
	void	*floor;
	void	*exit;
	void	*exit_open;
	int		width;
	int		height;
}	t_bg;

typedef struct s_map
{
	char		*filename;
	char		*base_map;
	int			fd;
	int			x;
	int			y;
	int			width;
	int			height;
	char		*coins_lft;
	t_chpath	chpath;
	t_spr		spr;
}	t_map;

typedef struct s_window
{
	void	*connection;
	void	*window;
	int		width;
	int		height;
	int		coins;
	int		movements;
	t_img	player;
	t_img	enemy;
	t_bg	bg;
	t_map	*map;
}	t_win;

int		exit_program(t_win *game);
t_win	ft_create_window(int width, int height, char *str);
void	ft_movement(t_win *game, int key);
int		ft_load_textures(t_win *game);
int		ft_load_map(t_map *game);
int		ft_check_extension(const char *filename, const char *ext);
int		ft_render(t_win *game);
int		ft_find_player(t_map *map);
void	*ft_switch_img(void **img);
void	*ft_switch_img_2(void **img);

#endif
