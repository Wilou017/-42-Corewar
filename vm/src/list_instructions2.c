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

void		cw_stinorme2(int *adresse, t_process *proc, int *new_loca,
	int *newloca_verbose)
{
	if (adresse < 0)
	{
		*new_loca = (proc->loca - (-(*adresse) % IDX_MOD)) % MEM_SIZE;
		*newloca_verbose = (proc->loca - (-(*adresse) % IDX_MOD));
	}
	else
	{
		*new_loca = (proc->loca + (*adresse % IDX_MOD)) % MEM_SIZE;
		*newloca_verbose = (proc->loca + (*adresse % IDX_MOD));
	}
	if (new_loca < 0)
		*adresse = *new_loca + MEM_SIZE;
	else
		*adresse = *new_loca;
}

int			cw_stinorme1(t_inst inst, t_process *proc, t_cwdata *data)
{
	if (!if_registre(data, proc, inst))
		return (0);
	if (data->verbose)
		ft_printf("P %4d | sti", proc->name);
	return (1);
}

int			cw_stinorme3(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	t_param param;
	int		adresse;
	int		new_loca;
	int		newloca_verbose;

	init_param(&param);
	init_instruc(proc, &inst);
	if (!cw_stinorme1(inst, proc, data))
		return (0);
	param.param1 = bin_offset(proc, data, 0, &inst) - 1;
	param.param2 = bin_offset(proc, data, 2, &inst);
	if (inst.param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	param.param3 = bin_offset(proc, data, 4, &inst);
	if (inst.param == REG_CODE)
		param.param3 = proc->reg[param.param3 - 1];
	adresse = param.param2 + param.param3;
	cw_stinorme2(&adresse, proc, &new_loca, &newloca_verbose);
	write_map(data, proc, adresse, param.param1);
	if (data->verbose)
		print_verbose_details(param.param1, param.param2, param.param3,
		newloca_verbose);
	return (1);
}

void		cw_sti(t_cwdata *data, t_process *proc)
{
	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_STI;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		if (!cw_stinorme3(data, proc))
			return ;
	}
	else
		bad_encodage(proc);
}

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

void		cw_xornorme(t_cwdata *data, t_process *proc, t_inst inst)
{
	t_param	param;

	init_param(&param);
	param.param1 = bin_offset(proc, data, 0, &inst);
	if (inst.param == REG_CODE)
		param.param1 = proc->reg[param.param1 - 1];
	inst.param = 0;
	print_verbose(data, param.param1, 0, inst);
	param.param2 = bin_offset(proc, data, 2, &inst);
	if (inst.param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	inst.param = 0;
	print_verbose(data, param.param2, 0, inst);
	param.param3 = bin_offset(proc, data, 4, &inst);
	print_verbose(data, param.param3, 1, inst);
	proc->reg[param.param3 - 1] = param.param1 ^ param.param2;
	check_reg_carry(proc, proc->reg[param.param3 - 1]);
}

void		cw_xor(t_cwdata *data, t_process *proc)
{
	t_inst	inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_XOR;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | xor", proc->name);
		cw_xornorme(data, proc, inst);
	}
	else
		bad_encodage(proc);
}

void		cw_ornorme(t_cwdata *data, t_process *proc, t_inst inst)
{
	t_param	param;

	init_param(&param);
	param.param1 = bin_offset(proc, data, 0, &inst);
	if (inst.param == REG_CODE)
		param.param1 = proc->reg[param.param1 - 1];
	inst.param = 0;
	print_verbose(data, param.param1, 0, inst);
	param.param2 = bin_offset(proc, data, 2, &inst);
	if (inst.param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	inst.param = 0;
	print_verbose(data, param.param2, 0, inst);
	param.param3 = bin_offset(proc, data, 4, &inst);
	print_verbose(data, param.param3, 1, inst);
	proc->reg[param.param3 - 1] = param.param1 | param.param2;
	check_reg_carry(proc, proc->reg[param.param3 - 1]);
}

void		cw_or(t_cwdata *data, t_process *proc)
{
	t_inst	inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_OR;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | or", proc->name);
		cw_ornorme(data, proc, inst);
	}
	else
		bad_encodage(proc);
}

void		cw_andnorme(t_cwdata *data, t_process *proc, t_inst inst)
{
	t_param	param;

	init_param(&param);
	param.param1 = bin_offset(proc, data, 0, &inst);
	print_verbose(data, param.param1, 0, inst);
	if (inst.param == REG_CODE)
		param.param1 = proc->reg[param.param1 - 1];
	param.param2 = bin_offset(proc, data, 2, &inst);
	print_verbose(data, param.param2, 0, inst);
	if (inst.param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	param.param3 = bin_offset(proc, data, 4, &inst);
	print_verbose(data, param.param1, 1, inst);
	proc->reg[param.param3 - 1] = param.param1 & param.param2;
	check_reg_carry(proc, proc->reg[param.param3 - 1]);
}

void		cw_and(t_cwdata *data, t_process *proc)
{
	t_inst	inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_AND;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc_ind(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | and", proc->name);
		cw_andnorme(data, proc, inst);
	}
	else
		bad_encodage(proc);
}
