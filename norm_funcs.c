/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 07:32:06 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 08:27:50 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_mlx_utils *a)
{
	mlx_clear_window(a->mlx, a->window);
	mlx_destroy_window(a->mlx, a->window);
	exit(EXIT_FAILURE);
}

void	map_len_error(void)
{
	write(2, "Error: the lines of the map are not identical\n", 47);
	exit(EXIT_FAILURE);
}

void	file_format_error(void)
{
	write(1, "Error: invalid file format\n", 28);
	exit(EXIT_FAILURE);
}
