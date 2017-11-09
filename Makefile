#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askochen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 17:18:28 by askochen          #+#    #+#              #
#    Updated: 2016/12/22 14:20:14 by askochen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRC = check.c main.c my_list.c read.c solve.c \
min_max.c matrix.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
all:$(NAME)
$(NAME):
	gcc -c $(FLAGS) $(SRC) libft.h fillit.h
	gcc -o $(NAME) $(OBJ) libft.a
clean:
	rm -f $(OBJ) fillit.h.gch libft.h.gch
fclean: clean
	rm -f $(NAME)
re: fclean all