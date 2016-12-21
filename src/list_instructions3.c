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
	good_cicle(proc, WAIT_LIVE);
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

	proc->wait_cicle++;
	good_cicle(proc, WAIT_FORK);
	if (proc->wait_cicle == WAIT_FORK)
	{
		new = cw_add_process_to_lst(data, proc->id_champ);
		new->loca = cw_get_new_loca(data, proc->loca, 0);
		new->pc = data->mem[new->loca];
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void	cw_lfork(t_cwdata *data, t_process *proc)
{
	t_process	*new;

	proc->wait_cicle++;
	good_cicle(proc, WAIT_LFORK);
	if (proc->wait_cicle == WAIT_LFORK)
	{
		new = cw_add_process_to_lst(data, proc->id_champ);
		new->loca = cw_get_new_loca(data, proc->loca, 1);
		new->pc = data->mem[new->loca];
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void	cw_zjump(t_cwdata *data, t_process *proc)
{
	proc->wait_cicle++;
	good_cicle(proc, WAIT_ZJUMP);
	if (proc->wait_cicle == WAIT_ZJUMP)
	{
		if (proc->carry)
		{
			proc->loca = cw_get_new_loca(data, proc->loca, 0);
			proc->pc = data->mem[proc->loca];
		}
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}
