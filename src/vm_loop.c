/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/05 21:40:00 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	cw_decrement(t_cwdata *data, t_vm_data *vm_data)
{
	if (data->verbose)
		ft_printf("Decrement du cycle_to_die\n");
	data->cycle_to_die -= CYCLE_DELTA;
	vm_data->check = 0;
}

static int	cw_check_live(t_cwdata *data, t_vm_data *vm_data)
{
	t_list		*tmp;
	t_process	*proc;
	int			i;

	tmp = data->processlist;
	i = 1;
	while (tmp)
	{
		proc = (t_process*)tmp->content;

		if (proc->nb_live == 0)
		{
			proc->if_live = 0;
			data->nb_process--;
		}
		else if (data->nb_live_per_cycle >= NBR_LIVE)
			cw_decrement(data, vm_data);
		if (data->show_vm)
		{
			ft_termcaps_poscurs(7 + (i++), COLONE_TEXT);
		}
		ft_printf("%d (%d) -> %s (live %d)\n", proc->id, proc->id_champ, (proc->if_live) ? "VIE" : "MORT", proc->nb_live);
		proc->nb_live = 0;
		tmp = tmp->next;
	}
	ft_putendl("----------------");
	return (1);
}

static void	cw_check_cycle(t_cwdata *data, t_vm_data *vm_data)
{
	cw_check_live(data, vm_data);
	vm_data->check++;
	if (vm_data->check == MAX_CHECKS)
		cw_decrement(data, vm_data);
	data->nb_live_per_cycle = 0;
	if (data->verbose)
		ft_printf("cycle_to_die %d, Check %d -> Cycle %d\n", data->cycle_to_die, vm_data->check, data->cur_cycle);
	vm_data->cur_cycle = 0;
}


static void	cw_map_init()
{
	int i;

	i = 0;
	ft_termcaps_screenclear();
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	while (i++ <= MEM_SIZE/NB_OCT_LINE + 3)
	{
		ft_printf("{bglblack} {eoc}");
		ft_termcaps_rightcurs(NB_OCT_LINE * 3 + 3);
		ft_printf("{bglblack} {eoc}");
		ft_termcaps_rightcurs(52);
		ft_printf("{bglblack} {eoc}");
		ft_termcaps_poscurs(i, 0);
	}
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
}
void	cw_loop(t_cwdata *data)
{
	t_vm_data	vm_data;
	int i = 0;

	vm_data.check = 0;
	vm_data.cur_cycle = 0;
	if (data->show_vm)
		cw_map_init();
	init_process(data);
	while (data->nb_process > 1 && data->cycle_to_die > 0)
	{
		if (data->show_vm && vm_data.cur_cycle % 50 == 0)
		{
			ft_termcaps_poscurs(16, COLONE_TEXT);
			i++;
			ft_printf("Nombre d'affichage de la map = %d", i);
			print_map(data);
		}
		corewar(data);
		data->cur_cycle++;
		vm_data.cur_cycle++;
		if (vm_data.cur_cycle == data->cycle_to_die)
			cw_check_cycle(data, &vm_data);
		if (data->show_vm)
			ft_termcaps_poscurs(3, COLONE_TEXT);
		if (data->show_vm || data->verbose)
			ft_printf("Cycle courant = %d\n", data->cur_cycle);
		// sleep(1);
	}
}
