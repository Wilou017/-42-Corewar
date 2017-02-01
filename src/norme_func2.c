/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:57:58 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/01 14:20:51 by amaitre          ###   ########.fr       */
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