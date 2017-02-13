/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:16:34 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/13 20:15:53 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int			not_opcode(t_process *proc, t_cwdata *data)
{
	if (proc->pc < 1 || proc->pc > 16)
	{
		if (data->show_vm)
			show_hide_proc(data, proc, 0);
		proc->loca += 1;
		proc->loca %= MEM_SIZE;
		proc->pc = data->mem[proc->loca];
		proc->wait_cicle = 0;
		if (data->show_vm)
			show_hide_proc(data, proc, 1);
		return (0);
	}
	else
		return (1);
}

static void			corewar_start1(t_process *proc, t_cwdata *data)
{
	proc->size = check_encod(proc, data);
	redirect_function(data, proc->pc, proc);
	if (proc->move)
	{
		if (data->show_vm)
			show_hide_proc(data, proc, 0);
		proc->loca += proc->size;
		proc->loca %= MEM_SIZE;
		proc->pc = data->mem[proc->loca];
		if (data->show_vm)
			show_hide_proc(data, proc, 1);
	}
	proc->move = 1;
}

static void			corewar_start2(t_process *proc, t_cwdata *data)
{
	redirect_function(data, proc->pc, proc);
	proc->size = size_without_encod(proc->pc);
	if (proc->move)
	{
		if (data->show_vm)
			show_hide_proc(data, proc, 0);
		proc->loca += size_without_encod(proc->pc);
		proc->loca %= MEM_SIZE;
		proc->pc = data->mem[proc->loca];
		if (data->show_vm)
			show_hide_proc(data, proc, 1);
	}
	proc->move = 1;
}

static void			corewar_start(t_process *proc, t_cwdata *data)
{
	if (!not_opcode(proc, data))
		return ;
	if (if_encodage(proc->pc))
		corewar_start1(proc, data);
	else
		corewar_start2(proc, data);
	return ;
}

void				corewar(t_cwdata *data)
{
	t_list		*tmp;
	t_process	*proc;

	tmp = data->processlist;
	while (tmp)
	{
		proc = ((t_process *)(tmp->content));
		data->lastopfail = 0;
		corewar_start(proc, data);
		tmp = tmp->next;
	}
	return ;
}
