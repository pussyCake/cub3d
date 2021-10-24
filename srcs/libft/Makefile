
NAME = libft.a

FLAG = -Wall -Wextra -Werror

O_DIR = obj

SRCS = ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_strlen.c\
		ft_memcmp.c\
		ft_strncmp.c\
		ft_isalpha.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strlcpy.c\
		ft_memmove.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_split.c\
		ft_itoa.c\
		ft_putlist.c\
		ft_lstnew.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstlast.c\
		ft_lstsize.c\
		ft_lstiter.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_strtok.c\
		get_next_line.c

HEAD = -I.

OBJ = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(O_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "LIBFT compiled"

$(O_DIR): 
	@mkdir -p obj

$(O_DIR)/%.o: %.c 
	@gcc $(FLAG) $(HEAD) -o $@ -c $< 

clean:
	@rm -f $(OBJ)
	@rm -rf $(O_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re