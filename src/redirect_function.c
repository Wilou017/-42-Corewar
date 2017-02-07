/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:57:33 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/07 14:16:20 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		redirect_function2(t_cwdata *data, t_func func, t_process *proc)
{
	if (func == STI)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  sti", -proc->id_champ, proc->name);
		cw_sti(data, proc);
	}
	else if (func == FORK)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  fork", -proc->id_champ, proc->name);
		cw_fork(data, proc);
	}
	else if (func == LLD)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  lld\n", -proc->id_champ, proc->name);
		cw_lld(data, proc);
	}
	else if (func == LLDI)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  lldi\n", -proc->id_champ, proc->name);
		cw_lldi(data, proc);
	}
	else if (func == LFORK)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  lfork\n", -proc->id_champ, proc->name);
		cw_lfork(data, proc);
	}
	else if (func == AFF)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  aff\n", -proc->id_champ, proc->name);
		cw_aff(data, proc);
	}
}

void		redirect_function(t_cwdata *data, t_func func, t_process *proc)
{
	int		i;

	i = 0;
	if (data->verbose && proc->good_cicle)
	{
		ft_printf("Size -%d- (%.4p %d -> %.4p) ", proc->size, proc->loca, proc->loca, proc->loca + proc->size);
		while (i < proc->size)
		{
			ft_printf("%.2X ", data->mem[(proc->loca + i) % MEM_SIZE]);
			i++;
		}
		ft_printf("\n");
	}
	if (func == LIVE)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  live", -proc->id_champ, proc->name);
		cw_live(data, proc);
	}
	else if (func == LD)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  ld", -proc->id_champ, proc->name);
		cw_ld(data, proc);
	}
	else if (func == ST)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  st", -proc->id_champ, proc->name);
		cw_st(data, proc);
	}
	else if (func == ADD)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  add", -proc->id_champ, proc->name);
		cw_add(data, proc);
	}
	else if (func == SUB)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  sub", -proc->id_champ, proc->name);
		cw_sub(data, proc);
	}
	else if (func == AND)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  and", -proc->id_champ, proc->name);
		cw_and(data, proc);
	}
	else if (func == OR)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  or", -proc->id_champ, proc->name);
		cw_or(data, proc);
	}
	else if (func == XOR)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  xor", -proc->id_champ, proc->name);
		cw_xor(data, proc);
	}
	else if (func == ZJUMP)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  zjump", -proc->id_champ, proc->name);
		cw_zjump(data, proc);
	}
	else if (func == LDI)
	{
		if (data->verbose && proc->good_cicle)
			ft_printf("Joueur %d Process %d   |  ldi", -proc->id_champ, proc->name);
		cw_ldi(data, proc);
	}
	else
		redirect_function2(data, func, proc);
}
