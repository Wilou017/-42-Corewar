/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:32:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/05 20:08:44 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_live(t_cwdata *data, t_process *proc)
{
	(void)data;
	proc->nb_live++;
	data->nb_live_per_cycle++;
}

void	cw_zjump(t_cwdata *data, t_process *proc)
{
	int	param;
	int tmp_param1;
	int tmp_param2;

	param = 0;
	ft_termcaps_savecurs();
	ft_termcaps_poscurs(50, COLONE_TEXT);
	ft_printf("proc->loca = %d -- %.2X %.2X\n", proc->loca, data->mem[proc->loca], data->mem[proc->loca + 1]);
	param = (data->mem[proc->loca + 1] << 8) + data->mem[proc->loca + 2];
	if (data->mem[proc->loca + 1] > 0x7F)
	{
		tmp_param1 = 0xFF - data->mem[proc->loca + 1];
		tmp_param2 = 0xFF - data->mem[proc->loca + 2];
		param = ((tmp_param1 << 8) + tmp_param2) + 1;
		proc->loca = proc->loca - (param % IDX_MOD);
		proc->loca = (proc->loca < 0) ? proc->loca + MEM_SIZE : proc->loca;
	}
	else
	{
		param = (data->mem[proc->loca + 1] << 8) + data->mem[proc->loca + 2];
		proc->loca = proc->loca + (param % IDX_MOD) % MEM_SIZE;
	}
	proc->pc = data->mem[proc->loca];
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("proc->loca = %d -- %.2X %.2X %.2X %.2X %.2X\n", proc->loca, data->mem[proc->loca], data->mem[proc->loca + 1], data->mem[proc->loca + 2], data->mem[proc->loca + 3], data->mem[proc->loca + 4]);
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("proc->loca = %d, proc->pc = %d, proc->pc+1 = %d\n", proc->loca, proc->pc, data->mem[proc->loca + 1]);
	ft_termcaps_restorecurs();
}