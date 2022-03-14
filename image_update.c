/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:09:19 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 07:15:34 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_image_left(t_mlx_utils *a, t_list *pos, t_boarders b)
{
	mlx_put_image_to_window(a->mlx, a->window, a->land,
		a->player_pos->x_cor, a->player_pos->y_cor);
	a->player_pos->x_cor -= 50;
	a->player = mlx_xpm_file_to_image(a->mlx, "player_left.xpm",
			a->width, a->height);
	mlx_put_image_to_window(a->mlx, a->window, a->land,
		a->player_pos->x_cor, a->player_pos->y_cor);
	mlx_put_image_to_window(a->mlx, a->window, a->player,
		a->player_pos->x_cor, a->player_pos->y_cor);
	if (got_collided(b.collectable_pos, pos))
		a->num_of_collects -= 1;
	a->movs++;
}

void	update_image_up(t_mlx_utils *a, t_list *pos, t_boarders b)
{
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
}

void	update_image_right(t_mlx_utils *a, t_list *pos, t_boarders b)
{
	mlx_put_image_to_window(a->mlx, a->window, a->land,
		a->player_pos->x_cor, a->player_pos->y_cor);
	a->player_pos->x_cor += 50;
	mlx_put_image_to_window(a->mlx, a->window, a->land,
		a->player_pos->x_cor, a->player_pos->y_cor);
	a->player = mlx_xpm_file_to_image(a->mlx, "player_right.xpm",
			a->width, a->height);
	mlx_put_image_to_window(a->mlx, a->window, a->player,
		a->player_pos->x_cor, a->player_pos->y_cor);
	if (got_collided(b.collectable_pos, pos))
		a->num_of_collects -= 1;
	a->movs++;
}

void	update_image_down(t_mlx_utils *a, t_list *pos, t_boarders b)
{
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
}

void	put_image(t_mlx_utils mlx_utils, t_map a)
{
	put_land(mlx_utils, a);
	put_wall(mlx_utils, a);
	put_exit(mlx_utils, a);
	put_player(mlx_utils, a);
	put_collectable(mlx_utils, a);
}
