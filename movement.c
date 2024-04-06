/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:11:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/06 11:18:30 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_movement(t_win *game)
{
	int		player_pos;
	int		y;
	int		x;
	char	map_pos;

	y = game->player.pos_y / TILE_H;
	x = game->player.pos_x / TILE_W;
	player_pos = x + (y * game->map->x);
	map_pos = game->map->base_map[player_pos];
	if (map_pos == '1')
		return (perror(ERROR_MOV), 1);
	else if (map_pos == 'C')
	{
		game->map->base_map[player_pos] = '0';
		--game->map->coins;
	}
	else if (map_pos == 'E')
	{
		if (game->map->coins != 0)
			return (perror(ERROR_EXIT), 1);
		ft_printf("%s\n", WIN);
		exit_program(game);
	}
	++game->movements;
	return (0);
}

int	ft_movement(t_win *game, int key)
{
	ft_printf("UP: %d\nDOWN: %d\nLEFT: %d\nRIGHT: %d\n", UP, DOWN, LEFT, RIGHT);
	if (key == UP)
	{
		game->player.pos_y -= TILE_H;
		game->player.render = game->player.up;
		if (ft_validate_movement(game))
			game->player.pos_y += TILE_H;
	}
	else if (key == DOWN)
	{
		game->player.pos_y += TILE_H;
		game->player.render = game->player.down;
		if (ft_validate_movement(game))
			game->player.pos_y -= TILE_H;
	}
	else if (key == RIGHT)
	{
		game->player.pos_x += TILE_W;
		game->player.render = game->player.right;
		if (ft_validate_movement(game))
			game->player.pos_x -= TILE_W;
	}
	else if (key == LEFT)
	{
		game->player.pos_x -= TILE_W;
		game->player.render = game->player.left;
		if (ft_validate_movement(game))
			game->player.pos_x += TILE_W;
	}
	ft_render(game);
	return (0);
}
