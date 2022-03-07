/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/07 15:42:18 by ytouate          ###   ########.fr       */
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
} mlx_utils;
char	**convert(int fd, char *file);
char	*ft_strjoin(char *s1, char const *s2);
char	*get_next_line(int fd);
void	put_exit(void *mlx, void *window, void *map_exit, int rows, char **map);
void	put_collectable(void *mlx, void *window, void *collectable, int rows, char **map);
void	put_wall(void *mlx, void *window, void *wall, int rows, char **map);
void	put_structure(int rows, char **map, void *mlx, void *window, void *land, void *wall);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	check_map(char **map, int rows);
void	error();
void	check_map(char **map, int rows);
void	put_land(void *mlx, void *window, void *land, int rows, char **map);
void	put_player(void *mlx, void *window, void *player, int rows, char **map);
int		ft_strchr(const char *s, int c);
int		count_map_lines(char *file);
int		ft_strlen(const char *s);
t_list	*get_c_pos(int rows, char **map, char c);
t_list	*ft_lstnew(int x, int y);
valid_map	check_requirs(char **map, int rows);
#endif