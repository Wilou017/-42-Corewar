/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:32:27 by amaitre           #+#    #+#             */
/*   Updated: 2017/01/31 19:00:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_live(t_cwdata *data, t_process *proc)
{
	int	num_champ;

	proc->wait_cicle++;
	good_cicle(proc, WAIT_LIVE);
	if (proc->wait_cicle == WAIT_LIVE)
	{
		num_champ = return_num_champ(proc, data);
		proc->nb_live++;
		data->nb_live_per_cycle++;
		proc->wait_cicle = 0;
		if (data->verbose)
			ft_printf("Un processus dit que le joueur %d est en vie\n", num_champ);
		data->last_champ_live = (cw_id_champ_valid(data, num_champ)) ? data->last_champ_live : num_champ;
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
		new = cw_add_process_to_lst(data, proc->id_champ, proc, 1);
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
		new = cw_add_process_to_lst(data, proc->id_champ, proc, 1);
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
			if(data->show_vm)
			{
				ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 3);
				ft_printf("{bgblack} ");
				ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 6);
				ft_printf(" ");
			}
			proc->loca = cw_get_new_loca(data, proc->loca, 0);
			proc->pc = data->mem[proc->loca];
			proc->dont_move = 1;
			if(data->show_vm)
			{
				ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 3);
				ft_printf("{bg%s} ", right_color(data, proc->id_champ));
				ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 6);
				ft_printf(" {eoc}");
			}
		}
		else if (data->verbose)
			ft_printf(" FAILED\n");
		proc->wait_cicle = 0;
	}
	else
		proc->move = 0;
}
