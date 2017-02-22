# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2017/02/07 13:42:29 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm

SRC					=	sources/main.c
SRC					+=	sources/argv_checker.c
SRC					+=	sources/exit_failure.c
SRC					+=	sources/init_data.c
SRC					+=	sources/data_delete.c
SRC					+=	sources/op_tab.c
SRC					+=	sources/init_op.c
SRC					+=	sources/fill_op.c
SRC					+=	sources/fill_op2.c
SRC					+=	sources/fill_op3.c
SRC					+=	sources/fill_op4.c
SRC					+=	sources/parse.c
SRC					+=	sources/read_clean.c
SRC					+=	sources/parse_label.c
SRC					+=	sources/parse_instructions.c
SRC					+=	sources/fill_header.c
SRC					+=	sources/is_name.c
SRC					+=	sources/is_comment.c
SRC					+=	sources/check_args.c
SRC					+=	sources/check_args1.c
SRC					+=	sources/check_args2.c
SRC					+=	sources/check_args3.c
SRC					+=	sources/check_args4.c
SRC					+=	sources/process_data.c
SRC					+=	sources/set_byte_encoding.c
SRC					+=	sources/fill_token.c
SRC					+=	sources/set_size.c
SRC					+=	sources/set_index.c
SRC					+=	sources/set_label_value.c
SRC					+=	sources/search_label_size.c
SRC					+=	sources/bytecode_generator.c
SRC					+=	sources/write_bytecode.c
SRC					+=	sources/write_arg.c
SRC					+=	sources/utils0.c
SRC					+=	sources/utils1.c
SRC					+=	sources/if.c

SRCO				=	$(addprefix obj/,$(notdir $(SRC:.c=.o)))
HEADERSLIB	=	libft/includes
HEADERS			=	includes
CC					=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g

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

obj/%.o: sources/%.c $(HEADERS)/$(NAME).h $(HEADERS)/op.h
	@echo "\033[32mASM     :\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERSLIB) -I $(HEADERS)

$(NAME): $(SRCO)
	@make -C libft/
	@$(CC)  $(CFLAGS) -o $@ $^ libft/libft.a
	@mv $(NAME) ../
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m------   OK - ASM   ------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "\033[32muse: ./$(NAME) [champion1.s] ... \033[0m"

libft: logo
	@make -C libft/

clean: logo
	@echo "\033[32mASM     :\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C libft/
	@rm -f $(SRCO)

fclean: logo
	@echo "\033[32mASM     :\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mASM     :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C libft/
	@rm -f ../$(NAME)

.PHONY: re clean fclean all libft logo
