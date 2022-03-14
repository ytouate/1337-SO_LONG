/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:13:25 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 16:02:21 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_mlx_utils *a)
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
			ft_free(b, pos);
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		update_image_left(a, pos, b);
		print_move(&a->movs);
	}
	ft_free(b, pos);
}

void	move_down(t_mlx_utils *a)
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
			ft_free(b, pos);
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		update_image_down(a, pos, b);
		print_move(&a->movs);
	}
	ft_free(b, pos);
}

void	move_up(t_mlx_utils *a)
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
			ft_free(b, pos);
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		update_image_up(a, pos, b);
		print_move(&a->movs);
	}
	ft_free(b, pos);
}

void	move_right(t_mlx_utils *a)
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
			ft_free(b, pos);
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		update_image_right(a, pos, b);
		print_move(&a->movs);
	}
	ft_free(b, pos);
}

int	key_handler(int keycode, t_mlx_utils *a)
{
	system("leaks so_long");
	if (keycode == 2 || keycode == 124)
		move_right(a);
	else if (keycode == 13 || keycode == 126)
		move_up(a);
	else if (keycode == 0 || keycode == 123)
		move_left(a);
	else if (keycode == 1 || keycode == 125)
		move_down(a);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	else
		PASS ;
	return (0);
}
