# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 09:38:47 by ybarbot           #+#    #+#              #
#    Updated: 2023/11/20 16:38:01 by ybarbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

CC = clang

SOURCES = printf_utils.c nbr_utils.c ft_printf.c ft_putlnbr_ulongbase.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean :
		rm -f $(OBJECTS)
fclean : clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re