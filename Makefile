# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppatel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 16:35:37 by ppatel            #+#    #+#              #
#    Updated: 2016/12/08 17:45:39 by ppatel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  check_fillit.c \
	  fillit_data.c \
	  sol_fillit.c \
	  libft.c

OBJ = main.o \
	  check_fillit.o \
	  fillit_data.o \
	  sol_fillit.o \
	  libft.o

$(NAME):
		gcc $(FLAGS) -c $(SRC) -I Include
		gcc $(FLAGS) $(OBJ) -o $(NAME)

.PHONY: clean fclean

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
