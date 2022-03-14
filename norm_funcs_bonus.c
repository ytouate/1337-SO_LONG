/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 06:56:14 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 06:57:44 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(void)
{
	ft_free(b, pos);
	exit(EXIT_SUCCESS);
}

void	game_over(void)
{
	write (1, "You touched the trap GAME OVER\n", 32);
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
