/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:57:33 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/05 22:09:41 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		redirect_function2(t_cwdata *data, t_func func, t_process *proc)
{
	if (func == STI)
	{
		if (data->verbose)
			;
	}
	else if (func == FORK)
	{
		if (data->verbose)
			;
		cw_fork(data, proc);
	}
	else if (func == LLD)
	{
		if (data->verbose)
			;
	}
	else if (func == LLDI)
	{
		if (data->verbose)
			;
	}
	else if (func == LFORK)
	{
		if (data->verbose)
			;
		cw_lfork(data, proc);
	}
	else if (func == AFF)
	{
		if (data->verbose)
			;
	}
}

void		redirect_function(t_cwdata *data, t_func func, t_process *proc)
{
	// if (data->verbose)
	// 	ft_printf("%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X \n", data->mem[(proc->loca) % MEM_SIZE],
	// data->mem[(proc->loca + 1) % MEM_SIZE],
	// data->mem[(proc->loca + 2) % MEM_SIZE],
	// data->mem[(proc->loca + 3) % MEM_SIZE],
	// data->mem[(proc->loca + 4) % MEM_SIZE],
	// data->mem[(proc->loca + 5) % MEM_SIZE],
	// data->mem[(proc->loca + 6) % MEM_SIZE],
	// data->mem[(proc->loca + 7) % MEM_SIZE],
	// data->mem[(proc->loca + 8) % MEM_SIZE]);
	if (func == LIVE)
	{
		if (data->verbose)
			;
		cw_live(data, proc);
	}
	else if (func == LD)
	{
		if (data->verbose)
			;
		cw_ld(data, proc);
	}
	else if (func == ST)
	{
		if (data->verbose)
			;
		cw_st(data, proc);
	}
	else if (func == ADD)
	{
		if (data->verbose)
			;
		cw_add(data, proc);
	}
	else if (func == SUB)
	{
		if (data->verbose)
			;
		cw_sub(data, proc);
	}
	else if (func == AND)
	{
		if (data->verbose)
			;
		cw_and(data, proc);
	}
	else if (func == OR)
	{
		if (data->verbose)
			;
		cw_or(data, proc);
	}
	else if (func == XOR)
	{
		if (data->verbose)
			;
		cw_xor(data, proc);
	}
	else if (func == ZJUMP)
	{
		if (data->verbose)
			;
		cw_zjump(data, proc);
	}
	else if (func == LDI)
	{
		if (data->verbose)
			;
	}
	else
		redirect_function2(data, func, proc);
}
