/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:45 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/16 19:44:24 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int			fd;
	int			temp;
	t_mlx_utils	mlx_utils;
	t_valid_map	b;

	temp = 50;
	mlx_utils.size = &temp;
	if (ac != 2)
		exit(EXIT_FAILURE);
	check_format(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error();
	mlx_utils.a.map = convert(fd, av[1]);
	mlx_utils.a.rows = count_map_lines(av[1]);
	b = check_requirs(mlx_utils.a);
	check_map(mlx_utils.a);
	mlx_utils.temp_collectable_pos = ft_lstnew(0, 0);
	mlx_utils.num_of_collects = b.collectable;
	init_image(&mlx_utils);
	put_image(mlx_utils, mlx_utils.a);
	mlx_key_hook(mlx_utils.window, key_handler, &mlx_utils);
	mlx_hook(mlx_utils.window, 17, 0, ft_close, &mlx_utils);
	mlx_loop(mlx_utils.mlx);
}
