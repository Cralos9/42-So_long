# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 11:45:21 by cacarval          #+#    #+#              #
#    Updated: 2023/07/07 12:42:08 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC = srcs/main.c srcs/make_map.c srcs/utils.c srcs/moves.c srcs/sprites.c \
		srcs/check_map.c srcs/clean_game.c

SRC_BONUS = srcs_bonus/main_bonus.c srcs_bonus/make_map_bonus.c srcs_bonus/utils_bonus.c \
			srcs_bonus/moves_bonus.c srcs_bonus/sprites_bonus.c \
			srcs_bonus/check_map_bonus.c srcs_bonus/clean_game_bonus.c srcs_bonus/collectible_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

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
	${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}

all: ${NAME}

bonus:	${OBJ_BONUS}
	${MAKE} ${LIBFT_PATH}
	${MAKE} ${MLX_PATH}
	${CC} ${CFLAGS} ${OBJ_BONUS} ${LIBFT} ${MLX} -o ${NAME}

clean:
	${MAKE} ${LIBFT_PATH} clean
	${MAKE} ${MLX_PATH} clean
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT:
