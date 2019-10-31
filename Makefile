# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjamali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 18:57:04 by zjamali           #+#    #+#              #
#    Updated: 2019/10/31 17:20:06 by zjamali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRC=	ft_calloc.c	ft_isascii.c	ft_memccpy.c	ft_memcpy.c 	ft_strchr.c \
		ft_strlcpy.c	ft_strnstr.c	ft_toupper.c	ft_atoi.c		ft_isalnum.c \
		ft_isdigit.c	ft_memchr.c		ft_memmove.c	ft_strdup.c \
		ft_strlen.c		ft_strrchr.c	ft_bzero.c		ft_isalpha.c	ft_isprint.c \
		ft_memcmp.c		ft_memset.c		ft_strlcat.c	ft_strncmp.c	ft_tolower.c \
		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c \
		ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c \
		ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c

OBJ= $(SRC:.c=.o)

CC= gcc
INC= libft.h
CFLAGS=  -Wall -Wextra -Werror 
HDR_FLAGS= -I.

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC) -I $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -fr $(OBJ)

fclean: clean 
	rm -fr $(NAME)

re: fclean all
