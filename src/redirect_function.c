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
		if (data->verbose && proc->good_cicle)
			ft_printf("sti");
		cw_sti(data, proc);
	}
	else if (func == FORK)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("fork");
		cw_fork(data, proc);
	}
	else if (func == LLD)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("lld\n");
		cw_lld(data, proc);
	}
	else if (func == LLDI)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("lldi\n");
		cw_lldi(data, proc);
	}
	else if (func == LFORK)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("lfork\n");
		cw_lfork(data, proc);
	}
	else if (func == AFF)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("aff\n");
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
	if (data->verbose && proc->good_cicle && func >= LIVE && func <= AFF)
		ft_printf("P %4d | ", proc->name);
	if (func == LIVE)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("live ");
		cw_live(data, proc);
	}
	else if (func == LD)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("ld");
		cw_ld(data, proc);
	}
	else if (func == ST)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("st");
		cw_st(data, proc);
	}
	else if (func == ADD)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("add");
		cw_add(data, proc);
	}
	else if (func == SUB)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("sub");
		cw_sub(data, proc);
	}
	else if (func == AND)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("and");
		cw_and(data, proc);
	}
	else if (func == OR)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("or");
		cw_or(data, proc);
	}
	else if (func == XOR)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("xor");
		cw_xor(data, proc);
	}
	else if (func == ZJUMP)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("zjmp");
		cw_zjump(data, proc);
	}
	else if (func == LDI)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("ldi");
		cw_ldi(data, proc);
	}
	else
		return(redirect_function2(data, func, proc));
	adv_print(data, procsize, procloca, procgood_cicle);

}
