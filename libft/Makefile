# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 12:45:11 by cacarval          #+#    #+#              #
#    Updated: 2023/05/30 12:53:46 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_IS =		ft_isalnum.c ft_isprint.c ft_isalpha.c ft_isascii.c ft_isdigit.c 

FT_STR = 	ft_strlcat.c ft_strlen.c ft_strcmp.c ft_strchr.c  ft_strdup.c ft_strstr.c\
			ft_strnstr.c ft_strrchr.c ft_strlcpy.c ft_strncmp.c ft_strmapi.c ft_strjoin.c\
			ft_strtrim.c ft_striteri.c ft_split.c ft_substr.c

FT_PUT =	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c

FT_TO = 	ft_tolower.c ft_toupper.c ft_itoa.c

FT_MEM =	ft_memcpy.c ft_atoi.c ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c\
			ft_memmove.c ft_memset.c

FT_LST = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

FT_PRINTF =		ft_printf.c ft_printptr.c ft_printstd.c ft_printuns.c ft_printhex.c

FT_GNL =		get_next_line.c get_next_line_utils.c

SRCS = ${FT_IS} ${FT_TO} ${FT_PUT} ${FT_MEM} ${FT_LST} ${FT_STR} ${FT_PRINTF} ${FT_GNL}

OBJS = 		$(SRCS:.c=.o)
NAME = 		libft.a
HEADER =	libft.h
INCLUDE = 	-I include
CC = 		cc
RM = 		rm -f
CFLAGS = 	-Wextra -Wall -Werror
.c.o:
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS) $(HEADER)

all:		$(NAME)
		
clean:	
			@$(RM) $(OBJS)

fclean:		clean 
			@$(RM) $(NAME)

re:			fclean all

# bonus:		$(OBJS)
# 			@ar rcs $(NAME) $(OBJS) $(HEADER)

.PHONY: 	all clean fclean re bonus
