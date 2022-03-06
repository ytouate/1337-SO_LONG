/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:20:28 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/03 10:25:49 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void check_first_line(char *line)
{
	int i;
	int j;
	i = 0;
	j = ft_strlen(line) - 1;
	while (i < j)
	{
		if (line[i] != '1')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void check_last_line(char *line)
{
	int i;
	int j;
	i = 0;
	if (line == NULL)
		exit(1);
	j = ft_strlen(line);
	while (i < j)
	{
		if (line[i] != '1')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void check_map_len(char **map, int rows)
{
	int i;
	int j;
	int k;
	int p;

	i = 0;
	j = rows;
	k = 0;
	while (i < rows - 1)
	{
		j = 0;
		k = ft_strlen(map[j]);
		p = ft_strlen(map[i]);
		while (j < rows - 1)
		{
			if (k != p)
				error();
			j++;
		}
		i++;
	}
	if (p != ft_strlen(map[rows - 1]) + 1)
		error();
}

void check_map(char **map, int rows)
{
	int i;
	int j;
	int k;
	i = 1;
	j = rows - 1;

	check_first_line(map[0]);
	check_last_line(map[rows - 1]);
	while (i < j)
	{
		k = ft_strlen(map[i]) - 2;
		if (map[i][0] != '1' || map[i][k] != '1')
			error();
		i++;
	}
	check_map_len(map, rows);
	return ;
}


valid_map check_requirs(char **map, int rows)
{
	valid_map	a = {0,0,0};
	int i;
	int j;
	int k;
    int p;

	j = rows - 1;
	i = 1;
	while (i < j)
	{
		k = 0;
        p = ft_strlen(map[i]) - 1;
		while (k < p)
		{
			if (map[i][k] == 'E')
				a.map_exit += 1;
			else if (map[i][k] == 'C')
				a.collectable += 1;
			else if (map[i][k] == 'P')
				a.starting_pos += 1;
			else if (map[i][k] == '0' || map[i][k] == '1')
				pass ;
			else
				error();	
			k++;
		}
		i++;
	}
	if (a.collectable >= 1 && a.map_exit >= 1 && a.starting_pos == 1)
		return (a);
	exit(EXIT_FAILURE);
}
