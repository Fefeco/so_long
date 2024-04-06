/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/06 13:11:35 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_win *game)
{
	if (key == ESC)
		exit_program(game);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_movement(game, key);
	else
		printf("Tecla %d presionada\n", key);
	return (0);
}

int	ft_check_error(int argc)
{
	if (argc == 1)
		perror(ERROR_NO_MAP);
	if (argc > 2)
		perror(ERROR_TO_MANY_ARGS);
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
	if (ft_load_textures(&game))
		exit_program(&game);
	game.map = &map;
	game.player.render = game.player.down;
	game.movements = 0;
	ft_render(&game);
	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window, 17, 0, exit_program, &game); // Codigo DestroyNotify
	mlx_loop(game.connection);
	return (0);
}
