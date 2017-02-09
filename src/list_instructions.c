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

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_SUB)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_SUB);
	good_cicle(proc, WAIT_SUB);
	if (proc->wait_cicle == WAIT_SUB && !proc->bad_encodage)
	{
		init_inst(&inst, proc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
		proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] - \
		proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
		check_reg_carry(proc, proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1]);
		proc->wait_cicle = 0;
		if (data->verbose)
			ft_printf(" r%d r%d r%d\n", data->mem[(proc->loca + 2) % MEM_SIZE]\
			, data->mem[(proc->loca + 3) % MEM_SIZE]\
			, data->mem[(proc->loca + 4) % MEM_SIZE]);
	}
	else if (proc->wait_cicle == WAIT_SUB && proc->bad_encodage)
	{
		if (data->verbose)
			ft_printf(" FAIL\n");
		proc->wait_cicle = 0;
		proc->bad_encodage = 0;
	}
	else
		proc->move = 0;
}

void			cw_add(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_ADD)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_ADD);
	good_cicle(proc, WAIT_ADD);
	if (proc->wait_cicle == WAIT_ADD && !proc->bad_encodage)
	{
		init_inst(&inst, proc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
		proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] + \
		proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
		check_reg_carry(proc, proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1]);
		proc->wait_cicle = 0;
		if (data->verbose)
			ft_printf(" r%d r%d r%d\n", data->mem[(proc->loca + 2) % MEM_SIZE]\
			, data->mem[(proc->loca + 3) % MEM_SIZE]\
			, data->mem[(proc->loca + 4) % MEM_SIZE]);
	}
	else if (proc->wait_cicle == WAIT_ADD && proc->bad_encodage)
	{
		if (data->verbose)
			ft_printf(" FAIL\n");
		proc->wait_cicle = 0;
		proc->bad_encodage = 0;
	}
	else
		proc->move = 0;
}

void			cw_st(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			regsrc;
	int			regdest;
	int			dest;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_ST)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_ST);
	good_cicle(proc, WAIT_ST);
	if (proc->wait_cicle == WAIT_ST && !proc->bad_encodage)
	{
		init_inst(&inst, proc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		regsrc = bin_offset(proc, data, 0, &inst) - 1;
		bin_offset(proc, data, 2, &inst);
		if (inst.param == REG_CODE)
		{
			regdest = data->mem[(proc->loca + inst.size + 2) % MEM_SIZE] - 1;
			proc->reg[regdest] = proc->reg[regsrc];
			if (data->verbose)
				ft_printf(" r%d r%d\n", regsrc + 1, regdest);
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
		proc->wait_cicle = 0;
	}
	else if (proc->wait_cicle == WAIT_ST && proc->bad_encodage)
	{
		if (data->verbose)
			ft_printf(" FAIL\n");
		proc->wait_cicle = 0;
		proc->bad_encodage = 0;
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
	// if (data->verbose && proc->wait_cicle != WAIT_LD)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_LD);
	good_cicle(proc, WAIT_LD);
	if (proc->wait_cicle == WAIT_LD && !proc->bad_encodage)
	{
		init_inst(&inst, proc);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param = bin_offset(proc, data, 0, &inst);
		reg = bin_offset(proc, data, 2, &inst);
		if (data->verbose)
			ft_printf(" %d r%d\n", param, reg);
		proc->reg[reg - 1] = param;
		check_reg_carry(proc, proc->reg[reg - 1]);
		proc->wait_cicle = 0;
	}
	else if (proc->wait_cicle == WAIT_LD && proc->bad_encodage)
	{
		if (data->verbose)
			ft_printf(" FAIL\n");
		proc->wait_cicle = 0;
		proc->bad_encodage = 0;
	}
	else
		proc->move = 0;
}
