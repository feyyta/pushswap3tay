# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastrat <mcastrat@student.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 12:00:00 by mcastrat          #+#    #+#              #
#    Updated: 2025/09/29 12:00:00 by mcastrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I inc/ -I libft/inc/

SRC = src/main.c src/utils.c src/init.c \
	src/operations.c src/rotations.c src/push_operations.c \
	src/sorting_algorithm.c src/simple_sorts.c src/utils_algo.c src/utils_sort.c \

OBJ_DIR = objects/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ_DIR)%.o: src/%.c inc/push_swap.h
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re