/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:51:11 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/10 10:40:40 by fcarranz         ###   ########.fr       */
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
	if (map->chpath.exit == 1 && map->chpath.coins == map->coins)
		map->chpath.valid = 1;
	if (map->base_map[pos] == '1' || map->chpath.valid == 1)
		return (0);
	map->chpath.visited[pos] = 1;
	if (map->base_map[pos] == 'C')
		++map->chpath.coins;
	if (map->base_map[pos] == 'E')
		++map->chpath.exit;
	if (map->chpath.visited[pos + map->x] != 1)
		ft_check_path_available(map, pos + map->x);
	if (map->chpath.visited[pos + 1] != 1)
		ft_check_path_available(map, pos + 1);
	if (map->chpath.visited[pos - 1] != 1)
		ft_check_path_available(map, pos - 1);
	if (map->chpath.visited[pos - map->x] != 1)
		ft_check_path_available(map, pos - map->x);
	return (map->chpath.valid);
}
