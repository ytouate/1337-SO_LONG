# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 15:42:48 by ytouate           #+#    #+#              #
#    Updated: 2022/03/13 15:35:08 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = so_long

OBJS = \
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

PARTS = $(OBJS:.c=.o)

all : $(NAME)

$(NAME) : $(PARTS)
	@ar -rc so_long.a $(PARTS)
	@cc $(CFLAGS) $(PARTS) -lmlx -framework OpenGL -framework AppKit so_long.c so_long.a -o $(NAME)

clean :
	@rm -f $(PARTS) so_long.a