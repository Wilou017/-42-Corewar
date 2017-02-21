/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:33:10 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/21 19:33:18 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		bad_encodage(t_process *proc)
{
	if (proc->wait_cicle == 0 && proc->bad_encodage)
	{
		proc->wait_cicle = 0;
		proc->bad_encodage = 0;
	}
	else
		proc->move = 0;
}

void		init_instruc(t_process *proc, t_inst *inst)
{
	proc->wait_cicle = 0;
	inst->label_size = 0;
	inst->size = 0;
	inst->param = 0;
	inst->bin = ft_itoa(proc->encod, 2);
	inst->bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst->bin)),
		inst->bin, 3);
}

void		init_instruc_ind(t_process *proc, t_inst *inst)
{
	proc->wait_cicle = 0;
	inst->label_size = 0;
	inst->size = 0;
	inst->param = 0;
	inst->label_size = check_opcode(proc->pc);
	inst->bin = ft_itoa(proc->encod, 2);
	inst->bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(inst->bin)),
		inst->bin, 3);
}
