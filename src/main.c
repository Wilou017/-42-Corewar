/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:15:30 by amaitre           #+#    #+#             */
/*   Updated: 2017/01/31 16:12:41 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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
			ft_printf("Le joueur %d (%s) a gagné !\n", ABS(data->last_champ_live), champ->prog_name);
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
		cw_get_winner(&data);
		cw_freeall(&data);
	}
	else
		ft_printf("{lgreen}use: ./corewar [-dump nbr_cycles] [[-n number] champ\
ion1.cor] ...{eoc}\n");
	return (0);
}
