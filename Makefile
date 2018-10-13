# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnegura <mnegura@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 13:16:40 by mnegura           #+#    #+#              #
#    Updated: 2017/02/09 21:09:42 by mnegura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC = marina.c\
	print.c\
	key.c\
	init.c\
	aux.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a:
	@make -C libft

minilibx/libmlx.a:
	@make -C libmlx.a

$(NAME): libft/libft.a
	gcc $(FLAGS) -I /libft/libft.h -c $(SRC)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -lm -Llibft -lft -lmlx -lXext -lX11

$(OBJ):
	@gcc -c $(FLAGS) -o $@ $*.c

clean:
	@make -C libft/ fclean
	@make -C minilibx/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
