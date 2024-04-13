/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:05:36 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/13 13:47:37 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	**ft_load_imgs(t_win *game, char *path, char *ext, int len)
{
	void	**tmp;
	char	*file;

	tmp = malloc(sizeof(void *) * len);
	if (!tmp)
		return (NULL);
	tmp[--len] = NULL;
	while (len--)
	{
		file = ft_strjoin(ft_strdup(path), ft_itoa(len));
		file = ft_strjoin(file, ft_strdup(ext));
		tmp[len] = mlx_xpm_file_to_image(game->connection,
				file, &(game->width), &(game->height));
		free (file);
	}
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
	game->player.right = ft_load_imgs(game, "textures/player_right_",
			".xpm", 5);
	game->player.left = ft_load_imgs(game, "textures/player_left_",
			".xpm", 5);
	game->player.up = ft_load_imgs(game, "textures/player_up_", ".xpm", 5);
	game->player.down = ft_load_imgs(game, "textures/player_down_",
			".xpm", 5);
	game->enemy.render = ft_load_imgs(game, "textures/enemy_", ".xpm", 5);
	if (!game->bg.floor || !game->bg.wall || !game->bg.coin
		|| !game->bg.exit || !game->player.right || !game->player.up
		|| !game->player.left || !game->player.down)
		return (perror(ERROR_LOAD_TEX), 1);
	return (0);
}
