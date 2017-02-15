/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/15 19:26:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	init_process(t_cwdata *data)
{
	t_list		*tmp;
	t_process	*proc;
	int			i;

	i = 0;
	tmp = data->processlist;
	while (tmp)
	{
		proc = ((t_process *)(tmp->content));
		proc->loca = data->begin_champ[i];
		proc->pc = data->mem[data->begin_champ[i]];
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static void	cw_data_print_head(t_cwdata *data)
{
	ft_termcaps_poscurs(3, COLONE_TEXT);
	ft_printf("CURENT CYCLE {red}%21d{eoc}", data->cur_cycle);
	ft_termcaps_poscurs(5, COLONE_TEXT);
	ft_printf("NB PROCESS   {green}%10d/%10d{eoc}", data->nb_process,
		data->nb_process_total);
	ft_termcaps_poscurs(6, COLONE_TEXT);
	ft_printf("CYCLE TO DIE %21d", data->cycle_to_die);
	ft_termcaps_poscurs(8, COLONE_TEXT);
	ft_printf("------------------------");
}

static void	refresh_proc(t_cwdata *data)
{
	t_list		*tmp;
	t_process	*proc;

	tmp = data->processlist;
	while (data->show_vm && tmp)
	{
		proc = ((t_process *)(tmp->content));
		show_hide_proc(data, proc, 1);
		tmp = tmp->next;
	}
}

static void	cw_data_print(t_cwdata *data)
{
	t_list		*tmp;
	t_header	*champ;
	int			i;

	if (data->show_vm)
	{
		cw_data_print_head(data);
		tmp = data->beginlist;
		i = 0;
		while (tmp)
		{
			champ = ((t_header*)tmp->content);
			ft_termcaps_poscurs(10 + i, COLONE_TEXT);
			ft_printf("{%s}%s{eoc} (%d) %s", right_color(data, champ->id),
				champ->prog_name, ABS(champ->id),
				(champ->id == data->last_champ_live) ? "*" : "-");
			ft_termcaps_poscurs(12 + i, COLONE_TEXT);
			ft_printf("LAST CICLE LIVE: %d", champ->last_clive);
			tmp = tmp->next;
			i += 5;
		}
		ft_termcaps_poscurs(3, COLONE_TEXT);
	}
}

void		cw_loop(t_cwdata *data)
{
	t_vm_data	vm_data;

	vm_data.check = 0;
	vm_data.cur_cycle = 0;
	if (data->show_vm)
		cw_map_init(data);
	init_process(data);
	while (data->nb_process > 0 && data->cycle_to_die > 0)
	{
		if (vm_data.cur_cycle == data->cycle_to_die)
			cw_check_cycle(data, &vm_data);
		cw_data_print(data);
		data->cur_cycle++;
		vm_data.cur_cycle++;
		(data->verbose) ? ft_printf("It is now cycle %d\n", data->cur_cycle) : 0;
		corewar(data);
		if (data->dumpcycles > -1 && data->dumpcycles >= data->cur_cycle)
			return (cw_dump_mem(data));
		refresh_proc(data);
		if (data->slow >= 0 && data->cur_cycle >= data->slow)
			usleep(1000000);
	}
}
