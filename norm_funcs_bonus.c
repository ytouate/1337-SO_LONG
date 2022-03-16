/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 06:56:14 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/16 16:59:31 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*ends the game if the player touched the patrol*/
void	game_over(void)
{
	write (1, "You touched the trap GAME OVER\n", 32);
	exit(EXIT_SUCCESS);
}
