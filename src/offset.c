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

void	change_carry(t_process *proc)
{
	if (!proc->carry)
		proc->carry = 1;
	else
		proc->carry = 0;
}

int		bin_offset(t_process *proc, t_cwdata *data, int param, t_inst inst)
{
	int	value;

	if (inst.label_size == 4 && inst.bin[param] == '1' && inst.bin[param + 1] == '0')
	{
		inst.param = DIR_CODE;
		value = (data->mem[proc->loca + 2 + inst.size] << 8) + data->mem[proc->loca + 3 + inst.size];
		value = (value << 8) + data->mem[proc->loca + 4 + inst.size];
		value = (value << 8) + data->mem[proc->loca + 5 + inst.size];
		inst.size += inst.label_size;
		return (value);
	}
	else if (inst.bin[param] == '0' && inst.bin[param + 1] == '1')
	{
		inst.param = REG_CODE;
		return (data->mem[proc->loca + 2 + inst.size]);
	}
	else
	{
		if (inst.bin[param] == '1' && inst.bin[param + 1] == '0')
			inst.param = DIR_CODE;
		else
			inst.param = IND_CODE;
		value = (data->mem[proc->loca + 2 + inst.size] << 8) + data->mem[proc->loca + 3 + inst.size];
		inst.size += inst.label_size;
		return (value);
	}
}