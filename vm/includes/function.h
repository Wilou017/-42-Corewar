/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:33:59 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/21 17:27:33 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

void		print_verbose(t_cwdata *data, int param, int end, t_inst inst);
void		write_map(t_cwdata *data, t_process *proc, int dest, int src);
int			cw_init(t_cwdata *data);
void		cw_lastoption(t_cwdata *data, int i);
void		cw_zjump(t_cwdata *data, t_process *proc);
void		cw_live(t_cwdata *data, t_process *proc);
void		cw_fork(t_cwdata *data, t_process *proc);
void		cw_lfork(t_cwdata *data, t_process *proc);
int			cw_get_option(t_cwdata *data, int *i);
int			cw_get_champion(t_cwdata *data, int i);
int			cw_get_new_loca(t_cwdata *data, int loca, int lfork);
t_header	*cw_add_champ_to_lst(t_cwdata *data);
t_process	*cw_add_process_to_lst(t_cwdata *data, int id, t_process *proc);
void		cw_del_process_to_lst(t_cwdata *data, t_list *prev_proc,
			t_list *del_proc);
void		cw_freeall(t_cwdata *data);
void		cw_createnode(t_header *champion, int *tab, int size);
int			cw_check_live(t_cwdata *data, t_vm_data *vm_data);
void		cw_check_cycle(t_cwdata *data, t_vm_data *vm_data);
int			cw_distrib_name(t_reedstruct *reed, t_header *champion);
int			cw_distrib_comment(t_reedstruct *reed, t_header *champion);
int			cw_distrib_program(t_reedstruct *reed, t_header *champion);
int			cw_distrib_progsize(t_reedstruct *reed);
int			cw_distrib_padding(t_reedstruct *reed, int ret);
int			cw_norme1(t_reedstruct reed, t_header *champion);
void		vm_print(t_cwdata *data, t_process *proc, int loca);
t_header	*cw_id_champ_valid(t_cwdata *data, int id);
char		*right_color(t_cwdata *data, int id_champ);
int			cw_get_valid_champ_id(t_cwdata *data);
void		adv_print(t_cwdata *data, t_process saveproc);
void		show_hide_proc(t_cwdata *data, t_process *proc, int force);
void		cw_map_init(t_cwdata *data);
void		cw_dump_mem(t_cwdata *data);
void		print_map(t_cwdata *data);
void		fill_map(t_cwdata *data);
void		cw_loop(t_cwdata *data);
void		corewar(t_cwdata *data);
int			check_param(int opcode, int param, int name);
int			size_without_encod(t_func opcode);
int			size_encod(t_func opcode);
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
void		cw_dump_mem(t_cwdata *data);
int			endof_instructions(int inst, int encod);
int			if_encodage(int opcode);
int			check_opcode(int opcode);
int			if_registre(t_cwdata *data, t_process *proc, t_inst inst);
int			check_encod(t_process *proc, t_cwdata *data);
void		redirect_function(t_cwdata *data, t_func func, t_process *proc);
void		init_param(t_param *param);
void		check_reg_carry(t_process *proc, int reg);
void		change_carry(t_process *proc);
void		good_cicle(t_process *proc);
int			return_size_reg(t_cwdata *data, t_process *proc, int adresse,
			int lldi);
int			bin_offset_neg(t_process *proc, t_cwdata *data, t_inst *inst);
int			return_num_champ(t_process *proc, t_cwdata *data);
int			bin_offset(t_process *proc, t_cwdata *data, int param,
			t_inst *inst);
int			bin_offset_norme(t_process *proc, t_cwdata *data, int param,
			t_inst *inst);
void		cw_aff(t_cwdata *data, t_process *proc);
void		cw_lldi(t_cwdata *data, t_process *proc);
void		cw_lld(t_cwdata *data, t_process *proc);
void		cw_sti(t_cwdata *data, t_process *proc);
void		cw_ldi(t_cwdata *data, t_process *proc);
void		cw_xor(t_cwdata *data, t_process *proc);
void		cw_or(t_cwdata *data, t_process *proc);
void		cw_and(t_cwdata *data, t_process *proc);
void		cw_sub(t_cwdata *data, t_process *proc);
void		cw_add(t_cwdata *data, t_process *proc);
void		cw_st(t_cwdata *data, t_process *proc);
void		cw_ld(t_cwdata *data, t_process *proc);
void		init_instruc_ind(t_process *proc, t_inst *inst);
void		init_instruc(t_process *proc, t_inst *inst);
void		bad_encodage(t_process *proc);
void		print_verbose_details(int param1, int param2, int param3,
	int newloca_verbose);
void		print_verbose_details_load(t_cwdata *data, t_param param);

#endif
