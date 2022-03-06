# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 15:42:48 by ytouate           #+#    #+#              #
#    Updated: 2022/03/02 10:45:52 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = so_long.c gnl.c gnl_utils.c valid_map.c so_long_utils.c
all:
	cc $(OBJS) -lmlx -framework OpenGL -framework AppKit -o so_long
clean :
	rm -f so_long