NAME = asm
LIB = libft/libft.a 

SRC = 	sources/main.c 												\
		sources/argv_checker.c 										\
		sources/exit_failure.c 										\
																	\
		sources/data/init_data.c									\
		sources/data/data_delete.c 									\
																	\
		sources/optab_info/op_tab.c									\
		sources/optab_info/init_op.c								\
		sources/optab_info/fill_op.c								\
		sources/optab_info/fill_op2.c								\
		sources/optab_info/fill_op3.c								\
		sources/optab_info/fill_op4.c								\
																	\
		sources/parse/parse.c 										\
		sources/parse/read_clean.c 									\
		sources/parse/parse_label.c 								\
		sources/parse/parse_instructions.c 							\
		sources/parse/fill_header.c									\
		sources/parse/is_name.c 									\
		sources/parse/is_comment.c 									\
		sources/parse/check_instructions/check_args.c 				\
		sources/parse/check_instructions/check_args1.c 				\
		sources/parse/check_instructions/check_args2.c 				\
		sources/parse/check_instructions/check_args3.c 				\
		sources/parse/check_instructions/check_args4.c 				\
																	\
		sources/process_data/process_data.c 						\
		sources/process_data/set_byte_encoding.c 					\
		sources/process_data/fill_token.c 							\
		sources/process_data/set_size.c 							\
		sources/process_data/set_index.c 							\
		sources/process_data/set_label_value.c 						\
		sources/process_data/search_label_size.c 					\
																	\
		sources/bytecode_generator/bytecode_generator.c 			\
		sources/bytecode_generator/write_bytecode.c 				\
		sources/bytecode_generator/write_arg.c 						\
																	\
		sources/utils/utils0.c 										\
		sources/utils/utils1.c 										\
		sources/utils/if.c 											\

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	-@make -C libft
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Compiling ASM ...$(CE)";
	@gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

%.o: %.c
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
	@gcc $(FLAG) -c $< -o $@

clean:
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Cleaning Library ...$(CE)\033[1A";
	-@make clean -C libft
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Cleaning ASM objects$(CE)\033[1A";
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)FCleaning Library ...$(CE)\033[1A";
	@echo "\033[K$(CY)[ASM] :$(CE) $(CG)Cleaning ASM ...$(CE)\033[1A";
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re
