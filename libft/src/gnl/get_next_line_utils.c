/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:36:56 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/05 12:38:31 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s_dup;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		++i;
	s_dup = (char *)malloc(sizeof (char) * (i + 1));
	if (!s_dup)
		return (NULL);
	s_dup[i] = '\0';
	while (i >= 0)
	{
		s_dup[i] = s[i];
		--i;
	}
	return (s_dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	total_len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc((total_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (free(s1), free(s2), joined);
}

void	ft_bzero(char *buffer, size_t len)
{
	size_t	i;

	if (!buffer)
		return ;
	i = 0;
	while (i < len)
	{
		buffer[i] = '\0';
		++i;
	}
}
