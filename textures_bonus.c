/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:05:36 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/10 21:15:39 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*int	ft_load_player(game)
{
	int		i;
	char	*file;

	i = 0;
	while (i < 4)
	{
		nb = ft_itoa(i);
		file = ft_strjoin("textures/player_right_", nb);
		file = ft_strjoin(file, ".xpm");
		game->player.right[i] = mlx_xpm_file_to_image(game->connection,
			file, &(game->width), &(game->height));
		free (file);
		free (nb);
	}
}*/

int	ft_load_array(t_win *game, void **array, char *file, int len)
{
	int		i;
	char	*nb;
	char	*tmp;

	i = 0;
	while (i < len)
	{
		ft_printf("ITERO: %d\n", i);
		nb = ft_itoa(i);
		tmp = ft_strjoin(ft_strdup(file), nb);
		tmp = ft_strjoin(ft_strdup(tmp), ft_strdup(".xpm"));
		ft_printf("ARCHIVO: %s\n", tmp);
		array[i] = mlx_xpm_file_to_image(game->connection,
			file, &(game->width), &(game->height));
		free (tmp);
//		free (nb);
//		if (array[i] == NULL)
//			return (1);
		++i;
	}
	array[i] = NULL;
	return (0);
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
	game->player.right = malloc(sizeof(void *) * 5);
/*	game->player.down = malloc(sizeof(void *) * 5);
	game->player.up = malloc(sizeof(void *) * 5);
	game->player.left = malloc(sizeof(void *) * 5);*/
	ft_load_array(game, game->player.right, "textures/player_right_", 4);
/*	ft_load_array(game, game->player.down, "textures/player_down_", 4);
	ft_load_array(game, game->player.up, "textures/player_up_", 4);
	ft_load_array(game, game->player.left, "textures/player_left_", 4);*/
/*	if (!game->bg.floor || !game->bg.wall || !game->bg.coin
		|| !game->bg.exit || !game->player.right || !game->player.up
		|| !game->player.left || !game->player.down)
		return (perror(ERROR_LOAD_TEX), 1);*/
	return (0);
}
