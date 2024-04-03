/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:04:50 by fcarranz          #+#    #+#             */
/*   Updated: 2024/04/03 18:54:36 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_remind(char *buffer, char *line)
{
	int		len;
	int		i;
	int		j;
	char	*remind;

	if (!line)
	{
		free (buffer);
		return (NULL);
	}
	i = 0;
	while (line[i])
		++i;
	len = ft_strlen(&buffer[i]) + 1;
	remind = (char *)malloc(sizeof(char) * len);
	if (!remind)
		return (NULL);
	j = 0;
	while (buffer[i])
		remind[j++] = buffer[i++];
	remind[j] = '\0';
	free (buffer);
	return (remind);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	char	*end;
	int		len;
	int		i;

	end = ft_strchr(buffer, '\n');
	if (!end)
		return (ft_strdup(buffer));
	len = (end - buffer) + 2;
	line = (char *)malloc(sizeof(char) * len);
	if (!line)
		return (NULL);
	i = 0;
	while (&buffer[i] != end + 1)
	{
		line[i] = buffer[i];
		++i;
	}
	line[i] = '\0';
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

static char	*ft_read_file(char *buffer, int fd)
{
	char	*read_buf;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		read_buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (!read_buf)
			return (NULL);
		ft_bzero(read_buf, BUFFER_SIZE + 1);
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (read_buf);
			free (buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, read_buf);
		if (ft_strchr(buffer, '\n') || buffer == NULL)
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = ft_read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	if (ft_strlen(buffer) == 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer);
	buffer = ft_get_remind(buffer, line);
	return (line);
}
