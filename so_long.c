/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:45 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/06 12:59:32 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct  requirs {
	int E;
	int C;
} requirs;


int get_x(char **map, int rows)
{
	return (ft_strlen(map[rows - 1]) * 50);
}

int get_y(int rows)
{
	return (rows * 50);
}

void put_land(void *mlx, void *window, void *land, int rows, char **map)
{
	int x_core;
	int y_core;
	int i;
	int j;

	i = 0;
	j = 0;
	x_core = 0;
	y_core = 0;
	
	while (i < rows - 1)
	{
		j = 0;
		x_core = 0;
		while (j < ft_strlen(map[i]) - 1)
		{
			mlx_put_image_to_window(mlx, window, land, x_core, y_core);
			x_core += 50;
			j++;
		}
		i++;
		y_core += 50;
	}
	j = 0;
	x_core = 0;
	while (j < ft_strlen(map[i]))
	{
		mlx_put_image_to_window(mlx, window, land, x_core, y_core);
		x_core += 50;
		j++;
	}
}

int *get_starting_pos(int rows, char** map)
{
	int i;
	int	j;
	int *pos;
	int	x_core;
	int y_core;

	x_core = 0;
	y_core = 0;
	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	i = 0;
	while (i < rows)
	{
		j = 0;
		x_core = 0;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'P')
			{
				pos[0] = x_core;
				pos[1] = y_core;
				return (pos);
			}
			j++;
			x_core += 50;
		}
		i++;
		y_core += 50;
	}
	return (0);
}

int *get_collectable_pos(int rows, char **map)
{
	static int i;
	int j;
	static int x_core;
	static int y_core;
	int *pos;

	x_core = 0;
	y_core = 0;
	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	while (i < rows)
	{
		j = 0;
		x_core = 0;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'C')
			{
				pos[0] = x_core;
				pos[1] = y_core;
				return (pos);
			}
			x_core += 50;
			j++;
		}
		y_core += 50;
		i++;
	}
	return (0);
}

int *get_exit_position(int rows, char **map, int *k, int *x)
{
	static int i;
	int j;
	int *pos;
	static int x_core;
	static int y_core;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	while (i < rows)
	{
		j = *k;
		x_core = *x;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'E')
			{
				pos[0] = x_core;
				pos[1] = y_core;
				*k = j + 1;
				*x = x_core + 50;
				return (pos);
			}
			j++;
			x_core += 50;
		}
		i++;
		y_core += 50;
	}
	return (0);
}

void put_player(void *mlx, void *window, void *player, int rows, char **map)
{
	int *pos = get_starting_pos(rows, map);
	mlx_put_image_to_window(mlx, window, player, pos[0], pos[1]);
}

requirs count_requirs(int rows, char **map)
{
	int i;
	int j;

	requirs a;
	a.C = 0;
	a.E = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'E')
				a.E++;
			if (map[i][j] == 'C')
				a.C++;
			j++;
		}
		i++;
	}
	return (a);
}

void put_collectable(void *mlx, void *window, void *collectable, int rows, char **map)
{
	int *pos = get_collectable_pos(rows, map);
	mlx_put_image_to_window(mlx, window, collectable, pos[0], pos[1]);
}

void put_exit(void *mlx, void *window, void *map_exit, int rows, char **map)
{
	requirs a = count_requirs(rows, map);
	int k = 0;
	int x = 0;
	while (--a.E >= 0)
	{
		int *pos = get_exit_position(rows, map, &k, &x);
		mlx_put_image_to_window(mlx, window, map_exit, pos[0], pos[1]);
	}
}


int	main(int ac, char **av)
{
	int	fd;
	void *mlx;
	void *window;
	char *file;
	char **map;
	void *player;
	int rows;
	int *width;
	int *height;
	void *map_exit;
	void *collectable;
	int h;
	int w;
	void *land;
	valid_map a;
	h = 50;
	w = 50;
	width = &w;
	height = &h;


	if (ac == 2)
	{
		file = av[1];
		fd = open(file, O_RDONLY);
		if (fd == -1)
			exit(EXIT_FAILURE);
		map = convert(fd, file);
		rows = count_map_lines(file);
		check_requirs(map, rows);
		check_map(map, rows);
		mlx = mlx_init();
		if (mlx == NULL)
			exit(EXIT_FAILURE);

		window = mlx_new_window(mlx, get_x(map, rows), get_y(rows), "so_long");
		map_exit = mlx_xpm_file_to_image(mlx, "exit.xpm", width, height);
		player = mlx_xpm_file_to_image(mlx, "player.xpm", width, height);
		collectable = mlx_xpm_file_to_image(mlx, "collectable.xpm", width, height);
		land = mlx_xpm_file_to_image(mlx, "land.xpm", width, height);
		put_land(mlx, window, land, rows, map);
		put_exit(mlx, window, map_exit, rows, map);
		put_player(mlx, window, player, rows, map);
		put_collectable(mlx, window, collectable, rows, map);
		mlx_loop(mlx);
		
	}
	else
		exit(EXIT_FAILURE);
}
