# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 17:04:30 by marvin            #+#    #+#              #
#    Updated: 2019/01/16 15:19:57 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap
NAME_CHECK = checker

vpath %.c srcs
vpath %.h includes
vpath %.o bin

FLAGS = -Wall -Wextra -Werror

OBJ_PUSH = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/push_swap/*.c))))
OBJ_CHECK = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/checker/*.c))))

LIB = libft/libft.a

all: $(NAME_PUSH) $(NAME_CHECK)

$(NAME_PUSH): $(OBJ_PUSH)
	gcc $(FLAGS) $^ -o $@ -Iincludes -Llibft -lft

$(NAME_CHECK): $(OBJ_CHECK)
	gcc $(FLAGS) $^ -o $@ -Iincludes -Llibft -lft

bin/%.o: srcs/push_swap/%.c srcs/checker/%.c
	gcc $(FLAGS) -c $< -o $@ -Iincludes

clean:
	rm -f bin/*.o
	rm -f libft/bin/*.o

fclean: clean
	rm -f $(NAME_PUSH)
	rm -f $(NAME_CHECK)

re: fclean all

.PHONY: all clean fclean re
