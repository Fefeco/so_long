/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:29:34 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/30 19:31:56 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_map_size(t_map *map)
{
	char	*line;

	map->fd = open(map->filename, O_RDONLY);
	if (map->fd < 0)
		return (perror(ERROR_FILE), 1);
	line = get_next_line(map->fd);
	if (!line)
		return (1);
	map->x = ft_strlen(line) -1;
	map->y = 0;
	while (line)
	{
		++map->y;
		map->base_map = ft_strjoin(map->base_map, ft_strtrim(line, "\n"));
		free (line);
		line = get_next_line(map->fd);
		if (line && (int)ft_strlen(line) - 1 != map->x)
			return (perror(ERROR_MAP_SIZE), close(map->fd), free(line), 1);
	}
	close (map->fd);
	if (map->x == map->y)
		return (perror(ERROR_MAP_SIZE), 1);
	map->width = map->x * TILE_W;
	map->height = map->y * TILE_H;
	return (0);
}

static int	ft_validate_sprites(t_map *map)
{
	int		i;
	int		exit;
	int		player;
	char	c;

	i = 0;
	exit = 0;
	player = 0;
	map->coins = 0;
	while (map->base_map[i])
	{
		c = map->base_map[i++];
		if (!ft_strchr("EPC01", c))
			return (perror(ERROR_INVALID_CHAR), 1);
		else if (c == 'E')
			++exit;
		else if (c == 'P')
			++player;
		else if (c == 'C')
			++map->coins;
	}
	if (exit != 1 || player != 1 || map->coins < 1)
		return (perror(ERROR_STRIPES), 1);
	return (0);
}

static int	ft_check_walls(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if ((y == 0 && map->base_map[i] != '1') || (y == map->y -1
					&& map->base_map[i] != '1') || (x == 0
					&& map->base_map[i] != '1') || (x == map->x -1
					&& map->base_map[i] != '1'))
				return (perror(ERROR_WALLS), 1);
			++x;
			++i;
		}
		++y;
	}
	return (0);
}

static int	ft_check_path_available(t_map *map, int pos)
{
	if (map->chpath.exit == 1 && map->chpath.coins == map->coins)
		map->chpath.valid = 1;
	if (map->base_map[pos] == '1' || map->chpath.valid == 1)
		return (0);
	map->chpath.visited[pos] = 'V';
	if (map->base_map[pos] == 'C')
		++map->chpath.coins;
	if (map->base_map[pos] == 'E')
	{
		++map->chpath.exit;
		return (0);
	}
	if (map->chpath.visited[pos - 1] != 'V')
		ft_check_path_available(map, pos - 1);
	if (map->chpath.visited[pos + 1] != 'V')
		ft_check_path_available(map, pos + 1);
	if (map->chpath.visited[pos + map->x] != 'V')
		ft_check_path_available(map, pos + map->x);
	if (map->chpath.visited[pos - map->x] != 'V')
		ft_check_path_available(map, pos - map->x);
	if (map->chpath.exit == 1 && map->chpath.coins == map->coins)
		map->chpath.valid = 1;
	return (map->chpath.valid);
}

int	ft_load_map(t_map *map)
{
	int	pos;

	if (ft_check_extension(map->filename, EXTENSION))
		return (1);
	if (ft_check_map_size(map) || ft_check_walls(map)
		|| ft_validate_sprites(map))
		return (free(map->base_map), 1);
	pos = ft_find_player(map);
	map->chpath.valid = 0;
	map->chpath.coins = 0;
	map->chpath.exit = 0;
	map->chpath.visited = (int *)ft_calloc(sizeof(int), (map->x * map->y));
	if (!ft_check_path_available(map, pos))
	{
		free(map->base_map);
		free(map->chpath.visited);
		perror(ERROR_NO_PATH);
		return (1);
	}
	return (0);
}
