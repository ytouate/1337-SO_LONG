/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:58:36 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/16 07:25:15 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left_bonus(t_mlx_utils *a)
{
	t_temp_pos	p;
	t_list		*pos;
	t_boarders	b;

	b = get_boarders_pos(*a);
	p.temp_x = a->player_pos->x_cor - 50;
	p.temp_y = a->player_pos->y_cor;
	pos = ft_lstnew(p.temp_x, p.temp_y);
	if (a->status)
	{
		if (got_collided(b.boarder, pos, a, 'a') == 0)
		{
			if (got_collided(b.map_exit, pos, a, 'a'))
			{
				ft_free(b, pos);
				if (a->num_of_collects == 0)
					exit(EXIT_SUCCESS);
				return ;
			}
			update_image_left(a, pos, b);
			if (a->patrol_pos->x_cor == a->player_pos->x_cor
				&&a->patrol_pos->y_cor == a->player_pos->y_cor)
			{
				mlx_loop_hook(a->mlx, explode, a);
				a->status = 0;
			}
			put_moves_to_window(a, &a->movs);
		}
		ft_free(b, pos);
	}
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
	if (a->status == 1)
	{
		if (got_collided(b.boarder, pos, a, 'a') == 0)
		{
			if (got_collided(b.map_exit, pos, a, 'a'))
			{
				ft_free(b, pos);
				if (a->num_of_collects == 0)
					exit(EXIT_SUCCESS);
				return ;
			}
			update_image_down(a, pos, b);
			if (a->patrol_pos->x_cor == a->player_pos->x_cor
				&& a->patrol_pos->y_cor == a->player_pos->y_cor)
			{
				mlx_loop_hook(a->mlx, explode, a);
				a->status = 0;
			}
			put_moves_to_window(a, &a->movs);
		}
		ft_free(b, pos);
	}
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
	if (a->status == 1)
	{
		if (got_collided(b.boarder, pos, a, 'a') == 0)
		{
			if (got_collided(b.map_exit, pos, a, 'a'))
			{
				ft_free(b, pos);
				if (a->num_of_collects == 0)
					exit(EXIT_SUCCESS);
				return ;
			}
			update_image_up(a, pos, b);
			if (a->patrol_pos->x_cor == a->player_pos->x_cor
				&& a->patrol_pos->y_cor == a->player_pos->y_cor)
			{
				mlx_loop_hook(a->mlx, explode, a);
				a->status = 0;
			}
			put_moves_to_window(a, &a->movs);
		}
		ft_free(b, pos);
	}
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
	if (a->status == 1)
	{
		if (got_collided(b.boarder, pos, a, 'a') == 0)
		{
			if (got_collided(b.map_exit, pos, a, 'a'))
			{
				ft_free(b, pos);
				if (a->num_of_collects == 0)
					exit(EXIT_SUCCESS);
				return ;
			}
			update_image_right(a, pos, b);
			if (a->patrol_pos->x_cor == a->player_pos->x_cor
				&& a->patrol_pos->y_cor == a->player_pos->y_cor)
			{
				a->status = 0;
				mlx_loop_hook(a->mlx, explode, a);
			}
			put_moves_to_window(a, &a->movs);
		}
		ft_free(b, pos);
	}
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
