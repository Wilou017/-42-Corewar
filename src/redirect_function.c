/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:57:33 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/28 17:50:47 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		redirect_function2(t_cwdata *data, t_func func, t_process *proc)
{
	(void)data;
	(void)proc;
	if (func == STI)
		ft_printf("STI !\n");
	else if (func == FORK)
		ft_printf("FORK !\n");
	else if (func == LLD)
		ft_printf("LLD !\n");
	else if (func == LLDI)
		ft_printf("LLDI !\n");
	else if (func == LFORK)
		ft_printf("LFORK !\n");
	else if (func == AFF)
		ft_printf("AFF !\n");
	else
		ft_printf("\n");
}

void		redirect_function(t_cwdata *data, t_func func, t_process *proc)
{
	ft_termcaps_rightcurs(COLONE_TEXT);
	if (func == LIVE)
		ft_printf("LIVE !\n");
	else if (func == LD)
		ft_printf("LD !\n");
	else if (func == ST)
		ft_printf("ST !\n");
	else if (func == ADD)
		ft_printf("ADD !\n");
	else if (func == SUB)
		ft_printf("SUB !\n");
	else if (func == AND)
		ft_printf("AND !\n");
	else if (func == OR)
		ft_printf("OR !\n");
	else if (func == XOR)
		ft_printf("XOR !\n");
	else if (func == ZJUMP)
	{
		ft_printf("ZJUMP !\n");
		cw_zjump(data, proc);
	}
	else if (func == LDI)
		ft_printf("LDI !\n");
	else
		redirect_function2(data, func, proc);
}