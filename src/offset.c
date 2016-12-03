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

int			bin_offset(t_process *proc, t_cwdata *data, char *bin, int param)
{
	int		label_size;

	label_size = check_opcode(proc->pc);
	if (label_size == 2 || (bin[param] == '1' && bin[param + 1] == '1'))
	{
		param = (data->mem[proc->loca + 2] << 8) + data->mem[proc->loca + 3];
		return (param);
	}
	else if (label_size == 4 && bin[param] == '1' && bin[param + 1] == '0')
	{
		param = (data->mem[proc->loca + 2] << 8) + data->mem[proc->loca + 3];
		param = (param << 8) + data->mem[proc->loca + 4];
		param = (param << 8) + data->mem[proc->loca + 5];
		return (param);
	}
	return (-2);
}