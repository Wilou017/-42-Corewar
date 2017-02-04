/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:17:10 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/01 20:36:22 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		cw_sti(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;
	int		adresse;
	int		new_loca;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_STI)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_STI);
	good_cicle(proc, WAIT_STI);
	if (proc->wait_cicle == WAIT_STI)
	{
		init_inst(&inst, proc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param1 = bin_offset(proc, data, 0, &inst) - 1;
		param2 = bin_offset(proc, data, 2, &inst);
		if (inst.param == REG_CODE)
			param2 = proc->reg[param2 - 1];
		param3 = bin_offset(proc, data, 4, &inst);
		if (inst.param == REG_CODE)
			param3 = proc->reg[param3 - 1];
		adresse = param2 + param3;
		if (adresse < 0)
			new_loca = (proc->loca - (-adresse % IDX_MOD)) % MEM_SIZE;
		else
			new_loca = (proc->loca + (adresse % IDX_MOD)) % MEM_SIZE;
		new_loca = (new_loca < 0) ? new_loca + MEM_SIZE : new_loca;
		write_map(data, proc, new_loca, param1);
		proc->wait_cicle = 0;
		if (data->verbose)
		{
			ft_printf(" r%d %d %d\n", param1 + 1, param2, param3);
			ft_printf("            | -> store to %d + %d = %d (with pc and mod %d)\n", param2, param3, param2 + param3, new_loca);
		}
	}
	else
		proc->move = 0;
}

void		cw_ldi(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;
	t_param param;

	init_param(&param);
	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_LDI)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_LDI);
	good_cicle(proc, WAIT_LDI);
	if (proc->wait_cicle == WAIT_LDI)
	{
		init_inst(&inst, proc);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param1 = bin_offset(proc, data, 0, &inst);
		if (inst.param == REG_CODE)
		{
			param1 = proc->reg[param1 - 1];
			param.param1 = param1;
			inst.param = 0;
		}
		else if (inst.param == DIR_CODE)
			param.param1 = param1;
		else
			param.param1 = return_size_reg(data, proc, param1, 0);
		print_verbose(data, param.param1, 0, inst);
		param2 = bin_offset(proc, data, 2, &inst);
		if (inst.param == REG_CODE)
		{
			param2 = proc->reg[param2 - 1];
			param.param2 = param2;
			inst.param = 0;
			print_verbose(data, param2, 0, inst);
		}
		else
			param.param2 = return_size_reg(data, proc, param2, 0);
		param3 = bin_offset(proc, data, 4, &inst);
		print_verbose(data, param3, 1, inst);
		if (data->verbose)
			ft_printf("              | -> load from %d + %d = %d\n", param.param1, param.param2, param.param1 + param.param2);
		proc->reg[param3 - 1] = return_size_reg(data, proc, param.param1 + param.param2, 0);
		if (data->verbose)
			ft_printf("return_reg = %d\n", proc->reg[param3 - 1]);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void		cw_xor(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_XOR)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_XOR);
	good_cicle(proc, WAIT_XOR);
	if (proc->wait_cicle == WAIT_XOR)
	{
		init_inst(&inst, proc);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param1 = bin_offset(proc, data, 0, &inst);
		if (inst.param == REG_CODE)
			param1 = proc->reg[param1 - 1];
		inst.param = 0;
		print_verbose(data, param1, 0, inst);
		param2 = bin_offset(proc, data, 2, &inst);
		if (inst.param == REG_CODE)
			param2 = proc->reg[param2 - 1];
		inst.param = 0;
		print_verbose(data, param2, 0, inst);
		param3 = bin_offset(proc, data, 4, &inst);
		print_verbose(data, param3, 1, inst);
		proc->reg[param3 - 1] = param1 ^ param2;
		check_reg_carry(proc, proc->reg[param3 - 1]);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void		cw_or(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_OR)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_OR);
	good_cicle(proc, WAIT_OR);
	if (proc->wait_cicle == WAIT_OR)
	{
		init_inst(&inst, proc);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param1 = bin_offset(proc, data, 0, &inst);
		if (inst.param == REG_CODE)
			param1 = proc->reg[param1 - 1];
		inst.param = 0;
		print_verbose(data, param1, 0, inst);
		param2 = bin_offset(proc, data, 2, &inst);
		if (inst.param == REG_CODE)
			param2 = proc->reg[param2 - 1];
		inst.param = 0;
		print_verbose(data, param2, 0, inst);
		param3 = bin_offset(proc, data, 4, &inst);
		print_verbose(data, param3, 1, inst);
		proc->reg[param3 - 1] = param1 | param2;
		check_reg_carry(proc, proc->reg[param3 - 1]);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void		cw_and(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_AND)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_AND);
	good_cicle(proc, WAIT_AND);
	if (proc->wait_cicle == WAIT_AND)
	{
		init_inst(&inst, proc);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param1 = bin_offset(proc, data, 0, &inst);
		print_verbose(data, param1, 0, inst);
		if (inst.param == REG_CODE)
			param1 = proc->reg[param1 - 1];
		param2 = bin_offset(proc, data, 2, &inst);
		print_verbose(data, param2, 0, inst);
		if (inst.param == REG_CODE)
			param2 = proc->reg[param2 - 1];
		param3 = bin_offset(proc, data, 4, &inst);
		print_verbose(data, param1, 1, inst);
		proc->reg[param3 - 1] = param1 & param2;
		check_reg_carry(proc, proc->reg[param3 - 1]);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}
