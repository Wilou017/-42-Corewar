/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:15:30 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/08 18:11:25 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	cw_endloop(t_cwdata *data)
{
	t_list		*tmp;

	tmp = data->processlist;
	while (tmp)
	{
		if(data->show_vm)
			show_hide_proc(data, (t_process*)tmp->content, 0);
		cw_del_process_to_lst(data, NULL, tmp);
		tmp = tmp->next;
	}
}

static void	cw_get_winner(t_cwdata *data)
{
	t_list		*tmp;
	t_header	*champ;

	tmp = data->beginlist;
	while (tmp)
	{
		champ = ((t_header*)tmp->content);
		if (data->last_champ_live == champ->id)
		{
			ft_printf("Contestant %d, \"%s\", has won !\n", ABS(data->last_champ_live), champ->prog_name);
			break;
		}
		tmp = tmp->next;
	}
}

int	main(int argc, t_tab argv)
{
	t_cwdata	data;

	if (argc > 1)
	{
		data.v = argv;
		data.c = argc - 1;
		if (cw_init(&data))
			return (1);
		fill_map(&data);
		cw_loop(&data);
		cw_endloop(&data);
		if (data.show_vm)
			ft_termcaps_poscurs(MEM_SIZE/NB_OCT_LINE + 5, 0);
		cw_get_winner(&data);
		cw_freeall(&data);
	}
	else
		ft_printf("{lgreen}use: ./corewar [[-n number] champion1.cor] ...\
\nOptions:\n\
	[-v]              : Verbose\n\
	[-vm]             : Affichage de la loop\n\
	[-h]              : Cache les octets de -vm\n\
	[-dump nbr_cycles]: Affiche la memoire au cycle nbr_cycles\n{eoc}\n");
	return (0);
}
