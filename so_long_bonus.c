/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:27:12 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 18:49:55 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	split_main(t_mlx_utils *a, t_map b)
{
	init_image(a);
	put_image(*a, b);
	get_patrol_pos(a);
}
// int i = 0;

// int func(t_mlx_utils *a)
// {
// 	// printf("am here\n");
// 	static int i;
// 	printf("%d\n", i);
// 	if (i <= 30)
// 	{
// 		mlx_put_image_to_window(a->mlx, a->window, a->land, 0, 0);
// 		//mlx_put_image_to_window(a->mlx, a->window, a->wall, 0, 0);
// 	}
// 	else if (i <= 60)
// 	{
// 		//mlx_put_image_to_window(a->mlx, a->window, a->land, 0, 0);
// 		mlx_put_image_to_window(a->mlx, a->window, a->wall, 0, 0);
// 	}
// 	else if (i <= 120)
// 		mlx_put_image_to_window()
// 	else if (i == 80)
// 		i = 0;
// 	i++;
// 	return (0);
// }

t_explosion_vars	init_explosion(t_mlx_utils *a)
{
	t_explosion_vars var;
	var.a = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/1.xpm", a->width, a->height);
	var.b = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/2.xpm", a->width, a->height);
	var.c = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/3.xpm", a->width, a->height);
	var.d = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/4.xpm", a->width, a->height);
	var.e = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/5.xpm", a->width, a->height);
	var.f = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/6.xpm", a->width, a->height);
	var.g = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/7.xpm", a->width, a->height);
	var.h = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/8.xpm", a->width, a->height);
	var.i = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/9.xpm", a->width, a->height);
	var.j = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/10.xpm", a->width, a->height);
	var.k = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/11.xpm", a->width, a->height);
	var.l = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/12.xpm", a->width, a->height);
	var.m = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/13.xpm", a->width, a->height);
	var.n = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/14.xpm", a->width, a->height);
	var.o = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/15.xpm", a->width, a->height);
	var.p = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/bomb/16.xpm", a->width, a->height);
	return (var);
}

int explode(t_mlx_utils *a)
{
	t_explosion_vars var = init_explosion(a);
	static int i;
	if (i <= 20)
		mlx_put_image_to_window(a->mlx, a->window, var.a, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 40)
	mlx_put_image_to_window(a->mlx, a->window, var.b, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 60)
		mlx_put_image_to_window(a->mlx, a->window, var.c, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 80)
		mlx_put_image_to_window(a->mlx, a->window, var.d, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 100)
		mlx_put_image_to_window(a->mlx, a->window, var.e, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 110)
		mlx_put_image_to_window(a->mlx, a->window, var.f, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 120)
		mlx_put_image_to_window(a->mlx, a->window, var.g, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 130)
		mlx_put_image_to_window(a->mlx, a->window, var.h, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 140)
		mlx_put_image_to_window(a->mlx, a->window, var.i, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 150)
		mlx_put_image_to_window(a->mlx, a->window, var.j, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 160)
		mlx_put_image_to_window(a->mlx, a->window, var.k, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 170)
		mlx_put_image_to_window(a->mlx, a->window, var.l, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 180)
		mlx_put_image_to_window(a->mlx, a->window, var.m, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 190)
		mlx_put_image_to_window(a->mlx, a->window, var.n, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 200)
		mlx_put_image_to_window(a->mlx, a->window, var.o, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 210)
		mlx_put_image_to_window(a->mlx, a->window, var.p, a->patrol_pos->x_cor, a->patrol_pos->y_cor);
	else if (i <= 220)
		exit(EXIT_FAILURE);
	i++;
	return (0);
	
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
	split_main(&mlx_utils, mlx_utils.a);
	
	mlx_key_hook(mlx_utils.window, key_handler_bonus, &mlx_utils);
	mlx_hook(mlx_utils.window, 17, 0, ft_close, &mlx_utils);
	mlx_loop(mlx_utils.mlx);
}
