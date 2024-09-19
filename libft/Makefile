# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 09:49:30 by dgargant          #+#    #+#              #
#    Updated: 2024/09/17 14:28:41 by dgargant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC	= gcc

CFLAGS = -Wall -Werror -Wextra $(HEADERS)

HEADERS:= -I ./includes

SRCS :=	ft_strnstr.c	ft_strdup.c	ft_split.c ft_printf.c	ft_putchar.c\
ft_puthexadecimal.c	ft_putnbr.c	ft_putpadress.c	ft_putstr.c	ft_putunbr.c\
ft_strlen.c	ft_free_array.c	ft_strjoin.c\

OBJS = $(SRCS:.c=.o)

RED =			\033[0;31m
GREEN =			\033[0;92m
CYAN =			\033[0;96m
BLUE=			\033[0;34m
PURPLE=			\033[0;95m
YELLOW =		\033[0;93m
RESET=			\033[0m

$(NAME) : $(OBJS)
	@echo "$(GREEN)Creando libft"
	ar rcs $(NAME) $(OBJS)
	@echo "Libft Creada$(RESET)"

	
all : $(NAME)

clean :
	rm -fr $(OBJS)

fclean : clean
	rm -f  $(NAME)

re : fclean all

.PHONY: bonus all clean fclean re