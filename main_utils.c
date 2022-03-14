/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 07:36:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 07:40:57 by ytouate          ###   ########.fr       */
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
	a->map_exit = mlx_xpm_file_to_image(a->mlx, "exit.xpm",
			a->width, a->height);
	a->player = mlx_xpm_file_to_image(a->mlx, "player_right.xpm",
			a->width, a->height);
	a->collectable = mlx_xpm_file_to_image(a->mlx, "collectable.xpm",
			a->width, a->height);
	a->land = mlx_xpm_file_to_image(a->mlx, "land.xpm",
			a->width, a->height);
	a->wall = mlx_xpm_file_to_image(a->mlx, "pic.xpm",
			a->width, a->height);
	a->player_pos = get_c_pos(a->a.rows, a->a.map, 'P');
}

void	error(void)
{
	write(2, "Error: map not found\n", 22);
	exit(EXIT_FAILURE);
}