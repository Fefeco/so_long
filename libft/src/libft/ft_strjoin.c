/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:49:22 by fcarranz          #+#    #+#             */
/*   Updated: 2024/01/28 11:29:00 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	total_len;
	size_t	s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	total_len = s1_len + ft_strlen(s2);
	ptr = (char *)malloc((total_len + 1) * sizeof(char));
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, total_len + 1);
	return (ptr);
}
