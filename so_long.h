/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:02:33 by fcarranz          #+#    #+#             */
/*   Updated: 2024/03/28 21:12:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

#ifndef WIDTH
# define WIDTH 600
#endif

#ifndef HEIGHT
# define HEIGHT 400
#endif

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53

typedef	struct win_s {
	void	*connection;
	void	*window;
	int		width;
	int		height;
	int		box_x;
	int		box_y;
} win_t;
#endif

win_t	ft_create_window(int width, int height, char *str);

