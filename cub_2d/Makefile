# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 13:15:05 by pantigon          #+#    #+#              #
#    Updated: 2021/03/21 16:35:34 by pantigon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub

FLAG = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

INCLUDE = -I./include -I./srcs/libft/ -I./srcs/gnl/ -I./srcs/mlx/

SRCS =	srcs/main.c\
		srcs/parser.c\
		./srcs/gnl/get_next_line.c

SRCS_TEST = test.c\
			srcs/main.c\
			srcs/parser.c\
			srcs/gnl/get_next_line.c

MLX = ./srcs/mlx/

LIB = ./srcs/libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

# $(OBJ): main.c
# 	gcc $(FLAG) -Imlx -c $< -o $@

$(NAME):
	@make -C $(LIB) 
	@make -C $(MLX) 
	gcc $(SRCS) $(INCLUDE) $(FRAMEWORK) -o $(NAME) $(LIB)libft.a $(MLX)libmlx.a
	./$(NAME) map/map2.cub


test: t_r
	@make -C $(LIB) 
	@make -C $(MLX) 
	gcc $(SRCS_TEST) $(INCLUDE) $(FRAMEWORK) -o test $(LIB)libft.a $(MLX)libmlx.a

t_r:
	rm -f test

clean:
	rm -f $(OBJS)
#	rm -rf $(O_DIR)
	@make -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIB) fclean
	@make clean -C $(MLX)

re: fclean all

bonus: all

.PHONY:  all clean fclean re
