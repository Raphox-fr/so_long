# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raphox <raphox@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:01:28 by raphox            #+#    #+#              #
#    Updated: 2024/07/03 16:05:45 by raphox           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SRCS			=	Annexe.c flood_fill.c move.c error.c hooking.c parsing_args.c init_mlx.c check_maps.c split.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c init_map.c \

OBJS			=	${SRCS:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g3

MLX_DIR 		=	mlx

all				:	${NAME}

$(NAME): $(OBJS) $(MLX_DIR)
	make -C ${MLX_DIR}
	cc $(OBJS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -o $(NAME)

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
