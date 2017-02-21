/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:17:10 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/15 21:29:12 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		cw_ldinorme2(t_cwdata *data, t_process *proc, t_inst *inst,
	t_param *param)
{
	int		param2;

	param2 = bin_offset(proc, data, 2, inst);
	if (inst->param == REG_CODE)
	{
		param2 = proc->reg[param2 - 1];
		param->param2 = param2;
		inst->param = 0;
		print_verbose(data, param2, 0, *inst);
	}
	else
		param->param2 = return_size_reg(data, proc, param2, 2);
}

void		cw_ldinorme1(t_cwdata *data, t_process *proc, t_inst *inst,
		t_param *param)
{
	int		param1;

	param1 = bin_offset(proc, data, 0, inst);
	if (inst->param == REG_CODE)
	{
		param1 = proc->reg[param1 - 1];
		param->param1 = param1;
		inst->param = 0;
	}
	else if (inst->param == DIR_CODE)
		param->param1 = param1;
	else
		param->param1 = return_size_reg(data, proc, param1, 2);
	print_verbose(data, param->param1, 0, *inst);
}

void		cw_ldinorme(t_cwdata *data, t_process *proc, t_inst *inst,
		t_param *param)
{
	static int	i = 0;

	i++;
	if (i == 1)
		cw_ldinorme1(data, proc, &inst, &param);
	else if (i == 2)
		cw_ldinorme2(data, proc, &inst, &param);
	if (i == 2)
		i = 0;
}

void		cw_ldi(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param3;
	t_param param;

	init_param(&param);
	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_LDI;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | ldi", proc->name);
		cw_ldinorme(data, proc, &inst, &param);
		cw_ldinorme(data, proc, &inst, &param);
		param3 = bin_offset(proc, data, 4, &inst);
		print_verbose(data, param3, 1, inst);
		print_verbose_details_load(data, param);
		proc->reg[param3 - 1] = return_size_reg(data, proc,
		param.param1 + param.param2, 0);
	}
	else
		bad_encodage(proc);
}
