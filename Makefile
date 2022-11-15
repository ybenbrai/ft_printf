# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 14:10:01 by ybenbrai          #+#    #+#              #
#    Updated: 2022/11/15 17:00:00 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
SRC = main.c ft_printf.c tools.c

OBJ = $(SRC:.c=.o)


CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

all :$(NAME) 


$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o:%.c  $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
re : fclean all