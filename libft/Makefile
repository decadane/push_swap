# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 17:04:30 by marvin            #+#    #+#              #
#    Updated: 2019/01/26 19:27:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

vpath %.c srcs
vpath %.h includes
vpath %.o bin

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/*.c))))

all: makedir $(NAME)

makedir:
	@mkdir -p bin

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

bin/%.o: srcs/%.c
	gcc $(FLAGS) -c $< -o $@ -Iincludes

clean:
	rm -rf bin/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
