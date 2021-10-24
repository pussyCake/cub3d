
NAME = cub3D

FLAG = -Wall -Wextra -Werror

S_DIR = srcs

O_DIR = obj

FRAMEWORK = -framework OpenGL -framework AppKit

INCLUDE = -I./include -I./srcs/libft/ -I./srcs/gnl/ -I./srcs/mlx/

SRC =	cub3D.c\
		colour.c\
		parser_file.c\
		error.c\
		free.c\
		resolution.c\
		utils.c\
		param_check.c\
		param_get.c\
		map.c\
		valid_map.c\
		param_init.c\
		param_path.c\
		hook.c\
		raycast.c\
		control.c\
		texture.c\
		pixel.c\
		save.c\
		sprite.c\
		sprite_second.c\
		gnl/get_next_line.c

SRCS = $(addprefix $(S_DIR)/,$(SRC))

OBJS = $(addprefix $(O_DIR)/,$(SRC:.c=.o))

MLX = ./srcs/mlx/

LIB = ./srcs/libft/

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB) 
	@make -C $(MLX) 
	gcc $(OBJS) $(INCLUDE) $(FRAMEWORK) -O3 -o $(NAME) $(LIB)libft.a $(MLX)libmlx.a

$(O_DIR)/%.o: $(S_DIR)/%.c
	mkdir -p obj
	mkdir -p obj/gnl
	gcc $(FLAG) $(INCLUDE) -o $@ -c $< 

clean:
	rm -f $(OBJS)
	rm -rf $(O_DIR)
	@make -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIB) fclean
	@make clean -C $(MLX)

re: fclean all

bonus: all

.PHONY:  all clean fclean re
