/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:11:28 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/13 12:57:13 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_touched_enemy(t_win *game)
{
	perror(ERROR_TOUCHED_ENEMY);
	free (game->map->base_map);
	exit_program(game);
}

static void	ft_collect_coin(t_win *game, int player_pos)
{
	game->map->base_map[player_pos] = '0';
	--game->map->spr.coins;
	if (game->map->spr.coins == 0)
		game->bg.exit = game->bg.exit_open;
}

static int	ft_validate_movement(t_win *game)
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
		return (ft_printf("%s\n", ERROR_MOV), 1);
	else if (map_pos == 'C')
		ft_collect_coin(game, player_pos);
	else if (map_pos == 'N')
		ft_touched_enemy(game);
	else if (map_pos == 'E')
	{
		if (game->map->spr.coins != 0)
			return (ft_printf("%s\n", ERROR_EXIT), 1);
		ft_printf("%s\n", WIN);
		exit_program(game);
	}
	++game->movements;
	return (0);
}

static void	ft_movement_aux(t_win *game, int key)
{
	if (key == RIGHT)
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
}

void	ft_movement(t_win *game, int key)
{
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
	ft_movement_aux(game, key);
	ft_render(game);
}
