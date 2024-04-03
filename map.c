/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:29:34 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/03 13:43:04 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_size(t_map *map)
{
	char	*line;
	char	*prueba;

	map->fd = open(map->filename, O_RDONLY);
	if (map->fd < 0)
		return (0);
	line = get_next_line(map->fd);
	if (!line)
		return (0);
	map->x = ft_strlen(line) -1; //Remove the \n count 
	map->y = 0;
	while (line)
	{
		++map->y;
		prueba =ft_strtrim(line, "\n");
		map->map_from_file = ft_strjoin(map->map_from_file, prueba);
		free (line);
		free (prueba);
		line = get_next_line(map->fd);
		if (line && (int)ft_strlen(line) != map->x + 1)
			return (close(map->fd), free(line), 0);
	}
	ft_printf("%s", map->map_from_file);
	close (map->fd);
	if (map->x <= map->y)
		return (0);
	return (1);
}

int	ft_load_map(t_win *game)
{
	if (ft_check_extension(game->map.filename, EXTENSION))
		exit_program(game);
	if (!ft_check_map_size(&game->map))
	{
		ft_printf("%s\n", ERROR_MAP_SIZE);
		exit_program(game);
	}
	exit_program(game);
	return (1);
//	game->map = map;
}
