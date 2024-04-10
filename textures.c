/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:05:36 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/10 12:50:09 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_textures(t_win *game)
{
	game->bg.floor = mlx_xpm_file_to_image(game->connection,
			"textures/floor.xpm", &(game->width), &(game->height));
	game->bg.wall = mlx_xpm_file_to_image(game->connection,
			"textures/wall.xpm", &(game->width), &(game->height));
	game->bg.coin = mlx_xpm_file_to_image(game->connection,
			"textures/coin.xpm", &(game->width), &(game->height));
	game->bg.exit = mlx_xpm_file_to_image(game->connection,
			"textures/exit.xpm", &(game->width), &(game->height));
	game->bg.exit_open = mlx_xpm_file_to_image(game->connection,
			"textures/exit_open.xpm", &(game->width), &(game->height));
	game->player.right = mlx_xpm_file_to_image(game->connection,
			"textures/player_right.xpm", &(game->width), &(game->height));
	game->player.up = mlx_xpm_file_to_image(game->connection,
			"textures/player_up.xpm", &(game->width), &(game->height));
	game->player.left = mlx_xpm_file_to_image(game->connection,
			"textures/player_left.xpm", &(game->width), &(game->height));
	game->player.down = mlx_xpm_file_to_image(game->connection,
			"textures/player_down.xpm", &(game->width), &(game->height));
	if (!game->bg.floor || !game->bg.wall || !game->bg.coin
		|| !game->bg.exit || !game->player.right || !game->player.up
		|| !game->player.left || !game->player.down)
		return (perror(ERROR_LOAD_TEX), 1);
	return (0);
}
