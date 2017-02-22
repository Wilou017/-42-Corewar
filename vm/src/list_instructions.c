/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:49:12 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/08 19:47:01 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			cw_xornorme(t_cwdata *data, t_process *proc, t_inst *inst)
{
	t_param		param;

	init_param(&param);
	param.param1 = bin_offset(proc, data, 0, inst);
	if (inst->param == REG_CODE)
		param.param1 = proc->reg[param.param1 - 1];
	inst->param = 0;
	print_verbose(data, param.param1, 0, *inst);
	param.param2 = bin_offset(proc, data, 2, inst);
	if (inst->param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	inst->param = 0;
	print_verbose(data, param.param2, 0, *inst);
	param.param3 = bin_offset(proc, data, 4, inst);
	print_verbose(data, param.param3, 1, *inst);
	proc->reg[param.param3 - 1] = param.param1 ^ param.param2;
	check_reg_carry(proc, proc->reg[param.param3 - 1]);
}

void			cw_xor(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_XOR;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | xor", proc->name);
		cw_xornorme(data, proc, &inst);
	}
	else
		bad_encodage(proc);
}

void			cw_stnorme(t_cwdata *data, t_process *proc, t_inst *inst)
{
	int			regsrc;
	int			regdest;
	int			dest;

	regsrc = bin_offset(proc, data, 0, inst) - 1;
	bin_offset(proc, data, 2, inst);
	if (inst->param == REG_CODE)
	{
		regdest = data->mem[(proc->loca + inst->size + 1) % MEM_SIZE];
		proc->reg[regdest - 1] = proc->reg[regsrc];
		if (data->verbose)
			ft_printf(" r%d %d\n", regsrc + 1, regdest);
	}
	else if (inst->param == IND_CODE)
	{
		if (data->verbose)
			ft_printf(" r%d", regsrc + 1);
		dest = cw_get_new_loca(data, proc->loca + 2, 0) - 2;
		if (data->verbose)
			ft_putchar('\n');
		write_map(data, proc, dest, regsrc);
	}
}

void			cw_st(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_ST;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | st", proc->name);
		cw_stnorme(data, proc, &inst);
	}
	else
		bad_encodage(proc);
}

void			cw_ld(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			param;
	int			reg;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle <= -1)
		proc->wait_cicle = WAIT_LD;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | ld", proc->name);
		param = bin_offset(proc, data, 0, &inst);
		reg = bin_offset(proc, data, 2, &inst);
		if (data->verbose)
			ft_printf(" %d r%d\n", param, reg);
		proc->reg[reg - 1] = param;
		check_reg_carry(proc, proc->reg[reg - 1]);
	}
	else
		bad_encodage(proc);
}
