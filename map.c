/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:29:34 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/03 11:44:56 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_size(t_map *map)
{
	char	*line;

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
		free (line);
		line = get_next_line(map->fd);
		if (line && (int)ft_strlen(line) != map->x + 1)
			return (close(map->fd), free(line), 0);
	}
	close (map->fd);
	if (map->x <= map->y)
		return (0);
	return (1);
}

/*int	ft_check_map_size(char *map_file)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	x = ft_strlen(line) -1; //Remove the \n count 
	y = 0;
	while (line)
	{
		++y;
		free (line);
		line = get_next_line(fd);
		if (line && (int)ft_strlen(line) != x + 1)
			return (free (line), 0);
	}
	close (fd);
	if (x <= y)
		return (0);
	return (1);
}*/

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
