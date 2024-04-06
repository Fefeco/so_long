/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:01:32 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/06 10:50:09 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win   ft_create_window(int width, int height, char *str)
{
    t_win   game;

    game.connection = mlx_init();
	if (!game.connection)
		return (perror(ERROR_CONNECTION), game);
    game.window = mlx_new_window(game.connection, width, height, str);
	game.width = width;
	game.height = height;
    return (game);
}

int	ft_check_extension(const char *filename, const char *ext)
{
	int	len_ext;
	int	len_fname;

	if (!filename || !ext)
		return (perror(ERROR_MAP), 1);
	len_ext = ft_strlen(ext);
	len_fname = ft_strlen(filename);
	if (ft_strncmp(filename + (len_fname - len_ext), ext, len_ext))
		return (perror(ERROR_EXTENSION), 1);
	return (0);
}

