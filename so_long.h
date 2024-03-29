/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:02:33 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/29 13:53:14 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

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
	int		width;
	int		height;
	int		coins;
	img_t	player;
	back_t	background;
} win_t;

#endif

win_t	ft_create_window(int width, int height, char *str);
int		ft_movement(win_t *game, int key);
int		ft_load_textures(win_t *game);

