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

void			cw_sub(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_SUB;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | sub", proc->name);
		proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
		proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] - \
		proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
		check_reg_carry(proc, proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1]);
		if (data->verbose)
			ft_printf(" r%d r%d r%d\n", data->mem[(proc->loca + 2) % MEM_SIZE]\
			, data->mem[(proc->loca + 3) % MEM_SIZE]\
			, data->mem[(proc->loca + 4) % MEM_SIZE]);
	}
	else
		bad_encodage(proc);
}

void			cw_add(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_ADD;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | add", proc->name);
		proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
		proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] + \
		proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
		check_reg_carry(proc, proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1]);
		if (data->verbose)
			ft_printf(" r%d r%d r%d\n", data->mem[(proc->loca + 2) % MEM_SIZE]\
			, data->mem[(proc->loca + 3) % MEM_SIZE]\
			, data->mem[(proc->loca + 4) % MEM_SIZE]);
	}
	else
		bad_encodage(proc);
}

void			cw_st(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			regsrc;
	int			regdest;
	int			dest;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_ST;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | st", proc->name);
		regsrc = bin_offset(proc, data, 0, &inst) - 1;
		bin_offset(proc, data, 2, &inst);
		if (inst.param == REG_CODE)
		{
			regdest = data->mem[(proc->loca + inst.size + 1) % MEM_SIZE];
			proc->reg[regdest - 1] = proc->reg[regsrc];
			if (data->verbose)
				ft_printf(" r%d %d\n", regsrc + 1, regdest);
		}
		else if (inst.param == IND_CODE)
		{
			if (data->verbose)
				ft_printf(" r%d", regsrc + 1);
			dest = cw_get_new_loca(data, proc->loca + 2, 0) - 2;
			if (data->verbose)
				ft_putchar('\n');
			write_map(data, proc, dest, regsrc);
		}
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
		if (!if_registre(data, proc, inst))
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
