/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2017/01/31 19:00:46 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	cw_decrement(t_cwdata *data, t_vm_data *vm_data)
{
	data->cycle_to_die -= CYCLE_DELTA;
	if (data->verbose)
		ft_printf("Decrement du cycle_to_die -> %d\n", data->cycle_to_die);
	vm_data->check = 0;
	data->nb_live_per_cycle = 0;
}

static int	cw_check_live(t_cwdata *data, t_vm_data *vm_data)
{
	t_list		*tmp;
	t_list		*prev_tmp;
	t_process	*proc;

	tmp = data->processlist;
	prev_tmp = NULL;
	while (tmp)
	{
		proc = (t_process*)tmp->content;
		if (proc->if_live == 0)
		{
			if(data->show_vm)
			{
				ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 3);
				ft_printf("{bgblack} ", data->mem[proc->loca]);
				ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 6);
				ft_printf(" ", data->mem[proc->loca]);
			}
			// cw_del_process_to_lst(data, prev_tmp, tmp);
			tmp = tmp->next;
			continue ;
		}
		if (proc->nb_live == 0)
		{
			proc->if_live = 0;
			data->nb_process--;
		}
		else if (data->nb_live_per_cycle >= NBR_LIVE)
			cw_decrement(data, vm_data);

		proc->nb_live = 0;
		prev_tmp = tmp;
		tmp = tmp->next;
	}
	if (data->cycle_to_die > 0 && data->show_vm)
		ft_putendl("");
	return (1);
}

static void	cw_check_cycle(t_cwdata *data, t_vm_data *vm_data)
{
	vm_data->check++;
	if (vm_data->check == MAX_CHECKS)
		cw_decrement(data, vm_data);
	cw_check_live(data, vm_data);
	data->nb_live_per_cycle = 0;
	vm_data->cur_cycle = 0;
}


static void	cw_map_init(t_cwdata *data)
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
	ft_termcaps_poscurs(16, COLONE_TEXT);
	print_map(data);
}

static void	cw_data_print(t_cwdata *data)
{
	t_list		*tmp;
	t_header	*champ;
	int			i;

	if (data->show_vm)
	{
		ft_termcaps_poscurs(5, COLONE_TEXT);
		ft_printf("> > > NB process {green}%010d/%010d{eoc}", data->nb_process, data->nb_process_total);
		ft_termcaps_poscurs(6, COLONE_TEXT);
		ft_printf("> > > CYCLE TO DIE %010d", data->cycle_to_die);

		ft_termcaps_poscurs(8, COLONE_TEXT);
		ft_printf("------------------------", data->nb_process, data->nb_process_total);

		tmp = data->beginlist;
		i = 0;
		while (tmp)
		{
			ft_termcaps_poscurs(10 + i, COLONE_TEXT);
			champ = ((t_header*)tmp->content);

			ft_printf("{%s}%s{eoc} %s", right_color(data, champ->id), champ->prog_name, (champ->id == data->last_champ_live) ? "*" : "-");

			tmp = tmp->next;
			i += 5;
		}

		ft_termcaps_poscurs(3, COLONE_TEXT);
	}

	if (data->show_vm || data->verbose)
		ft_printf("> > > End of cycle {red}%d{eoc} < < <\n", data->cur_cycle);
}

void	cw_loop(t_cwdata *data)
{
	t_vm_data	vm_data;

	vm_data.check = 0;
	vm_data.cur_cycle = 0;
	if (data->show_vm)
		cw_map_init(data);
	init_process(data);
	while (data->nb_process > 1 && data->cycle_to_die > 0)
	{
		corewar(data);
		data->cur_cycle++;
		vm_data.cur_cycle++;
		if (vm_data.cur_cycle == data->cycle_to_die)
			cw_check_cycle(data, &vm_data);
		cw_data_print(data);
	}
	if (data->show_vm)
		ft_termcaps_poscurs(MEM_SIZE/NB_OCT_LINE + 5, 0);
}
