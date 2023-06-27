# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otitebah <otitebah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 17:46:54 by otitebah          #+#    #+#              #
#    Updated: 2023/02/17 17:13:14 by otitebah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FILES = pipex.c childs.c
CFLAGS = -Wall -Wextra -Werror
CC = cc
INCLUDES = libft/libft.a
OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)

clean :
	rm -f libft/*.o
	rm -f $(OBJ)

fclean : clean
	rm -f libft/libft.a
	rm -f $(NAME)

re : fclean all