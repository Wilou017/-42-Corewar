/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:57:58 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/08 20:34:52 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	show_hide_proc(t_cwdata *data, t_process *proc, int force)
{
	int boolean;

	boolean = (force == 0) ? force : 1;
	ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 3);
	ft_printf("{bg%s} ", (boolean) ? right_color(data, proc->id_champ) : "black");
	ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 6);
	ft_printf(" {eoc}");
}

void	adv_print(t_cwdata *data, int procsize, int procloca, int good_cicle)
{
	int		i;

	i = -1;
	if (data->verbose && good_cicle && (data->lastopfail || data->mem[procloca] != ZJUMP))
	{
		ft_printf("ADV %d (%.4p -> %.4p) ", procsize, procloca, procloca + procsize);
		while (++i < procsize)
			ft_printf("%.2x ", data->mem[(procloca + i) % MEM_SIZE]);
		ft_printf("\n");
	}
}