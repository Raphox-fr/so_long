# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:01:28 by raphox            #+#    #+#              #
#    Updated: 2024/05/13 15:41:21 by rafaria          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SRCS			=	Annexe.c flood_fill.c move.c error.c hooking.c parsing_args.c init_mlx.c check_maps.c split.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c init_map.c \

OBJS			=	${SRCS:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g3

all				:	${NAME}

$(NAME): $(OBJS)
	cc $(OBJS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -o $(NAME)

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
