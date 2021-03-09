# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 13:15:05 by pantigon          #+#    #+#              #
#    Updated: 2021/03/09 14:50:17 by pantigon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub

FLAG = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

INCLUDE = -I./include -I./srcs/libft/ -I./srcs/gnl/

SRCS =	main.c\
		parser.c\
		./srcs/gnl/get_next_line.c

SRCS_TEST = test.c ./srcs/gnl/get_next_line.c

LIB = ./srcs/libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

# $(OBJ): main.c
# 	gcc $(FLAG) -Imlx -c $< -o $@

$(NAME):
	@make -C $(LIB) 
	gcc $(SRCS) $(INCLUDE) libmlx.dylib $(FRAMEWORK) -o $(NAME) $(LIB)libft.a
	# gcc $(FLAG) -I./minilibx_mms -c main.c -o main.c
    # gcc -Lmlx -llibmlx $(FRAMEWORK) -o $(NAME)

test:
	gcc $(SRCS_TEST) $(INCLUDE) -o test ./srcs/libft/libft.a


clean:
	rm -f $(OBJS)
#	rm -rf $(O_DIR)
	@make -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIB) fclean

re: fclean all

bonus: all

.PHONY:  all clean fclean re
