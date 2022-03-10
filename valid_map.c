/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:20:28 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/10 17:54:17 by ytouate          ###   ########.fr       */
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

void	check_map_len(t_map a)
{
	int	i;
	int	j;
	int	k;
	int	p;

	i = 0;
	j = a.rows;
	k = 0;
	while (i < a.rows - 1)
	{
		j = 0;
		k = ft_strlen(a.map[j]);
		p = ft_strlen(a.map[i]);
		while (j < a.rows - 1)
		{
			if (k != p)
			{
				write(2, "Error: the lines of the map are not identical\n", 47);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	if (p != ft_strlen(a.map[a.rows - 1]) + 1)
	{
		write(2, "Error: the lines of the map are not identical\n", 47);
		exit(EXIT_FAILURE);
	}
}

void	check_map(t_map a)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = a.rows - 1;
	check_first_line(a.map[0]);
	check_last_line(a.map[a.rows - 1]);
	while (i < j)
	{
		k = ft_strlen(a.map[i]) - 2;
		if (a.map[i][0] != '1' || a.map[i][k] != '1')
		{
			write(2, "Error: the map must be surrounded with walls\n", 47);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	check_map_len(a);
	return ;
}

t_valid_map	check_requirs(t_map a)
{
	t_valid_map	b = {0, 0, 0};
	int			i;
	int			j;
	int			k;
	int			p;

	j = a.rows - 1;
	i = 1;
	while (i < j)
	{
		k = 0;
		p = ft_strlen(a.map[i]) - 1;
		while (k < p)
		{
			if (a.map[i][k] == 'E')
				b.map_exit += 1;
			else if (a.map[i][k] == 'C')
				b.collectable += 1;
			else if (a.map[i][k] == 'P')
				b.starting_pos += 1;
			else if (a.map[i][k] == '0' || a.map[i][k] == '1')
				pass ;
			else
			{
				write(2, "Error invalid map item\n", 24);
				exit(EXIT_FAILURE);
			}	
			k++;
		}
		i++;
	}
	if (b.collectable >= 1 && b.map_exit >= 1 && b.starting_pos == 1)
		return (b);
	else
	{
		write(2, "Error: the map requires are not fullfiled\n", 43);
		exit(EXIT_FAILURE);
	}
}
