/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:10 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/13 19:00:30 by ytouate          ###   ########.fr       */
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
	t_vars		var;
	t_list		*data;

	var.i = -1;
	var.y_cor = 0;
	data = malloc(sizeof(t_list));
	if (!data)
		exit(EXIT_FAILURE);
	data->x_cor = 0;
	data->y_cor = 0;
	data -> next = NULL;
	while (++var.i < rows)
	{
		var.j = 0;
		var.x_cor = 0;
		while (map[var.i][var.j] != '\n' && map[var.i][var.j] != '\0')
		{
			if (map[var.i][var.j] == c)
				ft_lstadd_front(&data, ft_lstnew(var.x_cor, var.y_cor));
			var.j++;
			var.x_cor += 50;
		}
		var.y_cor += 50;
	}
	return (data);
}

t_boarders	get_boarders_pos(t_mlx_utils a)
{
	t_boarders	b;

	b.boarder = get_c_pos(a.a.rows, a.a.map, '1');
	b.collectable_pos = get_c_pos(a.a.rows, a.a.map, 'C');
	b.map_exit = get_c_pos(a.a.rows, a.a.map, 'E');
	return (b);
}
