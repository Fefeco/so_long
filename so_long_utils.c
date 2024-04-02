/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:01:32 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/02 11:58:20 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win   ft_create_window(int width, int height, char *str)
{
    t_win   prog;

    prog.connection = mlx_init();
    prog.window = mlx_new_window(prog.connection, width, height, str);
    return (prog);
}

int	ft_check_extension(const char *filename, const char *ext)
{
	int	len_ext;
	int	len_fname;

	if (!filename || !ext)
	{
		ft_printf("%s\n", ERROR_MAP);
		return (1);
	}
	len_ext = ft_strlen(ext);
	len_fname = ft_strlen(filename);
	if (ft_strncmp(filename + (len_fname - len_ext), ext, len_ext))
	{
		ft_printf("%s\n", ERROR_EXTENSION);
		return (1);
	}
	return (0);
}

