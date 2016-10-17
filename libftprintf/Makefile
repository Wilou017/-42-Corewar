# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2016/09/19 21:52:40 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_chartostr.c \
			ft_coltostr.c \
			ft_countchar.c \
			ft_delcharinstr.c \
			ft_ftoa.c \
			ft_gather.c \
			ft_intinarray.c \
			ft_intlen.c \
			ft_intswap.c \
			ft_inttabdup.c \
			ft_inttabmax.c \
			ft_inttabjoin.c \
			ft_inttabmin.c \
			ft_inttabnew.c \
			ft_inttabsorted.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstadd_push_back.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstrev.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_min.c \
			ft_nbchar.c \
			ft_nbword.c \
			ft_nreplace.c \
			ft_nwstrtostr.c \
			ft_pf_color.c \
			ft_pf_cons_pres.c \
			ft_pf_initdata.c \
			ft_pf_initdata2.c \
			ft_pf_select.c \
			ft_pf_selector_br.c \
			ft_pf_selector_cs.c \
			ft_pf_selector_d.c \
			ft_pf_selector_e.c \
			ft_pf_selector_k.c \
			ft_pf_selector_n.c \
			ft_pf_selector_p.c \
			ft_pf_selector_t.c \
			ft_pf_selector_u.c \
			ft_pf_selector_ox.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putmessage.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putnstr.c \
			ft_putnstr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putwchar.c \
			ft_putwchar_fd.c \
			ft_pwe.c \
			ft_replace.c \
			ft_show_tab.c \
			ft_showtabint.c \
			ft_sqrt.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_strisdigit.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnrev.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtoupper.c \
			ft_strtrim.c \
			ft_tabcpy.c \
			ft_tablen.c \
			ft_tabmalloc.c \
			ft_termcaps_downline.c \
			ft_termcaps_leftcurs.c \
			ft_termcaps_lineclear.c \
			ft_termcaps_poscurs.c \
			ft_termcaps_restorecurs.c \
			ft_termcaps_rightcurs.c \
			ft_termcaps_savecurs.c \
			ft_termcaps_screenclear.c \
			ft_termcaps_upline.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wchrtostr.c \
			ft_without_space_len.c \
			ft_wstrtostr.c \
			get_next_line.c
SRCO	=	$(SRC:.c=.o)
HEADERS	=	includes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[K\033[35mPRINTF  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(CC) -g -o $@ -c $< $(CFLAGS) -I $(HEADERS)

$(NAME): $(SRCO)
	@echo "\033[K\033[35mPRINTF  :\033[0m [Compilation:\033[33m des .o\033[0m][\033[32mOK!\033[0m]"
	@echo "\033[35mPRINTF  :\033[0m [Compilation:\033[33m $(NAME)\033[0m]"
	@ar rc $@ $^
	@ranlib $@
	@echo "[\033[35m--------------------------\033[0m]"
	@echo "[\033[36m------- OK - PRINTF ------\033[0m]"
	@echo "[\033[35m--------------------------\033[0m]"

clean:
	@echo "\033[35mPRINTF  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)

fclean: clean
	@echo "\033[35mPRINTF  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@rm -f $(NAME)

.PHONY: re clean fclean all
