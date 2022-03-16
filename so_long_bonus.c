/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:27:12 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/16 16:47:06 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	split_main(t_mlx_utils *a, t_map b)
{
	init_image(a);
	put_image(*a, b);
	get_patrol_pos(a);
}

int	main(int ac, char **av)
{
	int			fd;
	t_mlx_utils	mlx_utils;
	int			temp;
	t_valid_map	b;

	mlx_utils.size = &temp;
	check_format(av[1]);
	if (ac != 2)
		exit(EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error();
	mlx_utils.a.map = convert(fd, av[1]);
	mlx_utils.a.rows = count_map_lines(av[1]);
	b = check_requirs(mlx_utils.a);
	check_map(mlx_utils.a);
	mlx_utils.num_of_collects = b.collectable;
	mlx_utils.status = mlx_utils.status;
	split_main(&mlx_utils, mlx_utils.a);
	mlx_utils.temp_collectable_pos = ft_lstnew(0, 0);
	mlx_hook(mlx_utils.window, 17, 0, ft_close, &mlx_utils);
	mlx_key_hook(mlx_utils.window, key_handler_bonus, &mlx_utils);
	mlx_loop(mlx_utils.mlx);
}
