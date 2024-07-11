# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 20:27:36 by iubieta           #+#    #+#              #
#    Updated: 2024/06/10 17:24:33 by iubieta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm
INCLUDES = -I./include -I./libs/libft -I./libs/printf -I./libs/minilibx
LIBS = -L./libs/libft -lft -L./libs/printf -lftprintf -L./libs/minilibx -lmlx -lXext -lX11 -lm 
MAKEFLAGS = --no-print-directory

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

.PHONY: all clean fclean re

all: libs $(NAME)
	@echo "DONE"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "EVERYTHING COMPILED\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libs: libft printf minilibx

libft:
	@$(MAKE) -C ./libs/libft

printf:
	@$(MAKE) -C ./libs/printf

minilibx:
	@$(MAKE) -C ./libs/minilibx

clean:
	@$(MAKE) -C ./libs/printf fclean
	@$(MAKE) -C ./libs/libft fclean
	@$(MAKE) -C ./libs/minilibx clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
