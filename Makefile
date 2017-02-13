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

NAME		=	corewar

all: $(NAME)

re: fclean all

$(NAME):
	@make -C asm/
	@make -C vm/

asm:
	@make -C asm/

clean:
	@make clean -C asm/
	@make clean -C vm/

fclean:
	@make fclean -C asm/
	@make fclean -C vm/


.PHONY: re clean fclean all libft logo
