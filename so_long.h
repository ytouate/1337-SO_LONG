/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/08 14:38:04 by ytouate          ###   ########.fr       */
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

typedef struct  requirs {
	int	E;
	int	C;
} requirs;

typedef struct mlx_utils {
	void *mlx;
	void *window;
	int *width;
	int *height;
	void *wall;
	void *player;
	void *collectable;
	void *map_exit;
	void *land;
	int rows;
	char **map;
} mlx_utils;

typedef struct map{
	int rows;
	char **map;
}map;

typedef struct measures {
	int height;
	int width;
}measures;

char	**convert(int fd, char *file);
char	*ft_strjoin(char *s1, char const *s2);
char	*get_next_line(int fd);
void	put_collectable(mlx_utils utils, map a);
void	put_exit(mlx_utils utils, map a);
void	put_wall(mlx_utils utils, map a);
void	put_land(mlx_utils utils, map a);
void	put_player(mlx_utils utils, map a);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	check_map(map a);
void	error();
int		ft_strchr(const char *s, int c);
int		count_map_lines(char *file);
int		ft_strlen(const char *s);
int		get_x(map a);
int		get_y(map a);
t_list	*get_c_pos(int rows, char **map, char c);
t_list	*ft_lstnew(int x, int y);
valid_map	check_requirs(map a);

#endif