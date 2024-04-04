/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:29:34 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/04 10:59:05 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_size(t_map *map)
{
	char	*line;

	map->fd = open(map->filename, O_RDONLY);
	if (map->fd < 0)
		return (1);
	line = get_next_line(map->fd);
	if (!line)
		return (1);
	map->x = ft_strlen(line) -1; //Remove the \n count 
	map->y = 0;
	while (line)
	{
		++map->y;
		map->base_map = ft_strjoin(map->base_map, ft_strtrim(line, "\n"));
		free (line);
		line = get_next_line(map->fd);
		if (line && (int)ft_strlen(line) - 1 != map->x)
			return (close(map->fd), free(line), 1);
	}
	close (map->fd);
	if (map->x <= map->y)
		return (ft_printf("%s\n", ERROR_MAP_SIZE), 1);
	map->width = map->x * TILE_W;
	map->height = map->y * TILE_H;
	return (0);
}

int	ft_load_map(t_map *map)
{
	if (ft_check_extension(map->filename, EXTENSION))
		return (1);
	if (ft_check_map_size(map))
		return (free(map->base_map), 1);
	return (0);
//	game->map = map;
}
