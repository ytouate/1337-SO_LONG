/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:45:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/13 14:44:23 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_line(char *buf)
{
	char	*temp;
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		temp = malloc(i + 2 * sizeof(char));
	else
		temp = malloc(i + 1 * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		temp[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*ft_save_left(char *buf)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	temp = malloc(ft_strlen(buf) - i + 1 * sizeof(char));
	if (!temp)
	{
		free(buf);
		return (NULL);
	}
	i++;
	while (buf[i])
		temp[j++] = buf[i++];
	temp[j] = '\0';
	free(buf);
	return (temp);
}

char	*loop(char *save, char *buffer, int byte, int fd)
{
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	buffer[0] = '\0';
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && byte != 0)
	{
		byte = read (fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}	
		buffer[byte] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*buffer;
	char			*line;
	int				byte;

	byte = 1;
	buffer = NULL;
	save = loop(save, buffer, byte, fd);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		return (NULL);
	if (!save[0])
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ft_get_line(save);
	save = ft_save_left(save);
	return (line);
}
