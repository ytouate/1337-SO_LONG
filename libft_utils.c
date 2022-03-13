/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:54 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/13 15:18:20 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*int_to_str(char *str,	unsigned int n, long int len)
{
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static long int	return_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				sign;
	long int		len;
	char			*res;
	unsigned int	temp_n;

	len = return_len(n);
	sign = 1;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		temp_n = n * -1;
		res[0] = '-';
	}
	else
	{
		temp_n = n;
	}
	res = int_to_str(res, temp_n, len);
	return (res);
}

void	ft_putchar_fd(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i]);
		i++;
	}
	ft_putchar('\n');
}
