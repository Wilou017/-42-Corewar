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

$(NAME):
	@make -C vm/
	@make -C asm/

asm: logo
	@make -C asm/

clean: logo
	@make clean -C asm/
	@make clean -C vm/

fclean: logo
	@make fclean -C asm/
	@make fclean -C vm/


.PHONY: re clean fclean all libft logo
