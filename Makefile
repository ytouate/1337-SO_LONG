# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 15:42:48 by ytouate           #+#    #+#              #
#    Updated: 2022/03/14 06:09:13 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = so_long
B_NAME = so_long_bonus

MANDATORY = \
	./gnl.c  	 		\
	./gnl_utils.c   	\
	./valid_map.c   	\
	./so_long_utils.c   \
	./image_put.c  		\
	./position_utils.c  \
	./libft_utils.c 	\
	./moving_utils.c	\
	./valid_map_2.c		\
	./image_update.c	\
	./moving_funcs.c

BONUS = \
	./so_long_bonus.c		\
	./valid_map.c			\
	./valid_map_2.c			\
	./so_long_utils.c		\
	./gnl.c  	 		\
	./gnl_utils.c   	\
	./image_put.c  		\
	./position_utils.c  \
	./libft_utils.c 	\
	./so_long_bonus_utils.c \
	./moving_utils.c	\
	./image_update.c	\
	./moving_utils_bonus.c

PARTS = $(MANDATORY) $(BONUS)

OBJS = $(PARTS:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rc so_long.a $(OBJS)
	@cc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit so_long.c so_long.a -o $(NAME)

clean :
	@rm -f $(OBJS) so_long.a

fclean : clean
	@rm -f  $(NAME) $(B_NAME) so_long.a

re : fclean all

OBBS = $(BONUS:.c=.o)

$(B_NAME) : $(OBBS)
	@ar -rc so_long.a $(OBBS)
	@cc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit so_long_bonus.c so_long.a -o $(B_NAME)

bonus : $(B_NAME)

.PHONY : all clean fclean re bonus