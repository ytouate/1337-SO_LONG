/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:45 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/08 23:25:13 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image(mlx_utils mlx_utils, map a)
{
	put_land(mlx_utils, a);
	put_wall(mlx_utils, a);
	put_exit(mlx_utils, a);
	put_player(mlx_utils, a);
	put_collectable(mlx_utils, a);
}

void move_right(mlx_utils *a)
{
	mlx_put_image_to_window(a->mlx, a->window, a->land, a->player_pos->x_cor, a->player_pos->y_cor);
	a->player_pos->x_cor += 50;
	mlx_put_image_to_window(a->mlx, a->window, a->player, a->player_pos->x_cor, a->player_pos->y_cor);
}

void move_up(mlx_utils *a)
{
	mlx_put_image_to_window(a->mlx, a->window, a->land, a->player_pos->x_cor, a->player_pos->y_cor);
	a->player_pos->y_cor -= 50;
	mlx_put_image_to_window(a->mlx, a->window, a->player, a->player_pos->x_cor, a->player_pos->y_cor);
}

void move_left(mlx_utils *a)
{
	mlx_put_image_to_window(a->mlx, a->window, a->land, a->player_pos->x_cor, a->player_pos->y_cor);
	a->player_pos->x_cor -= 50;
	mlx_put_image_to_window(a->mlx, a->window, a->player, a->player_pos->x_cor, a->player_pos->y_cor);
}

void move_down(mlx_utils *a)
{
	mlx_put_image_to_window(a->mlx, a->window, a->land, a->player_pos->x_cor, a->player_pos->y_cor);
	a->player_pos->y_cor += 50;
	mlx_put_image_to_window(a->mlx, a->window, a->player, a->player_pos->x_cor, a->player_pos->y_cor);
}

int key_handler(int keycode, mlx_utils *a)
{
	printf("%d\n", keycode);
	if (keycode == 2)
		move_right(a);
	else if (keycode == 13)
		move_up(a);
	else if (keycode == 0)
		move_left(a);
	else if (keycode == 1)
		move_down(a);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	else
		pass ;
	return (a->a.rows);
}

// boarders get_boarders_pos(mlx_utils a)
// {
// 	int i;
// 	int j;
// 	int x_cor;
// 	int y_cor;

// 	x_cor = 0;
// 	y_cor = 0;
// 	i = 0;
// 	j = 0;
// 	while (i < a->a.rows)
// 	{
// 		j = 0;
// 		while (ft_strlen(a.a.map[i][j]) != '\n' && ft_strlen(a.a.map[i][j]) != '\0')
// 		{
			
// 		}
// 	}
// }
int	main(int ac, char **av)
{
	int	fd;
	mlx_utils mlx_utils;
	measures measure;
	valid_map b;

	measure.width = 50;
	measure.height = 50;
	mlx_utils.height= &measure.width ;
	mlx_utils.width = &measure.height;
	if (ac != 2)
		exit(EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	mlx_utils.a.map = convert(fd, av[1]);
	mlx_utils.a.rows = count_map_lines(av[1]);
	b = check_requirs(mlx_utils.a);
	check_map(mlx_utils.a);
	mlx_utils.mlx = mlx_init();
	if (mlx_utils.mlx == NULL)
		exit(EXIT_FAILURE);
		
	mlx_utils.window = mlx_new_window(mlx_utils.mlx, get_x(mlx_utils.a), get_y(mlx_utils.a), "so_long");
	mlx_utils.map_exit = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/exit.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.player = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/player_up.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.collectable = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/collectable.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.land = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/land.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.wall = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/pic.xpm", mlx_utils.width, mlx_utils.height);
	put_image(mlx_utils, mlx_utils.a);
	mlx_utils.player_pos = get_c_pos(mlx_utils.a.rows, mlx_utils.a.map, 'P');
	mlx_key_hook(mlx_utils.window, key_handler, &mlx_utils);
	mlx_loop(mlx_utils.mlx);	
}
