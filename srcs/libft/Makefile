# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:52:01 by pantigon          #+#    #+#              #
#    Updated: 2021/03/09 14:50:43 by pantigon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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
		ft_lstclear.c

HEAD = libft.h

OBJ = $(SRCS:.c=.o)

%.o: %.c
	gcc -Wall -Werror -Wextra -I. -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
