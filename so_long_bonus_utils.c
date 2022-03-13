/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:30:29 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/13 18:50:39 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx_utils mlx_utils, t_map a)
{
	put_land(mlx_utils, a);
	put_wall(mlx_utils, a);
	put_exit(mlx_utils, a);
	put_player(mlx_utils, a);
	put_collectable(mlx_utils, a);
}

t_boarders	get_boarders_pos(t_mlx_utils a)
{
	t_boarders	b;

	b.boarder = get_c_pos(a.a.rows, a.a.map, '1');
	b.collectable_pos = get_c_pos(a.a.rows, a.a.map, 'C');
	b.map_exit = get_c_pos(a.a.rows, a.a.map, 'E');
	return (b);
}

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

void put_moves_to_window(t_mlx_utils *a, int *c)
{
	char	*n;
	int		x_cor;

	n = ft_itoa(*c);
	x_cor = ((ft_strlen(a->a.map[0]) - 1) / 2) * 50;
	mlx_put_image_to_window(a->mlx, a->window, a->wall, x_cor, 0);
	mlx_string_put(a->mlx, a->window, x_cor, 0, 0x8df542, n);
	free(n);
}

void	move_left_bonus(t_mlx_utils *a)
{
	t_temp_pos	p;
	t_list		*pos;
	t_boarders	b;

	b = get_boarders_pos(*a);
	p.temp_x = a->player_pos->x_cor - 50;
	p.temp_y = a->player_pos->y_cor;
	pos = ft_lstnew(p.temp_x, p.temp_y);
	if (got_collided(b.boarder, pos) == 0)
	{
		if (got_collided(b.map_exit, pos))
		{
			if (a->num_of_collects <= 0)
			{
				ft_free(b, pos);
				exit(EXIT_SUCCESS);
			}
			return ;
		}
		update_image_left(a, pos, b);
		put_moves_to_window(a, &a->movs);
	}
	ft_free(b, pos);
}

void	move_down_bonus(t_mlx_utils *a)
{
	int			temp_x;
	int			temp_y;
	t_list		*pos;
	t_boarders	b;

	b = get_boarders_pos(*a);
	temp_x = a->player_pos->x_cor;
	temp_y = a->player_pos->y_cor + 50;
	pos = ft_lstnew(temp_x, temp_y);
	if (got_collided(b.boarder, pos) == 0)
	{
		if (got_collided(b.map_exit, pos))
		{
			if (a->num_of_collects <= 0)
			{
				ft_free(b, pos);
				exit(EXIT_SUCCESS);
			}
			return ;
		}
		update_image_down(a, pos, b);
		put_moves_to_window(a, &a->movs);
	}
	ft_free(b, pos);
}

void	move_up_bonus(t_mlx_utils *a)
{
	int			temp_x;
	int			temp_y;
	t_list		*pos;
	t_boarders	b;

	b = get_boarders_pos(*a);
	temp_x = a->player_pos->x_cor;
	temp_y = a->player_pos->y_cor - 50;
	pos = ft_lstnew(temp_x, temp_y);
	if (got_collided(b.boarder, pos) == 0)
	{
		if (got_collided(b.map_exit, pos))
		{
			if (a->num_of_collects <= 0)
			{
				ft_free(b, pos);
				exit(EXIT_SUCCESS);
			}
			return ;
		}
		update_image_up(a, pos, b);
		put_moves_to_window(a, &a->movs);
	}
	ft_free(b, pos);
}

void	move_right_bonus(t_mlx_utils *a)
{
	t_temp_pos	p;
	t_list		*pos;
	t_boarders	b;

	b = get_boarders_pos(*a);
	p.temp_x = a->player_pos->x_cor + 50;
	p.temp_y = a->player_pos->y_cor;
	pos = ft_lstnew(p.temp_x, p.temp_y);
	if (got_collided(b.boarder, pos) == 0)
	{
		if (got_collided(b.map_exit, pos))
		{
			if (a->num_of_collects <= 0)
			{
				ft_free(b, pos);
				exit(EXIT_SUCCESS);
			}
			return ;
		}
		update_image_right(a, pos, b);
		put_moves_to_window(a, &a->movs);
	}
	ft_free(b, pos);
}

int	key_handler_bonus(int keycode, t_mlx_utils *a)
{
	if (keycode == 2 || keycode == 124)
		move_right_bonus(a);
	else if (keycode == 13 || keycode == 126)
		move_up_bonus(a);
	else if (keycode == 0 || keycode == 123)
		move_left_bonus(a);
	else if (keycode == 1 || keycode == 125)
		move_down_bonus(a);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	else
		PASS ;
	return (0);
}
