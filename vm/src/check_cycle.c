/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/15 19:22:56 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	cw_decrement(t_cwdata *data, t_vm_data *vm_data)
{
	data->cycle_to_die -= CYCLE_DELTA;
	if (data->verbose)
		ft_printf("Cycle to die is now %d\n", data->cycle_to_die);
	vm_data->check = 0;
	data->nb_live_per_cycle = 0;
}

int			cw_check_live(t_cwdata *data, t_vm_data *vm_data)
{
	t_list		*tmp;
	t_list		*prev_tmp;
	t_process	*proc;

	tmp = data->processlist;
	prev_tmp = NULL;
	while (tmp)
	{
		proc = (t_process*)tmp->content;
		if (proc->nb_live == 0)
		{
			cw_del_process_to_lst(data, prev_tmp, tmp);
			tmp = tmp->next;
			continue ;
		}
		proc->nb_live = 0;
		prev_tmp = tmp;
		tmp = tmp->next;
	}
	if (data->nb_live_per_cycle >= NBR_LIVE)
		cw_decrement(data, vm_data);
	return (1);
}

void		cw_check_cycle(t_cwdata *data, t_vm_data *vm_data)
{
	vm_data->check++;
	if (vm_data->check == MAX_CHECKS)
		cw_decrement(data, vm_data);
	cw_check_live(data, vm_data);
	data->nb_live_per_cycle = 0;
	vm_data->cur_cycle = 0;
}
