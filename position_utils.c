/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:10 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/12 09:48:21 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x(t_map a)
{
	return (ft_strlen(a.map[a.rows - 1]) * 50);
}

int	get_y(t_map a)
{
	return (a.rows * 50);
}

t_list	*get_c_pos(int rows, char **map, char c)
{
	int		i;
	int		j;
	int		x_cor;
	int		y_cor;
	t_list	*data;

	i = 0;
	j = 0;
	y_cor = 0;
	data = malloc(sizeof(t_list));
	if (!data)
		exit(EXIT_FAILURE);
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
				ft_lstadd_front(&data, ft_lstnew(x_cor, y_cor));
			j++;
			x_cor += 50;
		}
		i++;
		y_cor += 50;
	}
	return (data);
}
