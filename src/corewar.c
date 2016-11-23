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
	int			size;

	proc = ((t_process *)(champion->processlist->content));
	size = 0;
	if (if_encodage(proc->pc))
	{
		ft_printf("pc = %.2X, loca = %.2X\n", proc->pc, data->mem[proc->loca + 1]);
		if ((size = encod(champion, data)))
		{
			proc->loca += size;
			proc->pc = data->mem[proc->loca];
			return(ft_printf("Encodage correct, size = %d\n", size));
		}
		else
		{
			proc->loca += 1;
			proc->pc = data->mem[proc->loca];
			return(ft_printf("Encodage incorrect, size = %d\n", size));
		}
	}
	else
	{
		proc->loca += size_without_encod(proc->pc);
		proc->pc = data->mem[proc->loca];
		return(ft_printf("Pas d'encodage\n"));
	}
	return (0);
}

int				corewar(t_cwdata *data)
{
	t_list		*tmp;
	t_list		*begin_list;
	t_header	*champion;
	t_process	*proc;

	tmp = data->beginlist;
	begin_list = tmp;
	while (tmp)
	{
		champion = (t_header *)tmp->content;
		proc = ((t_process *)(champion->processlist->content));
		if (proc->loca == MEM_SIZE)
			break;
		ft_printf("name = %s, pc = %.2X\n", champion->prog_name, proc->pc);
		corewar_start(champion, data);
		// if (tmp->next)
		 	tmp = tmp->next;
		// // else
		// // // {	
		// // // 	ft_printf("\n------------------------\n");
		// // // 	tmp = begin_list;
		// // // }
	}
	return (0);
}

int				init_process(t_cwdata *data)
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
		tmp = tmp->next;
		i++;
	}
	return (0);
}