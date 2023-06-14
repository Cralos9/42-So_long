# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 11:45:21 by cacarval          #+#    #+#              #
#    Updated: 2023/06/14 12:13:47 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC = srcs/main.c srcs/map.c srcs/utils.c srcs/moves.c srcs/sprites.c

OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
MLX_PATH = mlx
LIBFT = -L ${LIBFT_PATH} -lft
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
	${MAKE} ${LIBFT_PATH}
	${MAKE} ${MLX_PATH}
	${CC} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}

all: ${NAME}

clean:
	${MAKE} ${LIBFT_PATH} clean
	${MAKE} ${MLX_PATH} clean
	${RM} ${OBJ}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT:
