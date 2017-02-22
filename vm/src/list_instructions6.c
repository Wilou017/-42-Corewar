/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:17:41 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/21 20:17:42 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			cw_sub(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_SUB;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		free(inst.bin);
		if (data->verbose)
			ft_printf("P %4d | sub", proc->name);
		proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
		proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] - \
		proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
		check_reg_carry(proc, proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE]
			- 1]);
		if (data->verbose)
			ft_printf(" r%d r%d r%d\n", data->mem[(proc->loca + 2) % MEM_SIZE]
			, data->mem[(proc->loca + 3) % MEM_SIZE]\
			, data->mem[(proc->loca + 4) % MEM_SIZE]);
	}
	else
		bad_encodage(proc);
}

void			cw_ornorme(t_cwdata *data, t_process *proc, t_inst *inst)
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
	free(inst->bin);
	print_verbose(data, param.param3, 1, *inst);
	proc->reg[param.param3 - 1] = param.param1 | param.param2;
	check_reg_carry(proc, proc->reg[param.param3 - 1]);
}

void			cw_or(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_OR;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | or", proc->name);
		cw_ornorme(data, proc, &inst);
	}
	else
		bad_encodage(proc);
}

void			cw_andnorme(t_cwdata *data, t_process *proc, t_inst *inst)
{
	t_param		param;

	init_param(&param);
	param.param1 = bin_offset(proc, data, 0, inst);
	print_verbose(data, param.param1, 0, *inst);
	if (inst->param == REG_CODE)
		param.param1 = proc->reg[param.param1 - 1];
	param.param2 = bin_offset(proc, data, 2, inst);
	print_verbose(data, param.param2, 0, *inst);
	if (inst->param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	param.param3 = bin_offset(proc, data, 4, inst);
	free(inst->bin);
	print_verbose(data, param.param1, 1, *inst);
	proc->reg[param.param3 - 1] = param.param1 & param.param2;
	check_reg_carry(proc, proc->reg[param.param3 - 1]);
}

void			cw_and(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_AND;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, &inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | and", proc->name);
		cw_andnorme(data, proc, &inst);
	}
	else
		bad_encodage(proc);
}
