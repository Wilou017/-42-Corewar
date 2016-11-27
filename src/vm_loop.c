/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/27 18:29:39 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	cw_decrement(t_cwdata *data, t_vm_data *vm_data)
{
	ft_termcaps_poscurs(15, COLONE_TEXT);
	ft_printf("Decrement\n");
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
		else if (data->nb_live == NBR_LIVE)
			cw_decrement(data, vm_data);

		ft_termcaps_poscurs(7 + (i++), COLONE_TEXT);
		ft_printf("%d (%d) -> %s", proc->id, proc->id_champ, (proc->if_live) ? "VIE" : "MORT");
		tmp = tmp->next;
	}
	return (1);
}

static void	cw_check_cycle(t_cwdata *data, t_vm_data *vm_data)
{
	cw_check_live(data, vm_data);
	vm_data->check++;
	if (vm_data->check == MAX_CHECKS)
		cw_decrement(data, vm_data);
	data->nb_live = 0;
	ft_termcaps_poscurs(5, COLONE_TEXT);
	ft_printf("cycle_to_die %d, Check %d -> Cycle %d", data->cycle_to_die, vm_data->check, data->cur_cycle);
	vm_data->cur_cycle = 0;
}


static void	cw_map_init()
{
	int i;

	i = MEM_SIZE/NB_OCT_LINE + 2;
	ft_termcaps_screenclear();
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	while (i-- > 0)
		ft_printf("{bglblack} {eoc}%*s{bglblack} {eoc}%52s{bglblack} {eoc}\n", NB_OCT_LINE * 3 + 3, " ", " ");
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	ft_termcaps_upline(MEM_SIZE/NB_OCT_LINE + 2);
}
void	cw_loop(t_cwdata *data)
{
	t_vm_data	vm_data;
	int i = 0;

	vm_data.check = 0;
	vm_data.cur_cycle = 0;
	cw_map_init();
	init_process(data);
	while (data->nb_process > 1 && data->cycle_to_die > 0)
	{
		if (data->cur_cycle % 5000 == 0)
		{
			ft_termcaps_poscurs(16, COLONE_TEXT);
			i++;
			ft_printf("Nombre d'affichage de la map = %d", i);
			print_map(data);
		}
		// ft_termcaps_poscurs(MEM_SIZE/NB_OCT_LINE + 7, 0);
		corewar(data);
		data->cur_cycle++;
		vm_data.cur_cycle++;
		if (vm_data.cur_cycle == data->cycle_to_die)
			cw_check_cycle(data, &vm_data);
		ft_termcaps_poscurs(3, COLONE_TEXT);
		ft_printf("Cycle courant = %d", data->cur_cycle);
		ft_termcaps_poscurs(MEM_SIZE/NB_OCT_LINE + 7, 0);
		sleep(1);
	}
}