/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:33:59 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/01 18:05:15 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
** src/init.c
*/

int			cw_init(t_cwdata *data);
void		cw_lastoption(t_cwdata *data, int i);

/*
** src/functionlst.c
*/

void		cw_zjump(t_cwdata *data, t_process *proc);
void		cw_live(t_cwdata *data, t_process *proc);

/*
** src/get_function.c
*/

int			cw_get_option(t_cwdata *data, int *i);
int			cw_get_champion(t_cwdata *data, int i);

/*
** src/lst_function.c
*/

t_header	*cw_add_champ_to_lst(t_cwdata *data);
void		cw_freeall(t_cwdata *data);
void		cw_pushback_inst(t_header *champion, t_instnode *new);
t_process	*cw_add_process_to_lst(t_cwdata *data, t_header *champ);

/*
** src/fill_instruction.c
*/

void		cw_createnode(t_header *champion, int *tab, int size);

/*
** src/distrib_function.c
*/

int			cw_distrib_name(t_reedstruct *reed, t_header *champion);
int			cw_distrib_comment(t_reedstruct *reed, t_header *champion);
int			cw_distrib_program(t_reedstruct *reed, t_header *champion);
int			cw_distrib_progsize(t_reedstruct *reed);
int			cw_distrib_padding(t_reedstruct *reed, int ret);

/*
** src/pouette.c
*/

int			cw_pouette(t_reedstruct reed, t_header *champion);

/*
** src/creat_mem.c
*/

void		print_map(t_cwdata *data);
void		fill_map(t_cwdata *data);

/*
** src/vm_loop.c
*/

void		cw_loop(t_cwdata *data);

/*
** src/corewar.c
*/

int			corewar(t_cwdata *data);
int			init_process(t_cwdata *data);

/*
** src/check_param.c
*/

int			check_param(int opcode, int param, int name);

/*
** src/opcode.c
*/

int			size_without_encod(int opcode);
int			size_encod(int opcode);
int			param_live(int param, int name);
int			param_ld(int param, int name);
int			param_st(int param, int name);
int			param_add(int param, int name);
int			param_sub(int param, int name);
int			param_and(int param, int name);
int			param_or(int param, int name);
int			param_xor(int param, int name);
int			param_zjmp(int param, int name);
int			param_ldi(int param, int name);
int			param_sti(int param, int name);
int			param_fork(int param, int name);
int			param_lld(int param, int name);
int			param_lldi(int param, int name);
int			param_lfork(int param, int name);
int			param_aff(int param, int name);

/*
** src/encodage.c
*/

int			endof_instructions(int inst, int encod);
int			if_encodage(int opcode);
int			check_opcode(int opcode);

int			check_encod(t_process *proc, t_cwdata *data, int ok);

/*
** src/redirect_function.c
*/

void		redirect_function(t_cwdata *data, t_func func, t_process *proc);

/*
**	src/offset.c
*/

int			bin_offset(t_process *proc, t_cwdata *data, char *bin, int param);

/*
**	src/list_instruction.c
*/

void			cw_ld(t_cwdata *data, t_process *proc);

#endif
