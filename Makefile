# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 14:10:01 by ybenbrai          #+#    #+#              #
#    Updated: 2022/11/15 16:50:22 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c tools.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

CC = gcc
# LIB = libft/libft.a
FLAGS = #-Wall -Wextra -Werror -fsanitize=address

all :$(NAME) 


$(NAME) : $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling ft_printf ..."
	@$(CC) $(FLAGS) $(OBJ) -lreadline -o $(NAME)
	@echo "\n\033[0mCompilation Done !"

%.o : %.c  $(HEADER)
	@printf "\033[0;33mCreating ft_printf objects ... %-33.33s\r" $@
	@$(CC) $(FLAGS) -c $< -o $@
clean :
	@echo "\nDeleting ft_printf objects..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean : clean
	@echo "\nDeleting ft_printf objects..."
	@rm -f $(NAME)
	@echo "\nDeleting executable..."
	@echo "\033[0m"
re : fclean all