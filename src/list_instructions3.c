/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:32:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/05 22:11:59 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_live(t_cwdata *data, t_process *proc)
{
	proc->wait_cicle++;
	ft_termcaps_poscurs(35, COLONE_TEXT);
	ft_printf("proc->wait_cicle %2d\n", proc->wait_cicle);
	if (proc->wait_cicle == WAIT_LIVE)
	{
		proc->nb_live++;
		data->nb_live_per_cycle++;
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void	cw_fork(t_cwdata *data, t_process *proc)
{
	t_process	*new;
	int			param;
	int			tmp_param1;
	int			tmp_param2;

	proc->wait_cicle++;
	ft_termcaps_poscurs(36, COLONE_TEXT);
	ft_printf("proc->wait_cicle %2d\n", proc->wait_cicle);
	if (proc->wait_cicle == WAIT_FORK)
	{
		new = cw_add_process_to_lst(data, proc->id_champ);
		if (data->mem[proc->loca + 1] > 0x7F)
		{
			tmp_param1 = 0xFF - data->mem[proc->loca + 1];
			tmp_param2 = 0xFF - data->mem[proc->loca + 2];
			param = ((tmp_param1 << 8) + tmp_param2) + 1;
			new->loca = proc->loca - (param % IDX_MOD);
			new->loca = (proc->loca < 0) ? proc->loca + MEM_SIZE : proc->loca;
		}
		else
		{
			param = (data->mem[proc->loca + 1] << 8) + data->mem[proc->loca + 2];
			new->loca = proc->loca + (param % IDX_MOD) % MEM_SIZE;
		}
		new->pc = data->mem[new->loca + 1];
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void	cw_zjump(t_cwdata *data, t_process *proc)
{
	int	param;
	int	tmp_param1;
	int	tmp_param2;

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
	proc->move = 0;
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("proc->loca = %d -- %.2X %.2X %.2X %.2X %.2X\n", proc->loca, data->mem[proc->loca], data->mem[proc->loca + 1], data->mem[proc->loca + 2], data->mem[proc->loca + 3], data->mem[proc->loca + 4]);
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("proc->loca = %d, proc->pc = %d, proc->pc+1 = %d\n", proc->loca, proc->pc, data->mem[proc->loca + 1]);
	ft_termcaps_restorecurs();
}