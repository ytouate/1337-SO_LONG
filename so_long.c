/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:45 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/08 21:09:13 by ytouate          ###   ########.fr       */
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
void move_front(mlx_utils *a)
{
	t_list *pos = get_c_pos(a->rows, a->map, 'P');
	printf("%d\t%d\n", pos->x_cor, pos->y_cor);
	//mlx_put_image_to_window(a->mlx, a->window, a->player, 4000,0);
}
int key_handler(int keycode, mlx_utils a)
{
	t_list *pos = get_c_pos(a.rows, a.map, 'P');
	//printf("%d\t%d\n", pos->x_cor, pos->y_cor);
	if (keycode == 13)
		move_front(&a);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (a.rows);
}
int	main(int ac, char **av)
{
	int	fd;
	map a;
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
	a.map = convert(fd, av[1]);
	a.rows = count_map_lines(av[1]);
	mlx_utils.rows = count_map_lines(av[1]);
	mlx_utils.map = convert(fd, av[1]);
	b = check_requirs(a);
	check_map(a);
	mlx_utils.mlx = mlx_init();
	if (mlx_utils.mlx == NULL)
		exit(EXIT_FAILURE);
	mlx_utils.window = mlx_new_window(mlx_utils.mlx, get_x(a), get_y(a), "so_long");
	mlx_utils.map_exit = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/exit.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.player = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/player_up.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.collectable = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/collectable.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.land = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/land.xpm", mlx_utils.width, mlx_utils.height);
	mlx_utils.wall = mlx_xpm_file_to_image(mlx_utils.mlx, "/Users/ytouate/Desktop/so_long/pics/pic.xpm", mlx_utils.width, mlx_utils.height);
	put_image(mlx_utils, a);
	mlx_key_hook(mlx_utils.window, key_handler, &mlx_utils);
	mlx_loop(mlx_utils.mlx);	
}
