# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2016/11/07 18:58:23 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

SRC			=	src/main.c
SRC			+=	src/init.c
SRC			+=	src/get_function.c
SRC			+=	src/lst_function.c

SRCO		=	$(SRC:.c=.o)
HEADERSLIB	=	libftprintf/includes
HEADERS		=	includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

re: fclean all

%.o: %.c $(HEADERS)/$(NAME).h
	@echo "\033[32mCorewar :\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERSLIB) -I $(HEADERS)

$(NAME): $(SRCO)
	@make -C libftprintf/
	@$(CC)  $(CFLAGS) -o $@ $^ libftprintf/libftprintf.a
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m------ OK - Corewar ------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "\033[32muse: ./$(NAME) [-dump nbr_cycles] [[-n number] champion1.cor] ... \033[0m"

libft:
	@make -C libftprintf/

clean:
	@echo "\033[32mCorewar :\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C libftprintf/
	@rm -f $(SRCO)

fclean:
	@echo "\033[32mCorewar :\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mCorewar :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C libftprintf/
	@rm -f $(NAME)

.PHONY: re clean fclean all libft
