/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:49:12 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/28 17:49:14 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			cw_ld(t_cwdata *data, t_process *proc)
{
	//static int	x = 0;
	char		*bin;
	int			param;

	//if (!x)
		proc->encod = data->mem[proc->loca + 1];
	//x++;
	// if (x == 5)
	// {
		bin = ft_itoa(proc->encod, 2);
		bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(bin)), bin, 3);
		param = bin_offset(proc, data, bin, 0);
		ft_termcaps_savecurs();
		ft_termcaps_poscurs(60, COLONE_TEXT);
		ft_printf("param = %d, mem[loca + 2] = %d, mem[loca + 3] = %d\n", param, data->mem[proc->loca + 2], data->mem[proc->loca + 3]);
		ft_termcaps_poscurs(61, COLONE_TEXT);
		ft_printf("mem[loca + 2] = %d, mem[loca + 3] = %d\n", data->mem[proc->loca + 4], data->mem[proc->loca + 5]);
		ft_termcaps_restorecurs();
		sleep(5);
	//}
}