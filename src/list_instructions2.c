/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:17:10 by dmathe            #+#    #+#             */
/*   Updated: 2016/12/05 13:17:11 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

// void		cw_ldi(t_cwdata *data, t_process *proc)
// {
// 	t_inst	inst;
// 	int		param1;
// 	int		param2;
// 	int		param3;

// 	if (!proc->wait_cicle)
// 		proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
// 	proc->wait_cicle++;
// 	if (proc->wait_cicle == WAIT_LDI)
// 	{
// 		init_inst(&inst);
// 		inst.label_size = check_opcode(proc->pc);
// 		inst.bin = ft_itoa(proc->encod, 2);
// 		inst.bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst.bin)), inst.bin, 3);
// 		if (!if_registre(data, proc, inst))
// 			return ;
// 		param1 = bin_offset(proc, data, 0, &inst);
// 		if (inst.param == REG_CODE)
// 			param1 = proc->reg[param1 - 1];
// 		param2 = bin_offset(proc, data, 2, &inst);
// 		if (inst.param == REG_CODE)
// 			param2 = proc->reg[param2 - 1];
// 		param3 = bin_offset(proc, data, 4, &inst);
// 		proc->reg[param3 - 1] = (param1 + param2) % INT_MAX;
// 		proc->wait_cicle = 0;
// 				sleep(5);
// 	}
// 	else
// 		proc->move = 0;
// }

void		cw_xor(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];

	init_inst(&inst);
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
	proc->reg[param3 - 1] = param1 ^ param2;
	change_carry(proc);
}

void		cw_or(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];

	init_inst(&inst);
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
	proc->reg[param3 - 1] = param1 | param2;
	change_carry(proc);
}

void		cw_and(t_cwdata *data, t_process *proc)
{
	t_inst	inst;
	int		param1;
	int		param2;
	int		param3;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];

	init_inst(&inst);
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
	proc->reg[param3 - 1] = param1 & param2;
	change_carry(proc);
}
