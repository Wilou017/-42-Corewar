/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/21 17:58:28 by amaitre          ###   ########.fr       */
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
	t_header	*champ;
	int			i;

	tmp = data->beginlist;
	i = 1;
	while (tmp)
	{
		champ = (t_header*)tmp->content;

		if (i != 1 && (i != 2 || vm_data->check > 2) && (i != 3 || vm_data->check > 3) && champ->nb_live == 0)
			champ->if_live = 0;
		else if (champ->nb_live == NBR_LIVE)
			cw_decrement(data, vm_data);

		ft_termcaps_poscurs(7 + (i++), COLONE_TEXT);
		ft_printf("%s -> %s", champ->prog_name, (champ->if_live) ? "VIE" : "MORT");
		tmp = tmp->next;
	}
	return (1);
}

static int	cw_champ_alive(t_cwdata *data)
{
	t_list		*tmp;
	t_header	*champ;
	int			nbr;

	tmp = data->beginlist;
	nbr = 0;
	while (tmp)
	{
		champ = (t_header*)tmp->content;
		if (champ->if_live == 1)
			nbr++;
		tmp = tmp->next;
	}
	return (nbr);
}

static void	cw_check_cycle(t_cwdata *data, t_vm_data *vm_data)
{
	cw_check_live(data, vm_data);
	vm_data->check++;
	if (vm_data->check == MAX_CHECKS)
		cw_decrement(data, vm_data);
	ft_termcaps_poscurs(5, COLONE_TEXT);
	ft_printf("cycle_to_die %d, Check %d -> Cycle %d", data->cycle_to_die, vm_data->check, data->cur_cycle);
}


static void	cw_map_init()
{
	int i;

	i = MEM_SIZE/NB_OCT_LINE + 2;
	ft_termcaps_screenclear();
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	while (i-- > 0)
		ft_printf("{bglblack}%s{eoc}%*s{bglblack}%s{eoc}%52s{bglblack}%s{eoc}\n", " ", NB_OCT_LINE * 3 + 3, " ", " ", " ", " ");
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	ft_termcaps_upline(MEM_SIZE/NB_OCT_LINE + 2);
}
void	cw_loop(t_cwdata *data)
{
	t_vm_data vm_data;

	vm_data.check = 0;
	cw_map_init();
	while (cw_champ_alive(data) > 1 && data->cycle_to_die > 0)
	{
		data->cur_cycle++;
		if (data->cur_cycle % data->cycle_to_die == 0)
			cw_check_cycle(data, &vm_data);
		ft_termcaps_poscurs(3, COLONE_TEXT);
		ft_printf("Cycle courant = %d", data->cur_cycle);
		print_map(data);
		ft_termcaps_downline(10);
		// ft_termcaps_upline(MEM_SIZE/NB_OCT_LINE + 1);
	}
}