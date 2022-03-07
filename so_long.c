/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:45 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/07 14:05:27 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct  requirs {
	int	E;
	int	C;
} requirs;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new ->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int x, int y)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> x_cor = x;
	list -> y_cor = y;
	list -> next = NULL;
	return (list);
}

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

void put_player(void *mlx, void *window, void *player, int rows, char **map)
{
	t_list *pos = get_position(rows, map, 'P');
	mlx_put_image_to_window(mlx, window, player, pos->x_cor, pos->y_cor);
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

void put_structure(int rows, char **map, void *mlx, void *window, void *land, void *wall)
{
	int i = 0;
	int j = 0;
	int x_cor = 0;
	int y_cor = 0;
	while (i < rows)
	{
		j = 0;
		x_cor = 0;
		while (j < ft_strlen(map[i]) - 1)
		{
			mlx_put_image_to_window(mlx, window, land, x_cor, y_cor);
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx, window, wall, x_cor, y_cor);
			}
			j++;
			x_cor += 50;
		}
		y_cor += 50;
		i++;
	}
	mlx_put_image_to_window(mlx, window, wall, x_cor, y_cor - 50);
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
	void *wall;
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
		
		a = check_requirs(map, rows);
		check_map(map, rows);
		mlx = mlx_init();
		if (mlx == NULL)
			exit(EXIT_FAILURE);
		window = mlx_new_window(mlx, get_x(map, rows), get_y(rows), "so_long");
		map_exit = mlx_xpm_file_to_image(mlx, "exit.xpm", width, height);
		player = mlx_xpm_file_to_image(mlx, "player.xpm", width, height);
		collectable = mlx_xpm_file_to_image(mlx, "collectable.xpm", width, height);
		land = mlx_xpm_file_to_image(mlx, "land.xpm", width, height);
		wall = mlx_xpm_file_to_image(mlx, "pic.xpm", width, height);
		//put_structure(rows, map, mlx, window, land, wall);
		put_land(mlx, window, land, rows, map);
		put_wall(mlx, window, wall, rows, map);
		put_exit(mlx, window, map_exit, rows, map);
		put_player(mlx, window, player, rows, map);
		put_collectable(mlx, window, collectable, rows, map);
		mlx_loop(mlx);

	}
	else
		exit(EXIT_FAILURE);
}
