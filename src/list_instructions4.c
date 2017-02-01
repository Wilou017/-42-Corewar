/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:17:53 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/01 20:38:02 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		cw_aff(t_cwdata *data, t_process *proc)
{
	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	if (data->verbose && proc->wait_cicle != WAIT_AFF)
		ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_AFF);
	good_cicle(proc, WAIT_AFF);
	if (proc->wait_cicle == WAIT_AFF)
	{
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void		cw_lldi(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	if (data->verbose && proc->wait_cicle != WAIT_LLDI)
		ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_LLDI);
	good_cicle(proc, WAIT_LLDI);
	if (proc->wait_cicle == WAIT_LLDI)
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
		param2 = bin_offset(proc, data, 2, &inst);
		if (inst.param == REG_CODE)
			param2 = proc->reg[param2 - 1];
		param3 = bin_offset(proc, data, 4, &inst);
		proc->reg[param3 - 1] = return_size_reg(data, proc, param1 + param2, 1);
		check_reg_carry(proc, proc->reg[param3 - 1]);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void			cw_lld(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	int			param;
	int			reg;

	if (!proc->wait_cicle)
		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	proc->wait_cicle++;
	if (data->verbose && proc->wait_cicle != WAIT_LLD)
		ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_LLD);
	good_cicle(proc, WAIT_LLD);
	if (proc->wait_cicle == WAIT_LLD)
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
			ft_printf("reg = %d %.2X, param = %d \n", reg, reg, param);
		proc->reg[reg - 1] = param;
		check_reg_carry(proc, proc->reg[reg - 1]);
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}