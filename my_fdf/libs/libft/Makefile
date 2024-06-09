# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 15:38:39 by iubieta-          #+#    #+#              #
#    Updated: 2024/06/09 21:09:00 by iubieta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = libft.h
SRCS = $(shell find "." -name "*.c")			
OBJS = ${SRCS:.c=.o}
BONUS = $(shell find "." -name "*_bonus.c")
BONUS_OBJS = ${BONUS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar csr
RM = rm -rf

all : ${OBJS} $(NAME)
	@echo "LIBFT COMPILED"

${NAME} : ${OBJS} ${INCLUDE}
	${AR} ${NAME} $^

bonus: ${OBJS} ${BONUS_OBJS} ${INCLUDE}
	${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re bonus