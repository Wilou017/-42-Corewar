/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:57:58 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/13 16:40:50 by amaitre          ###   ########.fr       */
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

void	cw_map_init(t_cwdata *data)
{
	int i;

	i = 0;
	ft_termcaps_screenclear();
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	while (i++ <= MEM_SIZE/NB_OCT_LINE + 3)
	{
		ft_printf("{bglblack} {eoc}");
		ft_termcaps_rightcurs(NB_OCT_LINE * 3 + 3);
		ft_printf("{bglblack} {eoc}");
		ft_termcaps_rightcurs(52);
		ft_printf("{bglblack} {eoc}");
		ft_termcaps_poscurs(i, 0);
	}
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	ft_termcaps_poscurs(16, COLONE_TEXT);
	print_map(data);
}

void		cw_dump_mem(t_cwdata *data)
{
	int i;
	int size;

	i = 0;
	size = (data->d) ? 64 : 32;
	while (i < MEM_SIZE)
	{
		if (i % size == 0)
			ft_printf("%#0.4x : ", i);
		ft_printf("%0.2X ", data->mem[i++]);
		if (i % size == 0)
			ft_putchar('\n');
	}
}
