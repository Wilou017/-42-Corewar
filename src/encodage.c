/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encodage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:51 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/23 15:22:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			check_opcode(int opcode)
{
	if (opcode == 1 || opcode == 2 || opcode == 6 || \
		opcode == 7 || opcode == 8 || opcode == 13)
		return (4);
	else if (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12 || \
		opcode == 14 || opcode == 15)
		return (2);
	return (0);
}

int			if_encodage(int opcode)
{
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
		return (0);
	else
		return (1);
}

int			encod(t_header *champion, t_cwdata *data)
{
	char	*bin;
	int		size;
	int		i;
	t_process	*proc;

	proc = ((t_process *)(champion->processlist->content));
	i = 0;
	size = size_encod(proc->pc);
	bin = ft_itoa(data->mem[proc->loca + 1], 2);
	bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(bin)), bin, 3);
	while (i < size)
	{
		if (bin[i] == '0' && bin[i + 1] == '1')
		{
			if (!check_param(proc->pc, i, REG_CODE))
				return (0);
		}
		else if (bin[i] == '1' && bin[i + 1] == '0')
		{
			if (!check_param(proc->pc, i, DIR_CODE))
				return (0);
		}
		else if (bin[i] == '1' && bin[i + 1] == '1')
		{
			if (!check_param(proc->pc, i, IND_CODE))
				return (0);
		}
		i += 2;
	}
	while (size < 8)
	{
		if (bin[size] != '0')
			return (0);
		size++;
	}
	return (endof_instructions(proc->pc, data->mem[proc->loca + 1]));
}