/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:45 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/07 19:39:06 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_x(char **map, int rows)
{
	return (ft_strlen(map[rows - 1]) * 50);
}

int get_y(int rows)
{
	return (rows * 50);
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

int	ft_close(int keycode, mlx_utils a)
{
	if (keycode == 0)
		mlx_destroy_window(a.mlx, a.window);
	return (0);
}
int	main(int ac, char **av)
{
	int	fd;
	char **map; 
	void *player;
	int rows;
	void *map_exit;
	void *collectable;
	mlx_utils mlx_utils;
	int h;
	int w;
	void *land;
	void *wall;
	valid_map a;
	h = 50;
	w = 50;
	mlx_utils.height= &h;
	mlx_utils.width = &w;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit(EXIT_FAILURE);
		map = convert(fd, av[1]);
		rows = count_map_lines(av[1]);
		a = check_requirs(map, rows);
		check_map(map, rows);
		mlx_utils.mlx = mlx_init();
		if (mlx_utils.mlx == NULL)
			exit(EXIT_FAILURE);
		mlx_utils.window = mlx_new_window(mlx_utils.mlx, get_x(map, rows), get_y(rows), "so_long");
		map_exit = mlx_xpm_file_to_image(mlx_utils.mlx, "exit.xpm", mlx_utils.width, mlx_utils.height);
		player = mlx_xpm_file_to_image(mlx_utils.mlx, "player_up.xpm", mlx_utils.width, mlx_utils.height);
		collectable = mlx_xpm_file_to_image(mlx_utils.mlx, "collectable.xpm", mlx_utils.width, mlx_utils.height);
		land = mlx_xpm_file_to_image(mlx_utils.mlx, "land.xpm", mlx_utils.width, mlx_utils.height);
		wall = mlx_xpm_file_to_image(mlx_utils.mlx, "pic.xpm", mlx_utils.width, mlx_utils.height);
		put_land(mlx_utils.mlx, mlx_utils.window, land, rows, map);
		put_wall(mlx_utils.mlx, mlx_utils.window, wall, rows, map);
		put_exit(mlx_utils.mlx, mlx_utils.window, map_exit, rows, map);
		put_player(mlx_utils.mlx, mlx_utils.window, player, rows, map);
		put_collectable(mlx_utils.mlx, mlx_utils.window, collectable, rows, map);
		mlx_loop(mlx_utils.mlx);
	}
	else
		exit(EXIT_FAILURE);
}
