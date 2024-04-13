/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:05:16 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/13 12:59:22 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	**ft_load_enemy(t_win *game)
{
	void	**tmp;

	tmp = malloc(sizeof(void *) * 5);
	if (!tmp)
		return (NULL);
	tmp[0] = mlx_xpm_file_to_image(game->connection,
			"textures/enemy_0.xpm", &(game->width), &(game->height));
	tmp[1] = mlx_xpm_file_to_image(game->connection,
			"textures/enemy_1.xpm", &(game->width), &(game->height));
	tmp[2] = mlx_xpm_file_to_image(game->connection,
			"textures/enemy_2.xpm", &(game->width), &(game->height));
	tmp[3] = mlx_xpm_file_to_image(game->connection,
			"textures/enemy_3.xpm", &(game->width), &(game->height));
	tmp[4] = NULL;
	return (tmp);
}
