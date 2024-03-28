/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/28 14:32:11 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"


///////////////////////////////
// Funciones para los Hooks //
///////////////////////////////
int	key_press(int key, t_game *game)
{
	if (key == 53)
	{
//		mlx_clear_window(game->mlx_connection, game->window);
		mlx_destroy_window(game->mlx_connection, game->window);
//		mlx_put_image_to_window(ply->mlx_ptr, ply->win_ptr, ply->img, 45, 30);
	}
	else if (key == 124)
	{
		mlx_destroy_image(game->mlx_connection, game->player);
		mlx_put_image_to_window(game->mlx_connection,
			   	game->window,
			   	game->player,
				45, 30);
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

	game = ft_create_window(600, 400, "My Juego");
	if (!game.connection || !game.window)
		return (1);
	
	
	game.texture = mlx_xpm_file_to_image(game.connection, "img/textura.xpm", &game.width, &game.height);
	game.player = mlx_xpm_file_to_image(game.connection, "img/player.xpm", &game.width, &game.height);

	mlx_put_image_to_window(game.connection, game.window, game.texture, 0, 0);
	mlx_put_image_to_window(game.connection, game.window, game.player, 25, 30);
	mlx_string_put(game.connection, game.window, WIDTH * 0.4, HEIGHT * 0.9 , 0xFF99FF, "GAME ON!");

	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window, 6, 1L << 6, mouse_move, NULL);
	mlx_hook(game.window, 4, 1L << 2, mouse_click, NULL);
	mlx_loop(game.connection);
	mlx_destroy_window(game.connection, game.window);
	free (game.connection);
	return (0);
}
