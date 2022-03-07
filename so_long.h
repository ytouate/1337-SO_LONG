/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/07 12:51:26 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define pass (void)0

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct valid_map
{
	int collectable;
	int map_exit;
	int starting_pos;
}valid_map;

typedef struct s_list {
	int x_cor;
	int y_cor;
	struct s_list *next;
}t_list;

char	**convert(int fd, char *file);
char	*ft_strjoin(char *s1, char const *s2);
char	*get_next_line(int fd);
void	check_map(char **map, int rows);
void	check_map(char **map, int rows);
valid_map	check_requirs(char **map, int rows);
void	error();
int		ft_strchr(const char *s, int c);
int		count_map_lines(char *file);
int	ft_strlen(const char *s);

#endif