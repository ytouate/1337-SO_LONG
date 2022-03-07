# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 15:42:48 by ytouate           #+#    #+#              #
#    Updated: 2022/03/07 12:50:54 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
OBJS = so_long.c gnl.c gnl_utils.c valid_map.c so_long_utils.c
all:
	cc $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o so_long
clean :
	rm -f so_long