/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/29 11:37:04 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"


///////////////////////////////
// Funciones para los Hooks //
///////////////////////////////
int	exit_program(win_t *game)
{
	if (game)
		mlx_destroy_window(game->connection, game->window);
	printf("Cerro!");
	exit(EXIT_FAILURE);
}

int	key_press(int key, win_t *game)
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
///////////////////////////////
// Fin Funciones para los Hooks
///////////////////////////////



///////////////////////////
// Funciones mmovimiento //
///////////////////////////

int	ft_movement(win_t *game, int key)
{
//	mlx_clear_window(game.connection, game.window);
	if (key == UP)
	{
		game->player.pos_y -= 20;
		game->player.render = game->player.up;
	}
	else if (key == DOWN)
	{
		game->player.pos_y += 20;
		game->player.render = game->player.down;
	}
	else if (key == RIGHT)
	{
		game->player.pos_x += 20;
		game->player.render = game->player.right;
	}
	else if (key == LEFT)
	{
		game->player.pos_x -= 20;
		game->player.render = game->player.left;
	}

	mlx_put_image_to_window(game->connection, game->window, game->player.render, 
			game->player.pos_x, game->player.pos_y);
	mlx_do_sync(game->connection);
	return (0);
}


///////////////////////////
// Funciones mmovimiento //
///////////////////////////



int main(void)
{
	win_t	game;
	void	*texture;

	game = ft_create_window(WIDTH, HEIGHT, "My Juego");
	if (!game.connection || !game.window)
		return (1);
	
	
	texture = mlx_xpm_file_to_image(game.connection, 
			"img/textura.xpm", 
			&game.width, 
			&game.height);
	game.player.right = mlx_xpm_file_to_image(game.connection, 
			"img/player_right.xpm", 
			&game.width, 
			&game.height);
	
	game.player.up = mlx_xpm_file_to_image(game.connection, 
			"img/player_up.xpm", 
			&game.width, 
			&game.height);
	
	game.player.left = mlx_xpm_file_to_image(game.connection, 
			"img/player_left.xpm", 
			&game.width, 
			&game.height);
	
	game.player.down = mlx_xpm_file_to_image(game.connection, 
			"img/player_down.xpm", 
			&game.width, 
			&game.height);
	
	mlx_put_image_to_window(game.connection, game.window, texture, 0, 0);

	game.player.pos_x = 25;
	game.player.pos_y = 30;
	game.player.render = game.player.right;
	mlx_put_image_to_window(game.connection, game.window, game.player.render, 
			game.player.pos_x, game.player.pos_y);
	mlx_string_put(game.connection, 
			game.window, 
			WIDTH * 0.4, 
			HEIGHT * 0.9 , 
			0xFF99FF, 
			"GAME ON!");

	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
//	mlx_hook(game.window, 6, 1L << 6, mouse_move, NULL);
//	mlx_hook(game.window, 4, 1L << 2, mouse_click, NULL);
	mlx_hook(game.window, 17, 0, exit_program, &game); // Codigo DestroyNotify
	mlx_do_sync(game.connection);
	mlx_loop(game.connection);
	mlx_destroy_window(game.connection, game.window);
	free (game.connection);
	return (0);
}
