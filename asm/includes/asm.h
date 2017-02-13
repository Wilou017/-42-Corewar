/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 10:03:41 by dgalide           #+#    #+#             */
/*   Updated: 2016/09/02 13:20:32 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h" 
# include "op.h"

typedef struct			s_op_token
{
	int					index;
	int					nbr_args;
	int					opcode;
	char				**arg;
	int					size;
	int					byte_encoding;
	int					label_index;
	struct s_op_token	*next;
	struct s_op_token	*prev;
}						t_op_token;

typedef struct			s_optab_info
{
	char				*name;
	int					nbr_args;
	int					opcode;
	int					nbr_cycles;
	int					if_codage;
	int					if_carry;
	int					label_size;
	struct s_optab_info	*next;
	struct s_optab_info	*prev;
}						t_optab_info;

typedef struct			s_label
{
	char				*name;
	int					index;
	struct s_label		*next;
	struct s_label		*prev;
}						t_label;

typedef struct			s_asm_data
{
	char				**file;
	char				*name;
	char				*comment_name;
	int					prog_size;
	t_label				*label;
	t_optab_info		*info_op;
	t_op_token			*token;
	int					error;
}						t_asm_data;

int						main(int ac, char **av);
void					exit_failure(char *error, t_asm_data *asm_data);
void					check_argv(char *av, t_asm_data *asm_data);

void					data_init(t_asm_data *asm_data);
void					data_delete(t_asm_data *data);

t_optab_info			*create_op_tab(t_optab_info *data);
t_optab_info			*link_init(void *data);
void					list_add_next(t_optab_info **data, t_optab_info *link);
void					fill_live(t_optab_info *data);
void					fill_ld(t_optab_info *data);
void					fill_st(t_optab_info *data);
void					fill_add(t_optab_info *data);
void					fill_sub(t_optab_info *data);
void					fill_and(t_optab_info *data);
void					fill_or(t_optab_info *data);
void					fill_xor(t_optab_info *data);
void					fill_zjmp(t_optab_info *data);
void					fill_ldi(t_optab_info *data);
void					fill_sti(t_optab_info *data);
void					fill_fork(t_optab_info *data);
void					fill_lld(t_optab_info *data);
void					fill_lldi(t_optab_info *data);
void					fill_lfork(t_optab_info *data);
void					fill_aff(t_optab_info *data);

void					parse(t_asm_data *data, char *av);
int						read_clean(t_asm_data *asm_data, char *arg);
int						parse_label(t_asm_data *data, char *buf);
void					parse_instructions(t_asm_data *data, char *buff);
int						fill_header(t_asm_data *data, char *buffer);
int						is_comment(char *buff);
int						is_name(char *buff);

int						aff_instruction(t_asm_data *data, char **tab);
int						lfork_instruction(t_asm_data *data, char **tab);
int						lldi_instruction(t_asm_data *data, char **tab);
int						lld_instruction(t_asm_data *data, char **tab);
int						fork_instruction(t_asm_data *data, char **tab);
int						sti_instruction(t_asm_data *data, char **tab);
int						ldi_instruction(t_asm_data *data, char **tab);
int						zjmp_instruction(t_asm_data *data, char **tab);
int						xor_instruction(t_asm_data *data, char **tab);
int						or_instruction(t_asm_data *data, char **tab);
int						and_instruction(t_asm_data *data, char **tab);
int						sub_instruction(t_asm_data *data, char **tab);
int						add_instruction(t_asm_data *data, char **tab);
int						st_instruction(t_asm_data *data, char **tab);
int						ld_instruction(t_asm_data *data, char **tab);
int						live_instruction(t_asm_data *data, char **tab);

void					process_data(t_asm_data *data);
void					fill_token(t_asm_data *data, char *buff);
void					set_byte_encoding(t_asm_data *data, t_op_token *token);
int						arg_identifier(char *str);
int						find_index(t_asm_data *data);
void					set_index(t_asm_data *data, t_op_token *token,
	char *input);
void					set_size(t_asm_data *data, t_op_token *token);
void					set_label_value(t_asm_data *data);
int						search_label_size(t_asm_data *data, int opcode);

void					bytecode_generator(t_asm_data *data, char *argv);
void					write_bytecode(unsigned int value, int size_value, int fd);
void				write_bytecode1(unsigned int value, int size_value, int fd);
void					write_arg(int fd, t_op_token *tok, int i,
	t_asm_data *data);

void					tab_del(char **tab);
int						op_tabcmp(t_optab_info *op_tab, char *str);
int						tab_len(char **tab);
int						find_label(t_label *label, char *str);
int						if_dir(char *s, t_label *label, int last_arg);
int						if_ind(char *s, t_label *label, int last_arg);
int						if_reg(char *s, int last_arg);
int						dir_value(char *str);
int						ind_label(char *str, t_label *label);
void					print_tokens(t_asm_data *data);
int						is_label(char *str);
void					tab_delete(char ***tab);
void					print_tab(char **tab);
int						find_label(t_label *label, char *str);
int						ind_label(char *str, t_label *label);
int						dir_value(char *str);
int						is_label(char *str);

#endif
