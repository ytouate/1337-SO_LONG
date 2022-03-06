/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:45:06 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/02 10:45:29 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error()
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int count_map_lines(char *file)
{
	char *temp;
	int	count;
	int	fd;

	fd = open(file, O_RDONLY);
	count = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		count++;
		free(temp);
		temp = get_next_line(fd);
	}
	temp = NULL;
	close(fd);
	return (count);
}

char **convert(int fd, char *file)
{
	int i;
	int	j;

	j = count_map_lines(file);
	i = 0;
	char **s;
	s = malloc(sizeof(char *) * j);
	if (!s)
		return (NULL);
	while (i < j)
	{
		s[i] = get_next_line(fd);
		i++;
	}
	return (s);
}
