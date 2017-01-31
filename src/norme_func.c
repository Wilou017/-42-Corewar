/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:17:46 by amaitre           #+#    #+#             */
/*   Updated: 2017/01/31 19:08:36 by amaitre          ###   ########.fr       */
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
	int loci;

	ft_printf("{l%s}{bgblack}", right_color(data, proc->id_champ));
	i = -1;
	while (++i < 4)
	{
		loci = (loca + i) % MEM_SIZE;
		ft_termcaps_poscurs(loci / NB_OCT_LINE + 3, (loci % NB_OCT_LINE) * 3 + 4);
		ft_printf("%.2X ", data->mem[loca + i]);
	}
	ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 4);
	ft_printf("{%s}", right_color(data, proc->id_champ));
	i = -1;
	while (++i < 4)
	{
		loci = (loca + i) % MEM_SIZE;
		ft_termcaps_poscurs(loci / NB_OCT_LINE + 3, (loci % NB_OCT_LINE) * 3 + 4);
		ft_printf("%.2X ", data->mem[loca + i]);
	}
	ft_putstr("\033[0m");
}

int		cw_id_champ_valid(t_cwdata *data, int id)
{
	t_list		*tmp;
	t_header	*champ;

	tmp = data->beginlist;
	while (tmp)
	{
		champ = ((t_header*)tmp->content);
		if (id == champ->id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*right_color(t_cwdata *data, int id_champ)
{
	return data->color[(ABS(id_champ) % 5)];
}