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
	(void)data;
	(void)proc;
	if (func == STI)
		ft_printf("STI      !\n");
	else if (func == FORK)
	{
		ft_printf("FORK     !\n");
		cw_fork(data, proc);
	}
	else if (func == LLD)
		ft_printf("LLD      !\n");
	else if (func == LLDI)
		ft_printf("LLDI     !\n");
	else if (func == LFORK)
	{
		ft_printf("LFORK    !\n");
		cw_lfork(data, proc);
	}
	else if (func == AFF)
		ft_printf("AFF      !\n");
	else
		ft_printf("\n");
}

void		redirect_function(t_cwdata *data, t_func func, t_process *proc)
{
	ft_termcaps_rightcurs(COLONE_TEXT);
	ft_printf("%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X \n", data->mem[(proc->loca) % MEM_SIZE],
	data->mem[(proc->loca + 1) % MEM_SIZE],
	data->mem[(proc->loca + 2) % MEM_SIZE],
	data->mem[(proc->loca + 3) % MEM_SIZE],
	data->mem[(proc->loca + 4) % MEM_SIZE],
	data->mem[(proc->loca + 5) % MEM_SIZE],
	data->mem[(proc->loca + 6) % MEM_SIZE],
	data->mem[(proc->loca + 7) % MEM_SIZE],
	data->mem[(proc->loca + 8) % MEM_SIZE]);
	ft_termcaps_rightcurs(COLONE_TEXT);
	if (func == LIVE)
	{
		ft_printf("LIVE     !\n");
		cw_live(data, proc);
	}
	else if (func == LD)
	{
		ft_printf("LD       !\n");
		cw_ld(data, proc);
	}
	else if (func == ST)
	{
		ft_printf("ST       !\n");
		cw_st(data, proc);
	}
	else if (func == ADD)
	{
		ft_printf("ADD      !\n");
		cw_add(data, proc);
	}
	else if (func == SUB)
	{
		ft_printf("SUB      !\n");
		cw_sub(data, proc);
	}
	else if (func == AND)
	{
		ft_printf("AND      !\n");
		cw_and(data, proc);
	}
	else if (func == OR)
	{
		ft_printf("OR       !\n");
		cw_or(data, proc);
	}
	else if (func == XOR)
	{
		ft_printf("XOR      !\n");
		cw_xor(data, proc);
	}
	else if (func == ZJUMP)
	{
		ft_printf("ZJUMP    !\n");
		cw_zjump(data, proc);
	}
	else if (func == LDI)
		ft_printf("LDI      !\n");
	else
		redirect_function2(data, func, proc);
}
