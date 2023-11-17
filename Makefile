# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 22:20:22 by jaqribei          #+#    #+#              #
#    Updated: 2023/11/10 22:43:49 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra -g3

INCLUDES = -I ./libft

SRC = push_swap.c check_errors.c a_moves.c b_moves.c ab_moves.c nodes_actions.c \
	stack_utilities.c stack_operations.c stack_specific_size_handlers.c \
	stack_checks.c

OBJ = $(SRC:.c=.o)

all:libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) ./libft/libft.a -o $(NAME)
	@echo "\033[32m[✓] \033[1m\033[1m$(NAME) created\033[1m"

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[32m[✓] \033[1m\033[1m$@ created\033[1m"

libft:
	@make -C ./libft
	@echo "\033[32m[✓] \033[1m\033[1mlibft created\033[1m"

clean:
	rm -f $(OBJ) 
	@make clean -C ./libft
	
fclean: clean
	rm -f $(NAME)
	@echo "\033[31m[✗] \033[1m\033[1m$(NAME) deleted\033[1m"

norm:
	norminette -R CheckForbiddenSourceHeader
	@echo "\033[32m[✓] \033[0m\033[1mNorminette done\033[0m"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re norm libft
