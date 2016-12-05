# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2016/12/05 21:30:32 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

SRC			=	src/main.c
SRC			+=	src/init.c
SRC			+=	src/corewar.c
SRC			+=	src/encodage.c
SRC			+=	src/opcode.c
SRC			+=	src/opcode2.c
SRC			+=	src/opcode3.c
SRC			+=	src/opcode4.c
SRC			+=	src/check_param_op.c
SRC			+=	src/get_function.c
SRC			+=	src/lst_function.c
SRC			+=	src/fill_instructions.c
SRC			+=	src/distrib_function.c
SRC			+=	src/pouette.c
SRC			+=	src/create_mem.c
SRC			+=	src/vm_loop.c
SRC			+=	src/redirect_function.c
SRC			+=	src/offset.c
SRC			+=	src/list_instructions.c
SRC			+=	src/list_instructions2.c
SRC			+=	src/list_instructions3.c

SRCO		=	$(SRC:.c=.o)
HEADERSLIB	=	libftprintf/includes
HEADERS		=	includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: logo $(NAME)

logo:
	@echo "\033[36m\n\
			        :::      ::::::::\n\
			       :+:      :+:    :+:\n\
			     +:+ +:+         +:+\n\
			   +#+  +:+       +#+\n\
			 +#+#+#+#+#+   +#+\n\
			      #+#    #+#\n\
			     ###   ########.fr\n\
			    			$(NAME) \033[0m"

re: logo fclean all

%.o: %.c $(HEADERS)/$(NAME).h $(HEADERS)/struct.h $(HEADERS)/function.h $(HEADERS)/define.h
	@echo "\033[32mCorewar :\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERSLIB) -I $(HEADERS)

$(NAME): $(SRCO)
	@make -C libftprintf/
	@$(CC)  $(CFLAGS) -o $@ $^ libftprintf/libftprintf.a
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m------ OK - Corewar ------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "\033[32muse: ./$(NAME) [-dump nbr_cycles] [[-n number] champion1.cor] ... \033[0m"

libft: logo
	@make -C libftprintf/

clean: logo
	@echo "\033[32mCorewar :\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C libftprintf/
	@rm -f $(SRCO)

fclean: logo
	@echo "\033[32mCorewar :\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mCorewar :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C libftprintf/
	@rm -f $(NAME)

.PHONY: re clean fclean all libft logo
