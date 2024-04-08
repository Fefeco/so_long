/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:01:32 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/08 09:37:33 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_win *game)
{
	if (game)
		mlx_destroy_window(game->connection, game->window);
	exit(EXIT_FAILURE);
}

t_win	ft_create_window(int width, int height, char *str)
{
	t_win	game;

	game.connection = mlx_init();
	if (!game.connection)
		return (perror(ERROR_CONNECTION), game);
	game.window = mlx_new_window(game.connection, width, height, str);
	game.width = width;
	game.height = height;
	return (game);
}

int	ft_load_textures(t_win *game)
{
	game->bg.floor = mlx_xpm_file_to_image(game->connection,
			"img/floor.xpm", &(game->width), &(game->height));
	game->bg.wall = mlx_xpm_file_to_image(game->connection,
			"img/wall.xpm", &(game->width), &(game->height));
	game->bg.coin = mlx_xpm_file_to_image(game->connection,
			"img/coin.xpm", &(game->width), &(game->height));
	game->bg.exit = mlx_xpm_file_to_image(game->connection,
			"img/exit.xpm", &(game->width), &(game->height));
	game->bg.exit_open = mlx_xpm_file_to_image(game->connection,
			"img/exit_open.xpm", &(game->width), &(game->height));
	game->player.right = mlx_xpm_file_to_image(game->connection,
			"img/player_right.xpm", &(game->width), &(game->height));
	game->player.up = mlx_xpm_file_to_image(game->connection,
			"img/player_up.xpm", &(game->width), &(game->height));
	game->player.left = mlx_xpm_file_to_image(game->connection,
			"img/player_left.xpm", &(game->width), &(game->height));
	game->player.down = mlx_xpm_file_to_image(game->connection,
			"img/player_down.xpm", &(game->width), &(game->height));
	if (!game->bg.floor || !game->bg.wall || !game->bg.coin
		|| !game->bg.exit || !game->player.right || !game->player.up
		|| !game->player.left || !game->player.down)
		return (perror(ERROR_LOAD_TEX), 1);
	return (0);
}

int	ft_check_extension(const char *filename, const char *ext)
{
	int	len_ext;
	int	len_fname;

	if (!filename || !ext)
		return (perror(ERROR_MAP), 1);
	len_ext = ft_strlen(ext);
	len_fname = ft_strlen(filename);
	if (ft_strncmp(filename + (len_fname - len_ext), ext, len_ext))
		return (perror(ERROR_EXTENSION), 1);
	return (0);
}
