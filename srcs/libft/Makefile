# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:52:01 by pantigon          #+#    #+#              #
#    Updated: 2020/11/08 18:25:54 by pantigon         ###   ########.fr        #
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
		ft_itoa.c

SRCSB = ft_lstnew.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstlast.c\
		ft_lstsize.c\
		ft_lstiter.c\
		ft_lstdelone.c\
		ft_lstclear.c

HEAD = libft.h

OBJ = ft_memset.o\
		ft_bzero.o\
		ft_memcpy.o\
		ft_memccpy.o\
		ft_memchr.o\
		ft_strlen.o\
		ft_memcmp.o\
		ft_strncmp.o\
		ft_isalpha.o\
		ft_isalnum.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_toupper.o\
		ft_tolower.o\
		ft_strlcpy.o\
		ft_memmove.o\
		ft_strlcat.o\
		ft_strchr.o\
		ft_strrchr.o\
		ft_strnstr.o\
		ft_atoi.o\
		ft_calloc.o\
		ft_strdup.o\
		ft_substr.o\
		ft_strjoin.o\
		ft_strtrim.o\
		ft_strmapi.o\
		ft_putchar_fd.o\
		ft_putstr_fd.o\
		ft_putnbr_fd.o\
		ft_putendl_fd.o\
		ft_split.o\
		ft_itoa.o

OBJB = ft_lstnew.o\
		ft_lstadd_back.o\
		ft_lstadd_front.o\
		ft_lstlast.o\
		ft_lstsize.o\
		ft_lstiter.o\
		ft_lstdelone.o\
		ft_lstclear.o

%.o: %.c
	gcc -Wall -Werror -Wextra -I. -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(OBJB)
	ar rc $(NAME) $(OBJB)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all
