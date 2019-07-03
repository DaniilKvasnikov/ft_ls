# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 19:01:08 by rrhaenys          #+#    #+#              #
#    Updated: 2019/02/20 17:23:15 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
COMMAND = gcc
FLAGS = #-Wall -Wextra -Werror
SRC_DIR = src/
SRC_FIL = $(shell ls src | grep -E ".+\.c")
SRCS = $(addprefix  $(SRC_DIR), $(SRC_FIL))
OBJ	= $(SRCS:.c=.o)
INCLUDE = -I libft/src -I includes
LIB = ./libft/libft.a

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	$(COMMAND) $(FLAGS) -g -o $(NAME) $(INCLUDE) $(OBJ) $(LIB)

.c.o:
	$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re