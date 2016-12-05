/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:49:12 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/28 17:49:14 by dmathe           ###   ########.fr       */
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
	proc->reg[data->mem[proc->loca + 4] - 1] = \
	proc->reg[data->mem[proc->loca + 2] - 1] - \
	proc->reg[data->mem[proc->loca + 3] - 1];
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
	proc->reg[data->mem[proc->loca + 4] - 1] = \
	proc->reg[data->mem[proc->loca + 2] - 1] + \
	proc->reg[data->mem[proc->loca + 3] - 1];
	change_carry(proc);
}

void			cw_st(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			regsrc;
	int			regdest;
	int			param;
	int			dest;

	proc->encod = data->mem[proc->loca + 1];

	init_inst(&inst);
	inst.bin = ft_itoa(proc->encod, 2);
	inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
	if (!if_registre(data, proc, inst))
		return ;
	inst.size = 1;
	param = bin_offset(proc, data, 2, inst);
	regsrc = data->mem[proc->loca + 2] - 1;
	if (inst.param == REG_CODE)
	{
		regdest = data->mem[proc->loca + inst.size + 2] - 1;
		proc->reg[regdest] = proc->reg[regsrc];
	}
	else if (inst.param == IND_CODE)
	{
		dest = (proc->loca + (param % IDX_MOD)) % MEM_SIZE;
		data->mem[dest] = proc->reg[regsrc];
	}
	//sleep(2);
}

void			cw_ld(t_cwdata *data, t_process *proc)
{
	//static int	x = 0;
	t_inst		inst;
	int			param;
	int			reg;
	//if (!x)
		proc->encod = data->mem[proc->loca + 1];
	//x++;
	// if (x == 5)
	// {
		init_inst(&inst);
		inst.label_size = check_opcode(proc->pc);
		inst.bin = ft_itoa(proc->encod, 2);
		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
		if (!if_registre(data, proc, inst))
			return ;
		param = bin_offset(proc, data, 0, inst);
		reg = data->mem[proc->loca + inst.label_size + 2];
		proc->reg[reg - 1] = param;
		change_carry(proc);
		ft_termcaps_poscurs(55, COLONE_TEXT);
		ft_printf("param = %d, mem[loca + 2] = %.2X, mem[loca + 3] = %.2X\n", param, data->mem[proc->loca + 2], data->mem[proc->loca + 3]);
		ft_termcaps_poscurs(56, COLONE_TEXT);
		ft_printf("mem[loca + 4] = %.2X, mem[loca + 5] = %.2X\n", data->mem[proc->loca + 4], data->mem[proc->loca + 5]);
		//sleep(2);
	//}
}