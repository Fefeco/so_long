/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:26 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/27 20:21:15 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./mlx/mlx.h"

typedef struct s_img
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_img;

int	key_press(int key, t_img ply)
{
	printf("Tecla %d presionada\n", key);
	if (key == 53)
	{
//		free (ply.img);
		mlx_destroy_window(ply.mlx_ptr, ply.win_ptr);
	}
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

int main(void)
{
	void	*img;
	int		width;
	int		height;
	t_img	ply;

    ply.mlx_ptr = mlx_init();
	if (!ply.mlx_ptr)
	{
		printf("Devuelve NULL\n");
		return (1);
	}
	ply.win_ptr = mlx_new_window(ply.mlx_ptr, 600, 400, "Mi ventana");
	if (!ply.win_ptr)
	{
		free (ply.mlx_ptr);
		return (1);
	}
	img = mlx_xpm_file_to_image(ply.mlx_ptr, "img/textura.xpm", &width, &height);
	ply.img = mlx_xpm_file_to_image(ply.mlx_ptr, "img/player.xpm", &width, &height);
	mlx_put_image_to_window(ply.mlx_ptr, ply.win_ptr, img, 0, 0);
	mlx_put_image_to_window(ply.mlx_ptr, ply.win_ptr, ply.img, 25, 30);

	mlx_destroy_image(ply.mlx_ptr, img);

	mlx_hook(ply.win_ptr, 2, 1L << 0, key_press, ply.img);
	mlx_hook(ply.win_ptr, 6, 1L << 6, mouse_move, NULL);
	mlx_hook(ply.win_ptr, 4, 1L << 2, mouse_click, NULL);
	mlx_loop(ply.mlx_ptr);
	mlx_destroy_window(ply.mlx_ptr, ply.win_ptr);
	free (ply.mlx_ptr);
	return (0);
}
