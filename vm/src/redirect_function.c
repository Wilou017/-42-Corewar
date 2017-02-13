/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:57:33 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/08 20:38:29 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		redirect_function2(t_cwdata *data, t_func func, t_process *proc)
{
	int		procsize;
	int		procloca;
	int		procgood_cicle;


	procsize = proc->size;
	procloca = proc->loca;
	procgood_cicle = proc->good_cicle;
	if (func == STI)
	{
		cw_sti(data, proc);
	}
	else if (func == FORK)
	{
		if (data->verbose && proc->good_cicle
			 && func >= LIVE && func <= AFF)
			ft_printf("P %4d | fork", proc->name);
		cw_fork(data, proc);
	}
	else if (func == LLD)
	{
		cw_lld(data, proc);
	}
	else if (func == LLDI)
	{
		cw_lldi(data, proc);
	}
	else if (func == LFORK)
	{
		if (data->verbose && proc->good_cicle
			 && func >= LIVE && func <= AFF)
			ft_printf("P %4d | lfork\n", proc->name);
		cw_lfork(data, proc);
	}
	else if (func == AFF)
	{
		cw_aff(data, proc);
	}
	adv_print(data, procsize, procloca, procgood_cicle);

}

void		redirect_function(t_cwdata *data, t_func func, t_process *proc)
{
	int		procsize;
	int		procloca;
	int		procgood_cicle;


	procsize = proc->size;
	procloca = proc->loca;
	procgood_cicle = proc->good_cicle;
	if (func == LIVE)
	{
		if (data->verbose && proc->good_cicle
			 && func >= LIVE && func <= AFF)
			ft_printf("P %4d | live ", proc->name);
		cw_live(data, proc);
	}
	else if (func == LD)
	{
		cw_ld(data, proc);
	}
	else if (func == ST)
	{
		cw_st(data, proc);
	}
	else if (func == ADD)
	{
		cw_add(data, proc);
	}
	else if (func == SUB)
	{
		cw_sub(data, proc);
	}
	else if (func == AND)
	{
		cw_and(data, proc);
	}
	else if (func == OR)
	{
		cw_or(data, proc);
	}
	else if (func == XOR)
	{
		cw_xor(data, proc);
	}
	else if (func == ZJUMP)
	{
		if (data->verbose && proc->good_cicle
			 && func >= LIVE && func <= AFF)
			ft_printf("P %4d | zjmp", proc->name);
		cw_zjump(data, proc);
	}
	else if (func == LDI)
	{
		cw_ldi(data, proc);
	}
	else
		return(redirect_function2(data, func, proc));
	adv_print(data, procsize, procloca, procgood_cicle);
}
