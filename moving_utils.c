/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:19:41 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/13 15:18:08 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_boarders b, t_list *pos)
{
	t_list	*temp;

	while (b.boarder)
	{
		temp = b.boarder;
		b.boarder = b.boarder->next;
		free(temp);
	}
	while (b.collectable_pos)
	{
		temp = b.collectable_pos;
		b.collectable_pos = b.collectable_pos->next;
		free(temp);
	}
	while (b.map_exit)
	{
		temp = b.map_exit;
		b.map_exit = b.map_exit->next;
		free(temp);
	}
	free(b.boarder);
	free(b.collectable_pos);
	free(b.map_exit);
	free(pos);
}

void	print_move(int *c)
{
	char	*n;

	n = ft_itoa(*c);
	ft_putstr(n);
	free(n);
}

int	got_collided(t_list *pos, t_list *player_pos)
{
	while (pos->next)
	{
		if (pos->x_cor == player_pos->x_cor && pos->y_cor == player_pos->y_cor)
			return (1);
		pos = pos->next;
	}
	return (0);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new ->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int x, int y)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> x_cor = x;
	list -> y_cor = y;
	list -> next = NULL;
	return (list);
}
