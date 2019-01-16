# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 17:04:30 by marvin            #+#    #+#              #
#    Updated: 2019/01/16 18:42:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap
NAME_CHECK = checker

vpath %.c srcs/checker srcs/push_swap srcs/operations
vpath %.h includes
vpath %.o bin

FLAGS = -Wall -Wextra -Werror

OBJ_PUSH = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/push_swap/*.c))))
OBJ_CHECK = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/checker/*.c))))
OBJ_OPER = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/operations/*.c))))

LIB = libft/libft.a

all: make_lib $(NAME_PUSH) $(NAME_CHECK)

make_lib:
	make -C libft/

$(NAME_PUSH): $(OBJ_PUSH) $(OBJ_OPER) $(LIB)
	gcc $(FLAGS) $^ -o $@ -Iincludes -Ilibft/includes -Llibft -lft

$(NAME_CHECK): $(OBJ_CHECK) $(OBJ_OPER) $(LIB)
	gcc $(FLAGS) $^ -o $@ -Iincludes -Ilibft/includes -Llibft -lft

bin/%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -Iincludes -Ilibft/includes

clean:
	rm -f bin/*.o
	rm -f libft/bin/*.o

fclean: clean
	rm -f $(NAME_PUSH)
	rm -f $(NAME_CHECK)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re make_lib
