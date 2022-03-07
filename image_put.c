/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:14 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/07 14:56:22 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_collectable(void *mlx, void *window, void *collectable, int rows, char **map)
{
	t_list *pos = get_c_pos(rows, map, 'C');
	while (pos->next)
	{
		mlx_put_image_to_window(mlx, window, collectable, pos->x_cor, pos->y_cor);
		pos = pos->next;
	}
}

void put_exit(void *mlx, void *window, void *map_exit, int rows, char **map)
{
	t_list *pos = get_c_pos(rows, map, 'E');
	while (pos->next)
	{
		mlx_put_image_to_window(mlx, window, map_exit, pos->x_cor, pos->y_cor);
		pos = pos->next;
	}
}

void put_wall(void *mlx, void *window, void *wall, int rows, char **map)
{
	t_list *pos = get_c_pos(rows, map, '1');
	while (pos->next)
	{
		mlx_put_image_to_window(mlx, window, wall, pos->x_cor, pos->y_cor);
		pos = pos->next;
	}
}

void put_land(void *mlx, void *window, void *land, int rows, char **map)
{
	int x_cor;
	int y_cor;
	int i;
	int j;

	i = 0;
	j = 0;
	x_cor = 0;
	y_cor = 0;
	
	while (i < rows - 1)
	{
		j = 0;
		x_cor = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			mlx_put_image_to_window(mlx, window, land, x_cor, y_cor);
			x_cor += 50;
			j++;
		}
		i++;
		y_cor += 50;
	}
}

void put_player(void *mlx, void *window, void *player, int rows, char **map)
{
	t_list *pos = get_c_pos(rows, map, 'P');
	while (pos->next)
	{
		mlx_put_image_to_window(mlx, window, player, pos->x_cor, pos->y_cor);
		pos = pos -> next;
	}
}