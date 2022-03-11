/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:07:27 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/10 20:24:53 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (0 <= nbr && nbr <= 9)
	{
		ft_putchar(nbr + '0');
	}
}
void    ft_printf(int n)
{
    ft_putnbr(n);
    ft_putchar('\n');
}
int main()
{
    ft_printf(90909);
}