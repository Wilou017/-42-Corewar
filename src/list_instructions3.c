/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:32:27 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/07 04:44:14 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_live(t_cwdata *data, t_process *proc)
{
	int			num_champ;
	t_header	*champ;

	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_LIVE)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_LIVE);
	good_cicle(proc, WAIT_LIVE);
	if (proc->wait_cicle == WAIT_LIVE)
	{
		num_champ = return_num_champ(proc, data);
		proc->nb_live++;
		data->nb_live_per_cycle++;
		proc->wait_cicle = 0;
		if (data->verbose)
			ft_printf("\nUn processus dit que le joueur %d est en vie\n", ABS(num_champ));
		champ = cw_id_champ_valid(data, num_champ);
		if (champ)
		{
			data->last_champ_live = champ->id;
			champ->last_clive = data->cur_cycle;
		}
	}
	else
		proc->move = 0;
}

void	cw_fork(t_cwdata *data, t_process *proc)
{
	t_process	*new;

	proc->wait_cicle++;
	// if (data->verbose && proc->wait_cicle != WAIT_FORK)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_FORK);
	good_cicle(proc, WAIT_FORK);
	if (proc->wait_cicle >= WAIT_FORK)
	{
		new = cw_add_process_to_lst(data, proc->id_champ, proc);
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
	// if (data->verbose && proc->wait_cicle != WAIT_LFORK)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_LFORK);
	good_cicle(proc, WAIT_LFORK);
	if (proc->wait_cicle == WAIT_LFORK)
	{
		new = cw_add_process_to_lst(data, proc->id_champ, proc);
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
	// if (data->verbose && proc->wait_cicle != WAIT_ZJUMP)
	// 	ft_printf("wait_cicle %d/%d", proc->wait_cicle, WAIT_ZJUMP);
	good_cicle(proc, WAIT_ZJUMP);
	if (proc->wait_cicle == WAIT_ZJUMP)
	{
		if (proc->carry)
		{
			if(data->show_vm)
				show_hide_proc(data, proc, 0);
			proc->loca = cw_get_new_loca(data, proc->loca, 0);
			proc->pc = data->mem[proc->loca];
			proc->move = 0;
			if(data->show_vm)
				show_hide_proc(data, proc, 1);
		}
		else if (data->verbose)
			ft_printf(" FAILED\n");
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}
