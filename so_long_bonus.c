/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:27:12 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/13 21:01:46 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int lst_size(t_list *head)
{
	int count;
	count = 0;
	while (head->next)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_list *pick_node(t_list *head, int n)
{
	int i;
	i = 0;
	while (i != n)
	{
		head = head->next;
		i++;
	}
	return (head);
}

void get_patrol_pos(t_mlx_utils *utils)
{
	t_list	*land;
	int		size;
	int		rand_num;

	land = get_c_pos(utils->a.rows, utils->a.map, '0');
	size = lst_size(land);
	rand_num = rand() % (size - 0 + 1);
	utils->patrol_pos = pick_node(land, rand_num);
	utils->patrol = mlx_xpm_file_to_image(utils->mlx, "/Users/ytouate/Desktop/so_long/pics/bomb.xpm", utils->height, utils->width);
	mlx_put_image_to_window(utils->mlx, utils->window, utils->patrol, utils->patrol_pos->x_cor, utils->patrol_pos->y_cor);
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
	mlx_utils.num_of_collects = b.collectable;
	init_image(&mlx_utils);
	put_image(mlx_utils, mlx_utils.a);
	get_patrol_pos(&mlx_utils);
	mlx_key_hook(mlx_utils.window, key_handler_bonus, &mlx_utils);
	mlx_loop(mlx_utils.mlx);
}
