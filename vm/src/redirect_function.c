/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:57:33 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/13 21:00:06 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	redirect_function3(t_cwdata *data, t_func func, t_process *proc,
	t_process saveproc)
{
	if (func == LLD)
		cw_lld(data, proc);
	else if (func == LFORK)
	{
		if (data->verbose && proc->good_cicle && func >= LIVE && func <= AFF)
			ft_printf("P %4d | lfork\n", proc->name);
		cw_lfork(data, proc);
	}
	else if (func == AFF)
		cw_aff(data, proc);
	adv_print(data, saveproc);
}

static void	redirect_function2(t_cwdata *data, t_func func, t_process *proc,
	t_process saveproc)
{
	if (func == SUB)
		cw_sub(data, proc);
	else if (func == XOR)
		cw_xor(data, proc);
	else if (func == LLDI)
		cw_lldi(data, proc);
	else if (func == ZJUMP)
	{
		if (data->verbose && proc->good_cicle && func >= LIVE && func <= AFF)
			ft_printf("P %4d | zjmp", proc->name);
		cw_zjump(data, proc);
	}
	else if (func == LDI)
		cw_ldi(data, proc);
	else if (func == STI)
		cw_sti(data, proc);
	else if (func == FORK)
	{
		if (data->verbose && proc->good_cicle && func >= LIVE && func <= AFF)
			ft_printf("P %4d | fork", proc->name);
		cw_fork(data, proc);
	}
	else
		return (redirect_function3(data, func, proc, saveproc));
	adv_print(data, saveproc);
}

void		redirect_function(t_cwdata *data, t_func func, t_process *proc)
{
	t_process	saveproc;

	saveproc.size = proc->size;
	saveproc.loca = proc->loca;
	saveproc.good_cicle = proc->good_cicle;
	if (func == LIVE)
	{
		if (data->verbose && proc->good_cicle && func >= LIVE && func <= AFF)
			ft_printf("P %4d | live ", proc->name);
		cw_live(data, proc);
	}
	else if (func == LD)
		cw_ld(data, proc);
	else if (func == ST)
		cw_st(data, proc);
	else if (func == ADD)
		cw_add(data, proc);
	else if (func == AND)
		cw_and(data, proc);
	else if (func == OR)
		cw_or(data, proc);
	else
		return (redirect_function2(data, func, proc, saveproc));
	adv_print(data, saveproc);
}
