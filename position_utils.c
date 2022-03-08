/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:10 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/08 21:18:05 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_x(map a)
{
	return (ft_strlen(a.map[a.rows - 1]) * 50);
}

int get_y(map a)
{
	return (a.rows * 50);
}

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
