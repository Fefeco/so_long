/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:05:36 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/13 12:58:52 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	**ft_load_player_right(t_win *game)
{
	void	**tmp;

	tmp = malloc(sizeof(void *) * 5);
	if (!tmp)
		return (NULL);
	tmp[0] = mlx_xpm_file_to_image(game->connection,
			"textures/player_right_0.xpm", &(game->width), &(game->height));
	tmp[1] = mlx_xpm_file_to_image(game->connection,
			"textures/player_right_1.xpm", &(game->width), &(game->height));
	tmp[2] = mlx_xpm_file_to_image(game->connection,
			"textures/player_right_2.xpm", &(game->width), &(game->height));
	tmp[3] = mlx_xpm_file_to_image(game->connection,
			"textures/player_right_3.xpm", &(game->width), &(game->height));
	tmp[4] = NULL;
	return (tmp);
}

static void	**ft_load_player_left(t_win *game)
{
	void	**tmp;

	tmp = malloc(sizeof(void *) * 5);
	if (!tmp)
		return (NULL);
	tmp[0] = mlx_xpm_file_to_image(game->connection,
			"textures/player_left_0.xpm", &(game->width), &(game->height));
	tmp[1] = mlx_xpm_file_to_image(game->connection,
			"textures/player_left_1.xpm", &(game->width), &(game->height));
	tmp[2] = mlx_xpm_file_to_image(game->connection,
			"textures/player_left_2.xpm", &(game->width), &(game->height));
	tmp[3] = mlx_xpm_file_to_image(game->connection,
			"textures/player_left_3.xpm", &(game->width), &(game->height));
	tmp[4] = NULL;
	return (tmp);
}

static void	**ft_load_player_up(t_win *game)
{
	void	**tmp;

	tmp = malloc(sizeof(void *) * 5);
	if (!tmp)
		return (NULL);
	tmp[0] = mlx_xpm_file_to_image(game->connection,
			"textures/player_up_0.xpm", &(game->width), &(game->height));
	tmp[1] = mlx_xpm_file_to_image(game->connection,
			"textures/player_up_1.xpm", &(game->width), &(game->height));
	tmp[2] = mlx_xpm_file_to_image(game->connection,
			"textures/player_up_2.xpm", &(game->width), &(game->height));
	tmp[3] = mlx_xpm_file_to_image(game->connection,
			"textures/player_up_3.xpm", &(game->width), &(game->height));
	tmp[4] = NULL;
	return (tmp);
}

static void	**ft_load_player_down(t_win *game)
{
	void	**tmp;

	tmp = malloc(sizeof(void *) * 5);
	if (!tmp)
		return (NULL);
	tmp[0] = mlx_xpm_file_to_image(game->connection,
			"textures/player_down_0.xpm", &(game->width), &(game->height));
	tmp[1] = mlx_xpm_file_to_image(game->connection,
			"textures/player_down_1.xpm", &(game->width), &(game->height));
	tmp[2] = mlx_xpm_file_to_image(game->connection,
			"textures/player_down_2.xpm", &(game->width), &(game->height));
	tmp[3] = mlx_xpm_file_to_image(game->connection,
			"textures/player_down_3.xpm", &(game->width), &(game->height));
	tmp[4] = NULL;
	return (tmp);
}

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
	game->player.right = ft_load_player_right(game);
	game->player.left = ft_load_player_left(game);
	game->player.up = ft_load_player_up(game);
	game->player.down = ft_load_player_down(game);
	game->enemy.render = ft_load_enemy(game);
	if (!game->bg.floor || !game->bg.wall || !game->bg.coin
		|| !game->bg.exit || !game->player.right || !game->player.up
		|| !game->player.left || !game->player.down)
		return (perror(ERROR_LOAD_TEX), 1);
	return (0);
}
