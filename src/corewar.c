/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:16:34 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/01 19:10:47 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				not_opcode(t_process *proc, t_cwdata *data)
{
	if (proc->pc < 1 || proc->pc > 16)
	{
		if(data->show_vm)
			show_hide_proc(data, proc, 0);
		proc->loca += 1;
		proc->loca %= MEM_SIZE;
		proc->pc = data->mem[proc->loca];
		if(data->show_vm)
			show_hide_proc(data, proc, 1);
		return (0);
	}
	else
		return (1);
}

int				corewar_start(t_process	*proc, t_cwdata *data)
{
	int			ok;

	ok = 0;
	if (!not_opcode(proc, data))
		return (0);
	if (if_encodage(proc->pc))
	{
		if (!proc->wait_cicle)
			proc->size = check_encod(proc, data, &ok);
		if (!ok)
			redirect_function(data, proc->pc, proc);
		if (proc->move)
		{
			if(data->show_vm)
				show_hide_proc(data, proc, 0);
			proc->loca += proc->size;
			proc->loca %= MEM_SIZE;
			proc->pc = data->mem[proc->loca];
			if(data->show_vm)
				show_hide_proc(data, proc, 1);
		}
		proc->move = 1;
		return (1);
	}
	else
	{
		redirect_function(data, proc->pc, proc);
		proc->size = size_without_encod(proc->pc);
		if (proc->move && !proc->dont_move)
		{
			if(data->show_vm)
				show_hide_proc(data, proc, 0);
			proc->loca += size_without_encod(proc->pc);
			proc->loca %= MEM_SIZE;
			proc->pc = data->mem[proc->loca];
			if(data->show_vm)
				show_hide_proc(data, proc, 1);
		}
		proc->dont_move = 0;
		proc->move = 1;
		return (1);
	}
	return (0);
}

int				corewar(t_cwdata *data)
{
	t_list		*tmp;
	t_process	*proc;
	int i = 0;

	tmp = data->processlist;
	while (tmp)
	{
		i+=8;
		proc = ((t_process *)(tmp->content));
		if (data->verbose)
			ft_printf("\n> Process %d | loca = %d | Octet %0.2X", proc->name, proc->loca, data->mem[proc->loca]);
		if (!proc->if_live)
		{
			tmp = tmp->next;
			continue ;
		}
		corewar_start(proc, data);
		tmp = tmp->next;
	}
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
