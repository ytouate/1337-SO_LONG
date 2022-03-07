/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:10 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/07 14:40:27 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
t_list *get_c_pos(int rows, char **map, char c)
{
	int i = 0;
	int j = 0;
	int x_cor = 0;
	int y_cor = 0;
	t_list	*data = malloc(sizeof(t_list));
	data->x_cor = 0;
	data->y_cor = 0;
	data->next = NULL;
	while (i < rows)
	{
		j = 0;
		x_cor = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				ft_lstadd_front(&data, ft_lstnew(x_cor, y_cor));
			}
			j++;
			x_cor += 50;
		}
		i++;
		y_cor += 50;
	}
	return (data);
}

t_list *get_position(int rows, char **map, char c)
{
	int i;
	int j;
	t_list *pos;
	int x_cor;
	int y_cor;

	i = 0;
	x_cor = 0;
	y_cor = 0;
	pos = malloc(sizeof(t_list));
	if (!pos)
		return (0);
	while (i < rows)
	{
		j = 0;
		x_cor = 0;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == c)
			{
				pos->x_cor = x_cor;
				pos->y_cor = y_cor;
				return (pos);
			}
			j++;
			x_cor += 50;
		}
		i++;
		y_cor += 50;
	}
	return (0);
}