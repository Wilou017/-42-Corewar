/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:01:43 by dmathe            #+#    #+#             */
/*   Updated: 2016/12/03 16:01:46 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		bin_offset(t_process *proc, t_cwdata *data, int param, t_inst *inst)
{
	int	value;
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	if (inst->label_size == 4 && inst->bin[param] == '1' && inst->bin[param + 1] == '0')
	{
		inst->param = DIR_CODE;
		if (data->mem[(proc->loca + 2 + inst->size) % MEM_SIZE] > 0x7f)
		{
			tmp1 = 0xFF - data->mem[(proc->loca + 2 + inst->size) % MEM_SIZE];
			tmp2 = 0xFF - data->mem[(proc->loca + 3 + inst->size) % MEM_SIZE];
			tmp3 = 0xFF - data->mem[(proc->loca + 4 + inst->size) % MEM_SIZE];
			tmp4 = 0xFF - data->mem[(proc->loca + 5 + inst->size) % MEM_SIZE];
			value = ((tmp1 << 8) + tmp2);
			value = ((value << 8) + tmp3);
			value = ((value << 8) + tmp4) + 1;
			value = -value;
		}
		else
		{
			value = (data->mem[(proc->loca + 2 + inst->size) % MEM_SIZE] << 8) + data->mem[(proc->loca + 3 + inst->size) % MEM_SIZE];
			value = (value << 8) + data->mem[(proc->loca + 4 + inst->size) % MEM_SIZE];
			value = (value << 8) + data->mem[(proc->loca + 5 + inst->size) % MEM_SIZE];
		}
		inst->size += inst->label_size;
		return (value);
	}
	else if (inst->bin[param] == '0' && inst->bin[param + 1] == '1')
	{
		inst->param = REG_CODE;
		inst->size += 1;
		return (data->mem[(proc->loca + inst->size + 1) % MEM_SIZE]);
	}
	else
	{
		if (inst->bin[param] == '1' && inst->bin[param + 1] == '0')
			inst->param = DIR_CODE;
		else
			inst->param = IND_CODE;
		if (data->mem[(proc->loca + 2 + inst->size) % MEM_SIZE] > 0x7f)
		{
			tmp1 = 0xFF - data->mem[(proc->loca + 2 + inst->size) % MEM_SIZE];
			tmp2 = 0xFF - data->mem[(proc->loca + 3 + inst->size) % MEM_SIZE];
			value = ((tmp1 << 8) + tmp2) + 1;
			value = -value;
		}
		else
		value = (data->mem[(proc->loca + 2 + inst->size) % MEM_SIZE] << 8) + data->mem[(proc->loca + 3 + inst->size) % MEM_SIZE];
		inst->size += 2;
		return (value);
	}
}