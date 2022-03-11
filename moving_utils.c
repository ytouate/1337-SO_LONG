/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:19:41 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/11 21:30:21 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
void print_move(int *c)
{
	char *n;
	n = ft_itoa(*c);
	ft_putstr(n);
	free (n);
}
void	move_left(t_mlx_utils *a)
{
	int			temp_x;
	int			temp_y;
	t_list		*pos;
	t_boarders	b;

	b = get_boarders_pos(*a);
	temp_x = a->player_pos->x_cor - 50;
	temp_y = a->player_pos->y_cor;
	pos = ft_lstnew(temp_x, temp_y);
	if (got_collided(b.boarder, pos) == 0)
	{
		if (got_collided(b.map_exit, pos))
		{
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		a->player_pos->x_cor -= 50;
		a->player = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/pics/player_left.xpm",
		a->width, a->height);
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		mlx_put_image_to_window(a->mlx, a->window, a->player,
			a->player_pos->x_cor, a->player_pos->y_cor);
		if (got_collided(b.collectable_pos, pos))
			a->num_of_collects -= 1;
		a->movs++;
		print_move(&a->movs);
	}
	free(pos);
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
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		a->player_pos->y_cor += 50;
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		mlx_put_image_to_window(a->mlx, a->window, a->player,
			a->player_pos->x_cor, a->player_pos->y_cor);
		if (got_collided(b.collectable_pos, pos))
			a->num_of_collects -= 1;
		a->movs++;
		print_move(&a->movs);
	}
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
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		a->player_pos->y_cor -= 50;
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		mlx_put_image_to_window(a->mlx, a->window, a->player,
			a->player_pos->x_cor, a->player_pos->y_cor);
		if (got_collided(b.collectable_pos, pos))
			a->num_of_collects -= 1;
		a->movs++;
		print_move(&a->movs);
	}
}

void	move_right(t_mlx_utils *a)
{
	int			temp_x;
	int			temp_y;
	t_list		*pos;
	t_boarders	b;

	b = get_boarders_pos(*a);
	temp_x = a->player_pos->x_cor + 50;
	temp_y = a->player_pos->y_cor;
	pos = ft_lstnew(temp_x, temp_y);
	if (got_collided(b.boarder, pos) == 0)
	{
		if (got_collided(b.map_exit, pos))
		{
			if (a->num_of_collects <= 0)
				exit(EXIT_SUCCESS);
			return ;
		}
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		a->player_pos->x_cor += 50;
		mlx_put_image_to_window(a->mlx, a->window, a->land,
			a->player_pos->x_cor, a->player_pos->y_cor);
		a->player = mlx_xpm_file_to_image(a->mlx, "/Users/ytouate/Desktop/so_long/pics/player_right.xpm",
		a->width, a->height);
		mlx_put_image_to_window(a->mlx, a->window, a->player,
			a->player_pos->x_cor, a->player_pos->y_cor);
		if (got_collided(b.collectable_pos, pos))
			a->num_of_collects -= 1;
		a->movs++;
		print_move(&a->movs);
	}
}

int	key_handler(int keycode, t_mlx_utils *a)
{
	if (keycode == 2 || keycode == 124)
		move_right(a);
	else if (keycode == 13 || keycode == 126)
		move_up(a);
	else if (keycode == 0 || keycode == 123)
		move_left(a);
	else if (keycode == 1 || keycode == 125)
		move_down(a);
	else if (keycode == 53 )
		exit(EXIT_SUCCESS);
	else
		pass ;
	return (0);
}