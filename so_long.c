/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/28 21:23:11 by fcarranz         ###   ########.fr       */
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
	else if (key == 124)
	{
		game->box_x += 20;
		printf("Brujo en posicion \nx = %d\ny = %d\n", game->box_x, game->box_y);
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


int main(void)
{
	win_t	game;
	void	*player;
	void	*texture;

	game = ft_create_window(WIDTH, HEIGHT, "My Juego");
	if (!game.connection || !game.window)
		return (1);
	
	
	texture = mlx_xpm_file_to_image(game.connection, 
			"img/textura.xpm", 
			&game.width, 
			&game.height);
	player = mlx_xpm_file_to_image(game.connection, 
			"img/player.xpm", 
			&game.width, 
			&game.height);
	
	mlx_put_image_to_window(game.connection, game.window, texture, 0, 0);

	game.box_x = 25;
	game.box_y = 30;
	mlx_put_image_to_window(game.connection, game.window, player, 
			game.box_x, game.box_y);
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
