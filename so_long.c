/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/05 14:03:35 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//////////////////////////////
// Funciones para los Hooks //
//////////////////////////////
int	exit_program(t_win *game)
{
	if (game)
		mlx_destroy_window(game->connection, game->window);
	exit(EXIT_FAILURE);
}

int	key_press(int key, t_win *game)
{
	if (key == 53)
		exit_program(game);
	else if (key >= 123 && key <= 126)
	{
		printf("Brujo en posicion \nx = %d\ny = %d\n", 
				game->player.pos_x, 
				game->player.pos_y);
		ft_movement(game, key);
	}
	else
		printf("Tecla %d presionada\n", key);
	return (0);
}

int	mouse_move(int x, int y)
{
	printf("Mouse en la posicion (%d, %d)\n", x, y);
	return (0);
}

int	mouse_click(int button)
{
	printf("Mouse click %d\n", button);
	return (0);
}
//////////////////////////////////
// Fin Funciones para los Hooks //
//////////////////////////////////
//
//
//
//
//
//
//
///////////////////////////
// Funciones mmovimiento //
///////////////////////////

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
		return (ft_printf("%s\n", ERROR_MOV), 1);
	return (0);
}

int	ft_movement(t_win *game, int key)
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

///////////////////////////////
// FIN Funciones mmovimiento //
///////////////////////////////
//
//
//
//
//
//
//
///////////////////////////////
/////// Funciones UTILS ///////
///////////////////////////////


///////////////////////////////
///// FIN Funciones UTILS /////
///////////////////////////////

int	ft_check_error(int argc)
{
	if (argc == 1)
		ft_printf("%s\n", ERROR_NO_MAP);
	if (argc > 2)
		ft_printf("%s\n", ERROR_TO_MANY_ARGS);
	return (1);
}

int main(int argc, char *argv[])
{
	t_win	game;
	t_map	map;

	if (argc == 1 || argc >2)
		return (ft_check_error(argc));
	map.filename = argv[1];
	map.base_map = (char *)malloc(sizeof(char) * 1);
	map.base_map[0] = '\0';
	if (ft_load_map(&map))
		return (1);
	game = ft_create_window(map.width, map.height, "My Juego");
	if (!game.connection || !game.window)
		return (1);

	ft_load_textures(&game);
	game.map = &map;
	game.player.render = game.player.right;
	ft_render(&game);


	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
//	mlx_hook(game.window, 6, 1L << 6, mouse_move, NULL);
//	mlx_hook(game.window, 4, 1L << 2, mouse_click, NULL);
	mlx_hook(game.window, 17, 0, exit_program, &game); // Codigo DestroyNotify
	mlx_loop(game.connection);
	//mlx_destroy_window(game.connection, game.window);
	//free (game.connection);
	return (0);
}
