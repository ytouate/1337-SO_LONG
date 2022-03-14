/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:01:41 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 05:49:17 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_line(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(line) - 1;
	while (i < j)
	{
		if (line[i] != '1')
		{
			write(2, "Error: map boarders must be walls\n", 35);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_last_line(char *line)
{
	int	i;
	int	j;

	i = 0;
	if (line == NULL)
		exit(1);
	j = ft_strlen(line);
	while (i < j)
	{
		if (line[i] != '1')
		{
			write(2, "Error: map boarders must be walls\n", 35);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	map_len_error(void)
{
	write(2, "Error: the lines of the map are not identical\n", 47);
	exit(EXIT_FAILURE);
}

void	file_format_error(void)
{
	write(1, "Error: invalid file format\n", 28);
	exit(EXIT_FAILURE);
}

void count_char(char *s)
{
	t_vars	var;

	var.i = 0;
	var.k = 0;
	var.j = 0;
	while (*s)
	{
		if (*s == 'b')
			var.i++;
		else if (*s == 'e')
			var.k++;
		else if (*s == 'r')
			var.j++;
		else
			file_format_error();
		s++;
	}
	if (var.j != 1 || var.k != 1 || var.i != 1)
		file_format_error();
}

void	check_format(char *s)
{
	int	i;
    int	flag;

    flag = 0;
    i = 0;
	while (s[i] && s[i] != '.')
		i++;
    i++;
    count_char(s + i);
}