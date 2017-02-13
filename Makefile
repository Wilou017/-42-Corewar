# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2017/02/13 17:19:55 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C asmdir/
	@make -C vm/

re: fclean all

asm:
	@make -C asmdir/

clean:
	@make clean -C asmdir/
	@make clean -C vm/

fclean:
	@make fclean -C asmdir/
	@make fclean -C vm/


.PHONY: re clean fclean all libft logo
