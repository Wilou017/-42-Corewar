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

	init_inst(&inst);
	inst.bin = ft_itoa(proc->encod, 2);
	inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
	if (!if_registre(data, proc, inst))
		return ;
	proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
	proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] + \
	proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
	change_carry(proc);
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
	if (proc->wait_cicle == WAIT_ST)
	{
		init_inst(&inst);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		inst.size = 1;
		param = bin_offset(proc, data, 2, inst);
		regsrc = data->mem[(proc->loca + 2) % MEM_SIZE] - 1;
		if (inst.param == REG_CODE)
		{
			regdest = data->mem[(proc->loca + inst.size + 2) % MEM_SIZE] - 1;
			proc->reg[regdest] = proc->reg[regsrc];
		}
		else if (inst.param == IND_CODE)
		{
			dest = (proc->loca + (param % IDX_MOD)) % MEM_SIZE;
			data->mem[dest] = proc->reg[regsrc];
		}
		proc->wait_cicle = 0;
			//sleep(2);
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
	if (proc->wait_cicle == WAIT_LD)
	{
		init_inst(&inst);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param = bin_offset(proc, data, 0, inst);
		reg = data->mem[(proc->loca + inst.label_size + 2) % MEM_SIZE];
		proc->reg[reg - 1] = param;
		change_carry(proc);
		ft_termcaps_poscurs(55, COLONE_TEXT);
		ft_printf("param = %d, %.2X %.2X %.2X %.2X \n", param, data->mem[(proc->loca + 2) % MEM_SIZE],
		data->mem[(proc->loca + 3) % MEM_SIZE],
		data->mem[(proc->loca + 4) % MEM_SIZE],
		data->mem[(proc->loca + 5) % MEM_SIZE]);
		proc->wait_cicle = 0;
		// sleep(2);
	}
	else
		proc->move = 0;
}
