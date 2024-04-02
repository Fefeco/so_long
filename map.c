/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:29:34 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/02 13:40:41 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_check_map_size(char *map_file)
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
		{
			free (line);
			return (0);
		}
	}
	close (fd);
	if (x <= y)
		return (0);
	return (1);
}

int		ft_load_map(t_win *game, char *map_file)
{
	if (ft_check_extension(map_file, EXTENSION))
		exit_program(game);
	if (!ft_check_map_size(map_file))
	{
		ft_printf("%s\n", ERROR_MAP_SIZE);
		exit_program(game);
	}
	exit_program(game);
	return(1);
//	game->map = map;
}
