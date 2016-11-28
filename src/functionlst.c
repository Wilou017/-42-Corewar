/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:32:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/28 18:41:45 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_zjump(t_cwdata *data, t_process *proc)
{
	int	param;

	param = 0;
	param = (data->mem[proc->loca + 1] << 8) + data->mem[proc->loca + 2];
	ft_termcaps_savecurs();
	ft_termcaps_poscurs(50, COLONE_TEXT);
	ft_printf("proc->loca = %d -- %x %x = %d\n", proc->loca, data->mem[proc->loca + 1], data->mem[proc->loca + 2], param);
	proc->loca = (proc->loca + param) % IDX_MOD;
	if (proc->loca > MEM_SIZE)
		proc->loca %= MEM_SIZE;
	proc->pc = data->mem[proc->loca];
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("proc->loca = %d\n", proc->loca);
	ft_termcaps_restorecurs();
}