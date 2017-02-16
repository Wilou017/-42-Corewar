/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:57:58 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/15 21:42:44 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	show_hide_proc(t_cwdata *data, t_process *proc, int force)
{
	int boolean;

	boolean = (force == 0) ? force : 1;
	ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3,
	(proc->loca % NB_OCT_LINE) * 3 + 3);
	ft_printf("{bg%s} ",
		(boolean) ? right_color(data, proc->id_champ) : "black");
	ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3,
		(proc->loca % NB_OCT_LINE) * 3 + 6);
	ft_printf(" {eoc}");
}

void	adv_print(t_cwdata *data, t_process saveproc)
{
	int		i;

	i = -1;
	if ((data->verbose && saveproc.good_cicle) ||
	 (data->verbose && data->lastopfail))
	{
		data->lastopfail = 0;
		ft_printf("ADV %d (%.4p -> %.4p) ", saveproc.size, saveproc.loca,
			saveproc.loca + saveproc.size);
		while (++i < saveproc.size)
			ft_printf("%.2x ", data->mem[(saveproc.loca + i) % MEM_SIZE]);
		ft_printf("\n");
	}
}

void	cw_map_init(t_cwdata *data)
{
	int		i;
	char	*start;

	i = 0;
	ft_termcaps_screenclear();
	ft_printf("{bglblack}%*s{eoc}\n", COLONE_TEXT + 51, " ");
	while (i++ <= MEM_SIZE / NB_OCT_LINE + 3)
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
	ft_termcaps_poscurs(3, COLONE_TEXT);
	printf("PRESS ENTER TO START\n");
	get_next_line(0, &start);
}

void	cw_dump_mem(t_cwdata *data)
{
	int i;
	int size;

	i = 0;
	size = (data->d) ? 64 : 32;
	while (i < MEM_SIZE)
	{
		if (i % size == 0)
			ft_printf("%#0.4x : ", i);
		ft_printf("%0.2x ", data->mem[i++]);
		if (i % size == 0)
			ft_putchar('\n');
	}
}

int		cw_get_new_loca(t_cwdata *data, int loca, int lfork)
{
	int	param;
	int	tmp_param1;
	int	tmp_param2;
	int	new_loca;

	param = 0;
	if (data->mem[(loca + 1) % MEM_SIZE] > 0x7F)
	{
		tmp_param1 = 0xFF - data->mem[(loca + 1) % MEM_SIZE];
		tmp_param2 = 0xFF - data->mem[(loca + 2) % MEM_SIZE];
		param = ((tmp_param1 << 8) + tmp_param2) + 1;
		new_loca = (lfork) ? (loca - param) : (loca - (param % IDX_MOD));
		new_loca = (new_loca < 0) ? new_loca + MEM_SIZE : new_loca;
		(data->verbose) ? ft_printf(" %d", -param) : 0;
		if (lfork && data->verbose)
			ft_printf(" (%d)\n", loca - param);
	}
	else
	{
		param = (data->mem[(loca + 1) % MEM_SIZE] << 8) +
		data->mem[(loca + 2) % MEM_SIZE];
		new_loca = (lfork) ? ((loca + param) % MEM_SIZE) :
		((loca + (param % IDX_MOD)) % MEM_SIZE);
		(data->verbose) ? ft_printf(" %d", param) : 0;
		if (lfork && data->verbose)
			ft_printf(" (%d)\n", loca + param);
	}
	return (new_loca);
}
