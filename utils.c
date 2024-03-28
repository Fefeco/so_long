/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:01:32 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/28 14:18:44 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"


win_t   ft_create_window(int width, int height, char *str)
{
    win_t   prog;

    prog.connection = mlx_init();
    if (!prog.connection)
        return (prog == NULL);
    prog.window = mlx_new_window(prog.connection, width, height, str);
    if (!prog.window)
    {
        free (prog.connection);
        return (prog == NULL);
    }
    return (prog);
}
