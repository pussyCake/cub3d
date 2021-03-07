# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 13:15:05 by pantigon          #+#    #+#              #
#    Updated: 2021/03/07 15:02:44 by pantigon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub

FLAG = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

INCLUDE = ./include

SRCS = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

# $(OBJ): main.c
# 	gcc $(FLAG) -Imlx -c $< -o $@

$(NAME):
	gcc $(SRCS) -I$(INCLUDE) libmlx.dylib $(FRAMEWORK) -o win
	# gcc $(FLAG) -I./minilibx_mms -c main.c -o main.c
    # gcc -Lmlx -llibmlx $(FRAMEWORK) -o $(NAME)
