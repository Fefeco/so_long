/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:01:32 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/30 10:09:28 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

win_t   ft_create_window(int width, int height, char *str)
{
    win_t   prog;

    prog.connection = mlx_init();
    prog.window = mlx_new_window(prog.connection, width, height, str);
    return (prog);
}
