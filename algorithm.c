/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:51:11 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/08 14:02:05 by fcarranz         ###   ########.fr       */
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

int	ft_check_path_available(t_map *map, int coins, int exit, int pos)
{
	ft_printf("BUSQUEDA: %d| MAP X : %d\n", pos, map->x);
	if (map->base_map[pos] == '1' || map->path == 1)
		return 1;
	if (map->base_map[pos] == 'C')
		++coins;
	if (map->base_map[pos] == 'E')
		++exit;
	if (exit == 1 && coins == map->coins)
	{
		map->path = 1;
		return (ft_printf("Camino encontrado"), 0);
	}
	ft_check_path_available(map, coins, exit, pos + map->x);
	ft_check_path_available(map, coins, exit, pos + 1);
	ft_check_path_available(map, coins, exit, pos - 1);
	ft_check_path_available(map, coins, exit, pos - map->x);
	if (map->path == 1)
		return (0);
	return (ft_printf("No hay camino posible"), 1);
}
