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
	if (proc->wait_cicle == WAIT_FORK)
	{
		new = cw_add_process_to_lst(data, proc->id_champ);
		new->loca = cw_get_new_loca(data, proc->loca);
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
	if (proc->wait_cicle == WAIT_LFORK)
	{
		new = cw_add_process_to_lst(data, proc->id_champ);
		new->loca = cw_get_new_loca(data, proc->loca);
		new->pc = data->mem[new->loca];
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}

void	cw_zjump(t_cwdata *data, t_process *proc)
{
	proc->loca = cw_get_new_loca(data, proc->loca);
	proc->pc = data->mem[proc->loca];
	proc->move = 0;
}
