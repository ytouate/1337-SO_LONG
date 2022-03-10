# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 15:42:48 by ytouate           #+#    #+#              #
#    Updated: 2022/03/10 17:25:35 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CFLAGS = -Wall -Wextra -Werror
NAME = so_long

OBJS = \
	./so_long.c  		\
	./gnl.c  	 		\
	./gnl_utils.c   	\
	./valid_map.c   	\
	./so_long_utils.c   \
	./image_put.c  		\
	./position_utils.c  \
	./libft_utils.c 	\
	./moving_utils.c	\

all:
	cc $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean :
	rm -f so_long