/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/02 13:24:45 by fcarranz         ###   ########.fr       */
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
///////////////////////////////
// Funciones para renderizar //
///////////////////////////////

int	ft_load_textures(t_win *game)
{
	game->background.floor = mlx_xpm_file_to_image(game->connection, 
			"img/textura.xpm", 
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

int	ft_render(t_win *game)
{
	mlx_clear_window(game->connection, game->window);
	ft_render_map(game);
	mlx_put_image_to_window(game->connection, game->window, game->background.floor, 0, 0);
	mlx_put_image_to_window(game->connection, game->window, game->player.render, 
			game->player.pos_x, game->player.pos_y);

	mlx_string_put(game->connection, 
			game->window, 
			WIDTH * 0.4, 
			HEIGHT * 0.9 , 
			0xFF99FF, 
			"GAME ON!");
	return (0);
}

int	ft_render_map(t_win *game)
{
	int		fd;
	char	*line;

	fd = open(game->map, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		//ft_render_map_line(line);
		free (line);
	}
	close(fd);
	return (0);
}

//int	ft_render_map_line(char *line)
//{
//
//}
///////////////////////////////////
// FIN Funciones para renderizar //
///////////////////////////////////
//
//
//
//
//
//
///////////////////////////
// Funciones mmovimiento //
///////////////////////////

int	ft_movement(t_win *game, int key)
{
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

	if (argc == 1 || argc >2)
		return (ft_check_error(argc));
	game = ft_create_window(WIDTH, HEIGHT, "My Juego");
	if (!game.connection || !game.window)
		return (1);
	
	ft_load_map(&game, argv[1]);
	ft_load_textures(&game);

	game.player.pos_x = 25;
	game.player.pos_y = 30;
	game.player.render = game.player.right;
	ft_render(&game);
//	mlx_put_image_to_window(game.connection, game.window, game.player.render, 
//			game.player.pos_x, game.player.pos_y);

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
