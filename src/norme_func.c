/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:17:46 by amaitre           #+#    #+#             */
/*   Updated: 2017/01/11 20:35:35 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <corewar.h>

int		cw_norme1(t_reedstruct reed, t_header *champion)
{
	champion->prog = reed.inst_tab;
	champion->prog_size = reed.inst_size;
	return (0);
}

void	vm_print(t_cwdata *data, t_process *proc, int loca)
{
	int i;

	ft_termcaps_poscurs(loca / NB_OCT_LINE + 3, (loca % NB_OCT_LINE) * 3 + 4);
	ft_printf("{%s}", data->color[ABS(proc->id_champ)]);
	i = -1;
	while (++i < 3)
		ft_printf("%.2X", data->mem[loca + i]);
	ft_putstr("{eoc}");
}