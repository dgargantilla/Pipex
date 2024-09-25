# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 10:13:27 by dgargant          #+#    #+#              #
#    Updated: 2024/09/24 15:12:34 by dgargant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC	= gcc

HEADERS:= -I ./includes 

#CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 $(HEADERS)
CFLAGS = -Wall -Werror -Wextra -g3 $(HEADERS)
#valgrind --leak-check=full --show-leak-kinds=all
#CFLAGS = -Wall -Werror -Wextra $(HEADERS) 
#valgrind --trace-children=yes --track-fds=yes --leak-check=full
#valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all 

GPATH = libft

LIBFT_PATH = $(GPATH)/libft.a

# Colors
RED =			\033[0;31m
GREEN =			\033[0;92m
CYAN =			\033[0;96m
BLUE=			\033[0;34m
PURPLE=			\033[0;95m
YELLOW =		\033[0;93m
RESET=			\033[0m

SRCS :=	 $(addprefix sources/, \
	pipex.c	utils_path.c	utils.c)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
	make _libft $(LIBFT_PATH)
	make print_title
	@echo "$(GREEN)Creando ejecutable"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)
	@echo "Ejecutable Creado$(RESET)"


all : _libft $(NAME)

print_title:
	echo "$(PURPLE)██████╗ ██╗██████╗ ███████╗██╗  ██╗"
	echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝"
	echo "██████╔╝██║██████╔╝█████╗   ╚███╔╝ "
	echo "██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ "
	echo "██║     ██║██║     ███████╗██╔╝ ██╗"
	echo "╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝	$(RESET)"


clean :
	rm -fr $(OBJS)
	@make clean -C $(GPATH)

fclean : clean
	rm -f  $(NAME)
	@make fclean -C $(GPATH)

re : fclean all

_libft :
	@make -C $(GPATH)

.PHONY: all clean fclean re print_title
.SILENT: print_title