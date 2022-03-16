/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 07:32:06 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/16 16:59:07 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*when to press the left red button at the top left*/
int	ft_close(t_mlx_utils *a)
{
	mlx_clear_window(a->mlx, a->window);
	mlx_destroy_window(a->mlx, a->window);
	exit(EXIT_FAILURE);
}

/*if the map has unidentical lines*/
void	map_len_error(void)
{
	write(2, "Error: the lines of the map are not identical\n", 47);
	exit(EXIT_FAILURE);
}

/*if the format of the file is not correct */
void	file_format_error(void)
{
	write(1, "Error: invalid file format\n", 28);
	exit(EXIT_FAILURE);
}

/*prints the moves to the shell*/
void	print_move(int *c)
{
	char	*n;

	n = ft_itoa(*c);
	ft_putstr(n);
	free(n);
}
