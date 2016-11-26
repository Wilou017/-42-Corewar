/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:16:34 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/26 19:42:00 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				corewar_start(t_process	*proc, t_cwdata *data)
{
	int			size;

	size = 0;
	redirect_function(data, proc->pc, proc);
	if (if_encodage(proc->pc))
	{
		ft_printf("pc = %.2X, loca = %.2X\n", proc->pc, data->mem[proc->loca + 1]);

		size = endof_instructions(proc->pc, data->mem[proc->loca + 1]);
		// if ((size = encod(proc, data)))
		// {
			proc->loca += size;
			proc->pc = data->mem[proc->loca];
			return(ft_printf("Encodage correct, size = %d\n", size));
		// }
		// else
		// {
		// 	proc->loca += 1;
		// 	proc->pc = data->mem[proc->loca];
		// 	return(ft_printf("Encodage incorrect, size = %d\n", size));
		// }
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
	t_process	*proc;

	tmp = data->processlist;
	while (tmp)
	{
		proc = ((t_process *)(tmp->content));
		if (!proc->if_live)
		{
			tmp = tmp->next;
			continue ;
		}
		ft_printf("name = %d, pc = %.2X\n", proc->id_champ, proc->pc);
		corewar_start(proc, data);
		if (proc->loca == MEM_SIZE)
			break;
		tmp = tmp->next;
	}
	ft_printf("------------------\n");
	return (0);
}

int				init_process(t_cwdata *data)
{
	t_list		*tmp;
	t_process	*proc;
	int			i;

	i = 0;
	tmp = data->processlist;
	while (tmp)
	{
		proc = ((t_process *)(tmp->content));
		proc->loca = data->begin_champ[i];
		proc->pc = data->mem[data->begin_champ[i]];
		tmp = tmp->next;
		i++;
	}
	return (0);
}