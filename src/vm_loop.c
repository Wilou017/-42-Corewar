/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/19 19:41:35 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_check_cycle(t_cwdata *data)
{
	static int	check = 0;

	ft_termcaps_screenclear();
	check++;
	if (check == MAX_CHECKS)
	{
		ft_printf("Decrement\n");
		data->cycle_to_die -= CYCLE_DELTA;
		check = 0;
	}

	ft_printf("cycle_to_die %d, Check %d -> %d\n", data->cycle_to_die, check, data->cur_cycle);
}

void	cw_loop(t_cwdata *data)
{


	ft_termcaps_screenclear();

	while (data->cycle_to_die > 0)
	{
		data->cur_cycle++;
		if (data->cur_cycle % data->cycle_to_die == 0)
			cw_check_cycle(data);
		ft_termcaps_lineclear();
		ft_printf("Cycle courant = %d\n", data->cur_cycle);
		print_map(data);
		ft_termcaps_upline(MEM_SIZE/NB_OCT_LINE + 1);
	}
}