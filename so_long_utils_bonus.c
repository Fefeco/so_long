/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:01:32 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/11 13:50:04 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_array(void **array, int len)
{
	while (len >= 0)
		free(array[len--]);
}

int	exit_program(t_win *game)
{
	/*if(game->player.right)
	{
		ft_free_array(game->player.right, 4);
		free (game->player.right);
	}*/
	if(game->player.up)
		free (game->player.up);
	/*if(game->player.down)
		ft_free_array(game->player.down, 4);
	if(game->player.left)
		ft_free_array(game->player.left, 4);*/
	if (game)
		mlx_destroy_window(game->connection, game->window);
	exit(EXIT_FAILURE);
}

int	ft_find_player(t_map *map)
{
	int	i;

	i = 0;
	while (map->base_map[i] != 'P')
		++i;
	return (i);
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
