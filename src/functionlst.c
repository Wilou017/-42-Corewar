/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:32:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/01 20:37:04 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_live(t_cwdata *data, t_process *proc)
{
	(void)data;
	proc->nb_live++;
	sleep(1);
}

void	cw_zjump(t_cwdata *data, t_process *proc)
{
	int	param;

	param = 0;
	param = (data->mem[proc->loca + 1] << 8) + data->mem[proc->loca + 2];
	ft_termcaps_savecurs();
	ft_termcaps_poscurs(50, COLONE_TEXT);
	ft_printf("proc->loca = %d -- %.2X %.2X\n", proc->loca, data->mem[proc->loca], data->mem[proc->loca + 1]);
	proc->loca = (param % IDX_MOD) % MEM_SIZE;
	proc->pc = data->mem[proc->loca];
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("proc->loca = %d -- %.2X %.2X %.2X %.2X %.2X\n", proc->loca, data->mem[proc->loca], data->mem[proc->loca + 1], data->mem[proc->loca + 2], data->mem[proc->loca + 3], data->mem[proc->loca + 4]);
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("proc->loca = %d, proc->pc = %d, proc->pc+1 = %d\n", proc->loca, proc->pc, data->mem[proc->loca + 1]);
	ft_termcaps_restorecurs();
}