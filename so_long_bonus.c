/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:27:12 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 07:41:20 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	check_format(av[1]);
	b = check_requirs(mlx_utils.a);
	check_map(mlx_utils.a);
	mlx_utils.num_of_collects = b.collectable;
	init_image(&mlx_utils);
	put_image(mlx_utils, mlx_utils.a);
	get_patrol_pos(&mlx_utils);
	mlx_key_hook(mlx_utils.window, key_handler_bonus, &mlx_utils);
	mlx_loop(mlx_utils.mlx);
}
