/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:45 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 05:50:11 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_mlx_utils *a)
{
	a->mlx = mlx_init();
	a->movs = 0;
	if (a->mlx == NULL)
		exit(EXIT_FAILURE);
	a->window = mlx_new_window(a->mlx, get_x(a->a),
			get_y(a->a), "so_long");
	a->map_exit = mlx_xpm_file_to_image(a->mlx,
			"/Users/ytouate/Desktop/so_long/pics/exit.xpm",
			a->width, a->height);
	a->player = mlx_xpm_file_to_image(a->mlx,
			"/Users/ytouate/Desktop/so_long/pics/player_right.xpm",
			a->width, a->height);
	a->collectable = mlx_xpm_file_to_image(a->mlx,
			"/Users/ytouate/Desktop/so_long/pics/collectable.xpm",
			a->width, a->height);
	a->land = mlx_xpm_file_to_image(a->mlx,
			"/Users/ytouate/Desktop/so_long/pics/land.xpm",
			a->width, a->height);
	a->wall = mlx_xpm_file_to_image(a->mlx,
			"/Users/ytouate/Desktop/so_long/pics/pic.xpm",
			a->width, a->height);
	a->player_pos = get_c_pos(a->a.rows, a->a.map, 'P');
}

void	error(void)
{
	write(2, "Error: map not found\n", 22);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int			fd;
	t_mlx_utils	mlx_utils;
	t_measures	measure;
	t_valid_map	b;

	measure.width = 50;
	measure.height = 50;
	mlx_utils.height = &measure.width ;
	mlx_utils.width = &measure.height;
	if (ac != 2)
		exit(EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error();
	mlx_utils.a.map = convert(fd, av[1]);
	mlx_utils.a.rows = count_map_lines(av[1]);
	b = check_requirs(mlx_utils.a);
	check_map(mlx_utils.a);
	check_format(av[1]);
	mlx_utils.num_of_collects = b.collectable;
	init_image(&mlx_utils);
	put_image(mlx_utils, mlx_utils.a);
	mlx_key_hook(mlx_utils.window, key_handler, &mlx_utils);
	mlx_loop(mlx_utils.mlx);
}
