/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:49:12 by dmathe            #+#    #+#             */
/*   Updated: 2016/12/05 22:15:31 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			cw_sub(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	init_inst(&inst);
	inst.bin = ft_itoa(proc->encod, 2);
	inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
	if (!if_registre(data, proc, inst))
		return ;
	proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
	proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] - \
	proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
	change_carry(proc);
}

void			cw_add(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	if (proc->wait_cicle == WAIT_ADD + 1)
	{
		init_inst(&inst);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
		proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] + \
		proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
		change_carry(proc);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void			cw_st(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			regsrc;
	int			regdest;
	int			param;
	int			dest;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	if (proc->wait_cicle == WAIT_ST + 1)
	{
		init_inst(&inst);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		inst.size = 1;
		param = bin_offset(proc, data, 2, &inst);
		regsrc = data->mem[(proc->loca + 2) % MEM_SIZE] - 1;
		if (data->verbose)
			ft_printf("param = %d %.2X, regsrc = %d %.2X reg = %d %.2X\n", param, param, regsrc, regsrc, proc->reg[regsrc], proc->reg[regsrc]);
		if (inst.param == REG_CODE)
		{
			regdest = data->mem[(proc->loca + inst.size + 2) % MEM_SIZE] - 1;
			proc->reg[regdest] = proc->reg[regsrc];
			if (data->verbose)
				ft_printf("regdest = %d %.2X \n", regdest, regdest);
		}
		else if (inst.param == IND_CODE)
		{
			dest = (proc->loca + (param % IDX_MOD)) % MEM_SIZE;
			write_map(data, proc, dest, regsrc);
			if (data->verbose)
				ft_printf("mem[dest] = %d %.2X \n", data->mem[dest], data->mem[dest]);
		}
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void			cw_ld(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			param;
	int			reg;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	if (proc->wait_cicle == WAIT_LD + 1)
	{
		init_inst(&inst);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param = bin_offset(proc, data, 0, &inst);
		reg = data->mem[(proc->loca + inst.label_size + 2) % MEM_SIZE];
		if (data->verbose)
			ft_printf("reg = %d %.2X, param = %d \n", reg, reg, param);
		proc->reg[reg - 1] = param;
		change_carry(proc);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}
