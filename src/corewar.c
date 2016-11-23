/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:16:34 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/23 15:22:26 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				corewar_start(t_header *champion, t_cwdata *data)
{
	t_process	*proc;

	proc = ((t_process *)(champion->processlist->content));
	if (if_encodage(proc->pc))
	{
		ft_printf("pc = %.2X, loca = %.2X\n", proc->pc, data->mem[proc->loca + 1]);
		if (encod(champion, data) > 0)
			return(ft_printf("Encodage correct\n"));
		else
			return(ft_printf("Encodage incorrect\n"));
	}
	else
		return(ft_printf("Pas d'encodage\n"));
	return (0);
}

int				corewar(t_cwdata *data)
{
	t_list		*tmp;
	t_header	*champion;
	t_process	*proc;
	int			i;

	i = 0;
	tmp = data->beginlist;
	while (tmp)
	{
		champion = (t_header *)tmp->content;
		proc = ((t_process *)(champion->processlist->content));
		proc->reg[0] = champion->id;
		proc->loca = data->begin_champ[i];
		proc->pc = data->mem[data->begin_champ[i]];
		ft_printf("name = %s, pc = %.2X\n", champion->prog_name, proc->pc);
		corewar_start(champion, data);
		tmp = tmp->next;
		i++;
	}
	return (0);
}