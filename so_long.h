/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:42:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/14 18:48:28 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define PASS (void)0

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>

typedef struct t_valid_t_map
{
	int	collectable;
	int	map_exit;
	int	starting_pos;
}t_valid_map;

typedef struct s_list {
	int				x_cor;
	int				y_cor;
	struct s_list	*next;
}t_list;

typedef struct t_map{
	int		rows;
	char	**map;
}t_map;

typedef struct boarders {
	t_list	*boarder;
	t_list	*collectable_pos;
	t_list	*map_exit;
}t_boarders;

typedef struct t_mlx_utils {
	void	*mlx;
	void	*window;
	int		*width;
	int		*height;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*map_exit;
	void	*land;
	void	*patrol;
	t_list	*player_pos;
	t_map	a;
	int		movs;
	int		num_of_collects;
	t_list	*patrol_pos;
}t_mlx_utils;

typedef struct measures {
	int	height;
	int	width;
}t_measures;

typedef struct temp_pos {
	int	temp_x;
	int	temp_y;
}t_temp_pos;

typedef struct vars {
	int	i;
	int	j;
	int	x_cor;
	int	y_cor;
	int	k;
	int	p;
}t_vars;

typedef struct explosion {
	void	*a;
	void	*b;
	void	*c;
	void	*d;
	void	*e;
	void	*f;
	void	*g;
	void	*h;
	void	*i;
	void	*j;
	void	*k;
	void	*l;
	void	*m;
	void	*n;
	void	*o;
	void	*p;
}t_explosion_vars;

char		**convert(int fd, char *file);
char		*ft_strjoin(char *s1, char const *s2);
char		*get_next_line(int fd);
char		*ft_itoa(int n);
void		put_collectable(t_mlx_utils utils, t_map a);
void		put_exit(t_mlx_utils utils, t_map a);
void		put_wall(t_mlx_utils utils, t_map a);
void		put_land(t_mlx_utils utils, t_map a);
void		put_player(t_mlx_utils utils, t_map a);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		check_map(t_map a);
void		move_left(t_mlx_utils *a);
void		move_down(t_mlx_utils *a);
void		move_up(t_mlx_utils *a);
void		move_right(t_mlx_utils *a);
void		ft_putnbr(int i);
void		ft_printf(int n);
void		ft_putchar(int c);
void		ft_putstr(char *s);
void		check_first_line(char *line);
void		check_last_line(char *line);
void		map_len_error(void);
void		update_image_left(t_mlx_utils *a, t_list *pos, t_boarders b);
void		update_image_up(t_mlx_utils *a, t_list *pos, t_boarders b);
void		update_image_right(t_mlx_utils *a, t_list *pos, t_boarders b);
void		update_image_down(t_mlx_utils *a, t_list *pos, t_boarders b);
void		print_move(int *c);
void		ft_free(t_boarders b, t_list *pos);
void		put_image(t_mlx_utils mlx_utils, t_map a);
void		init_image(t_mlx_utils *a);
void		error(void);
void		move_left_bonus(t_mlx_utils *a);
void		move_down_bonus(t_mlx_utils *a);
void		move_up_bonus(t_mlx_utils *a);
void		move_right_bonus(t_mlx_utils *a);
void		put_moves_to_window(t_mlx_utils *a, int *c);
void		check_format(char *s);
void		get_patrol_pos(t_mlx_utils *utils);
void		end_game(t_boarders b, t_list *pos);
void		game_over(void);
void		file_format_error(void);
int			ft_strchr(const char *s, int c);
int			count_map_lines(char *file);
int			ft_strlen(const char *s);
int			get_x(t_map a);
int			get_y(t_map a);
int			key_handler(int keycode, t_mlx_utils *a);
int			got_collided(t_list *pos, t_list *player_pos);
int			lst_size(t_list *head);
int			key_handler_bonus(int keycode, t_mlx_utils *a);
int			ft_close(t_mlx_utils *a);
t_list		*get_c_pos(int rows, char **map, char c);
t_list		*ft_lstnew(int x, int y);
t_list		*pick_node(t_list *head, int n);
t_valid_map	check_requirs(t_map a);
t_boarders	get_boarders_pos(t_mlx_utils a);
int explode(t_mlx_utils *a);
#endif