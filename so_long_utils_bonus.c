/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:01:32 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/13 12:39:26 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_switch_img(void **img)
{
	static int	array_pos;
	static void	*tmp;

	if (!array_pos || !img[array_pos] || img != tmp)
	{
		tmp = img;
		array_pos = 0;
	}
	return (img[array_pos++]);
}

void	*ft_switch_img_2(void **img)
{
	static int	array_pos;
	static void	*tmp;

	if (!array_pos || !img[array_pos] || img != tmp)
	{
		tmp = img;
		array_pos = 0;
	}
	return (img[array_pos++]);
}
