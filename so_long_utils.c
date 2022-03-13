/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:45:06 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/12 15:03:16 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_lines(char *file)
{
	char	*temp;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	count = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		count++;
		free(temp);
		temp = get_next_line(fd);
	}
	temp = NULL;
	close(fd);
	return (count);
}

char	**convert(int fd, char *file)
{
	int		i;
	int		j;
	char	**s;

	j = count_map_lines(file);
	i = 0;
	s = malloc(sizeof(char *) * j);
	if (!s)
		return (NULL);
	while (i < j)
	{
		s[i] = get_next_line(fd);
		i++;
	}
	return (s);
}
void ft_putchar(int c)
{
    write(1, &c, 1);
}
void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (0 <= nbr && nbr <= 9)
	{
		putchar(nbr + '0');
	}
}
void    ft_printf(int n)
{
    ft_putnbr(n);
    ft_putchar('\n');
}