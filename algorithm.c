/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:51:11 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/09 14:03:14 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_player(t_map *map)
{
	int	i;

	i = 0;
	while (map->base_map[i] != 'P')
		++i;
	return (i);
}

int	ft_check_path_available(t_map *map, int pos)
{
//	ft_printf("POSICION: |%d| || COINS: %d || EXIT: %d\n", pos, map->cpath.coins, map->cpath.exit);
	if (map->base_map[pos] == '1' || map->cpath.valid == 1)
		return (0);

	map->cpath.visited[pos] = 1;
	if (map->base_map[pos] == 'C')
		++map->cpath.coins;

	if (map->base_map[pos] == 'E')
		++map->cpath.exit;
//
	if (map->cpath.visited[pos + map->x] != 1)
		ft_check_path_available(map, pos + map->x);
	if (map->cpath.visited[pos + 1] != 1)
		ft_check_path_available(map, pos + 1);
	if (map->cpath.visited[pos - 1] != 1)
		ft_check_path_available(map, pos - 1);
	if (map->cpath.visited[pos - map->x] != 1)
		ft_check_path_available(map, pos - map->x);
//
	if (map->cpath.exit == 1 && map->cpath.coins == map->coins)
		map->cpath.valid = 1;
	return (1);
}
