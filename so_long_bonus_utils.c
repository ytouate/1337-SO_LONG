/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:30:29 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/16 16:56:06 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lst_size(t_list *head)
{
	int	count;

	count = 0;
	while (head->next)
	{
		count++;
		head = head->next;
	}
	return (count);
}

/*returns a random node depending on the given number */
t_list	*pick_node(t_list *head, int n)
{
	int	i;

	i = 0;
	while (i != n)
	{
		head = head->next;
		i++;
	}
	return (head);
}

/*sets the patrol position randomly using the rand function */
void	get_patrol_pos(t_mlx_utils *utils)
{
	t_list	*land;
	t_list	*temp;
	int		size;
	int		rand_num;

	land = get_c_pos(utils->a.rows, utils->a.map, '0');
	size = lst_size(land) - 1;
	rand_num = rand() % (size - 0 + 1);
	temp = pick_node(land, rand_num);
	utils->patrol_pos = ft_lstnew(temp->x_cor, temp->y_cor);
	temp = NULL;
	utils->patrol = mlx_xpm_file_to_image(utils->mlx, "bomb.xpm",
			utils->size, utils->size);
	mlx_put_image_to_window(utils->mlx, utils->window, utils->patrol,
		utils->patrol_pos->x_cor, utils->patrol_pos->y_cor);
	while (land)
	{
		temp = land;
		land = land->next;
		free(temp);
	}
	free(land);
}

/*printf the number of moves on the screen */
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
