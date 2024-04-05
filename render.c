/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:00:39 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/05 21:27:25 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_textures(t_win *game)
{
	game->background.floor = mlx_xpm_file_to_image(game->connection, 
			"img/floor.xpm", 
			&(game->width), 
			&(game->height));

	game->background.wall = mlx_xpm_file_to_image(game->connection, 
			"img/wall.xpm", 
			&(game->width), 
			&(game->height));

	game->background.coin = mlx_xpm_file_to_image(game->connection, 
			"img/coin.xpm", 
			&(game->width), 
			&(game->height));

	game->background.exit = mlx_xpm_file_to_image(game->connection, 
			"img/exit.xpm", 
			&(game->width), 
			&(game->height));

	game->player.right = mlx_xpm_file_to_image(game->connection, 
			"img/player_right.xpm", 
			&(game->width), 
			&(game->height));

	game->player.up = mlx_xpm_file_to_image(game->connection, 
			"img/player_up.xpm", 
			&(game->width), 
			&(game->height));
	
	game->player.left = mlx_xpm_file_to_image(game->connection, 
			"img/player_left.xpm", 
			&(game->width), 
			&(game->height));
	
	game->player.down = mlx_xpm_file_to_image(game->connection, 
			"img/player_down.xpm", 
			&(game->width), 
			&(game->height));
	return (0);
}

void	ft_render_map(t_win *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	ft_printf("MAP: %s\nMovements :%d\n", game->map->base_map, game->movements);
	while(y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			if (game->map->base_map[i] == '0' || game->map->base_map[i] == 'P'
					|| game->map->base_map[i] == 'C')
			{
				mlx_put_image_to_window(game->connection, 
						game->window, 
						game->background.floor, x * TILE_W, y * TILE_H);
		//		ft_printf("X = %d | Y = %d | I = %d | x = %d | y = %d\n", x, y, i, TILE_W * x, TILE_H * y);
			}
			if (game->map->base_map[i] == 'P')
			{
				game->player.pos_x = x * TILE_W;
				game->player.pos_y = y * TILE_H;
				game->map->base_map[i] = '0';
			}

			if(game->map->base_map[i] == 'C')
			{
				mlx_put_image_to_window(game->connection, 
						game->window, 
						game->background.coin, x * TILE_W, y * TILE_H);
			}
			if (game->map->base_map[i] == '1')
			{
				mlx_put_image_to_window(game->connection, 
						game->window, 
						game->background.wall, x * TILE_W, y * TILE_H);
			}
			if (game->map->base_map[i] == 'E')
			{
				mlx_put_image_to_window(game->connection, 
						game->window, 
						game->background.exit, x * TILE_W, y * TILE_H);
			}
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

	mlx_put_image_to_window(game->connection, game->window, game->player.render, game->player.pos_x, game->player.pos_y);

	mlx_string_put(game->connection, 
			game->window, 
			game->map->width * 0.4, 
			game->map->height * 0.9 , 
			0xFF99FF, 
			coins);
	mlx_string_put(game->connection, 
			game->window, 
			game->map->width * 0.4, 
			game->map->height * 0.85 , 
			0xFF99FF, 
			mov);
	return (free (coins), free (mov), 0);
}
