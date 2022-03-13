/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:30:29 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/13 20:49:40 by ytouate          ###   ########.fr       */
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

void	put_moves_to_window(t_mlx_utils *a, int *c)
{
	char	*n;
	int		x_cor;

	n = ft_itoa(*c);
	x_cor = ((ft_strlen(a->a.map[0]) - 1) / 2) * 50;
	mlx_put_image_to_window(a->mlx, a->window, a->wall, x_cor, 0);
	mlx_string_put(a->mlx, a->window, x_cor, 0, 0x8df542, n);
	free(n);
}
