/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:40:38 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/19 17:58:15 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	cw_loop(t_cwdata *data)
{
	while (1)
	{
		data->cur_cycle++;
		ft_termcaps_screenclear();
		ft_printf("Cycle courant = %d\n", data->cur_cycle);
		print_map(data);
		ft_termcaps_upline(MEM_SIZE/NB_OCT_LINE + 1);
	}
}