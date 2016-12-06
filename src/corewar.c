/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:16:34 by dmathe            #+#    #+#             */
/*   Updated: 2016/12/05 21:33:34 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				not_opcode(t_process *proc, t_cwdata *data)
{
	if (proc->pc < 1 || proc->pc > 16)
	{
		proc->loca += 1;
		proc->loca %= MEM_SIZE;
		proc->pc = data->mem[proc->loca];
		return (0);
	}
	else
		return (1);
}

int				corewar_start(t_process	*proc, t_cwdata *data)
{
	int			size;
	int			ok;

	ok = 0;
	size = 0;
	if (!not_opcode(proc, data))
		return (0);

		ft_termcaps_rightcurs(COLONE_TEXT);
		ft_printf("PROS PC %.2X\n", proc->pc);
	if (if_encodage(proc->pc))
	{
		ft_termcaps_rightcurs(COLONE_TEXT);
		ft_printf("pc = %.2X, loca = %.2X\n", proc->pc, data->mem[(proc->loca + 1) % MEM_SIZE]);

		size = check_encod(proc, data, ok);
		if (!ok)
			redirect_function(data, proc->pc, proc);
		if (proc->move)
		{
			proc->loca += size;
			proc->loca %= MEM_SIZE;
			proc->pc = data->mem[proc->loca];
		}
		proc->move = 1;
		ft_termcaps_rightcurs(COLONE_TEXT);
		return (1);
	}
	else
	{
		redirect_function(data, proc->pc, proc);
		if (proc->move)
		{
			proc->loca += size_without_encod(proc->pc);
			proc->loca %= MEM_SIZE;
			proc->pc = data->mem[proc->loca];
		}
		proc->move = 1;
		ft_termcaps_rightcurs(COLONE_TEXT);
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
		if (!proc->if_live)
		{
			tmp = tmp->next;
			continue ;
		}
		ft_termcaps_poscurs(proc->loca / NB_OCT_LINE + 3, (proc->loca % NB_OCT_LINE) * 3 + 4);
		usleep(20000);
		ft_termcaps_poscurs(20 + i, COLONE_TEXT);
		ft_printf("name = %d, pc = %.2X\n", proc->id_champ, proc->pc);
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
