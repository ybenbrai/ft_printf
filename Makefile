# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 14:10:01 by ybenbrai          #+#    #+#              #
#    Updated: 2022/11/15 18:33:21 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = main.c tools.c ft_printf.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

CC = gcc
FLAGS = -Wall -Wextra -Werror 

all :$(NAME) 


$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -lreadline -o $(NAME)

%.o : %.c  $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
re : fclean all

# NAME = libftprintf.a

# SRC = main.c tools.c ft_printf.c

# OBJ = $(SRC:.c=.o)

# HEADER = ft_printf.h

# CC = gcc
# FLAGS = -Wall -Wextra -Werror

# all :$(NAME)


# $(NAME) : $(OBJ)
# 	ar -rcs $(NAME) $(OBJ)

# %.o : %.c  $(HEADER)
# 	@$(CC) $(FLAGS) -c $< -o $@
# clean :
# 	@rm -f $(OBJ)

# fclean : clean
# 	@rm -f $(NAME)
# re : fclean all