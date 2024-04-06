/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:00:39 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/06 12:39:36 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_specials(t_win *game, char map_pos, int x, int y, int i)
{
	if(map_pos == 'C')
		mlx_put_image_to_window(game->connection, game->window, 
				game->background.coin, x * TILE_W, y * TILE_H);
	if (map_pos == '1')
		mlx_put_image_to_window(game->connection, game->window, 
				game->background.wall, x * TILE_W, y * TILE_H);
	if (map_pos == 'E')
		mlx_put_image_to_window(game->connection, game->window, 
				game->background.exit, x * TILE_W, y * TILE_H);
	if (map_pos == 'P')
	{
		game->player.pos_x = x * TILE_W;
		game->player.pos_y = y * TILE_H;
		game->map->base_map[i] = '0';
	}
}
void	ft_render_map(t_win *game)
{
	int		y;
	int		x;
	int		i;
	char	map_pos;

	y = 0;
	i = 0;
	while(y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			map_pos = game->map->base_map[i];
			if (ft_strchr("0PC", map_pos))
				mlx_put_image_to_window(game->connection, game->window, 
						game->background.floor, x * TILE_W, y * TILE_H);
			if (ft_strchr("C1EP", map_pos))
				ft_render_specials(game, map_pos, x, y, i);
			++x;
			++i;
		}
		++y;
	}
}

int	ft_render(t_win *game)
{
	char	*coins;
	char	*mov;

	coins = ft_strjoin(ft_strdup("COINS LEFT: "), ft_itoa(game->map->coins));
	mov = ft_strjoin(ft_strdup("MOVEMENTS: "), ft_itoa(game->movements));
	mlx_clear_window(game->connection, game->window);
	ft_render_map(game);
	mlx_put_image_to_window(game->connection, game->window, 
			game->player.render, game->player.pos_x, game->player.pos_y);
	mlx_string_put(game->connection, game->window, game->map->width * 0.4, 
			game->map->height * 0.9 , 0xFF99FF, coins);
	mlx_string_put(game->connection, game->window,game->map->width * 0.4, 
			game->map->height * 0.85 , 0xFF99FF,mov);
	free (coins);
	free (mov);
	return (0);
}
