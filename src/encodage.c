/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encodage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:51 by dmathe            #+#    #+#             */
/*   Updated: 2016/12/05 20:12:49 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			if_registre(t_cwdata *data, t_process *proc, t_inst inst)
{
	int		size;
	int		i;
	int		len;

	len = size_encod(proc->pc);
	i = 0;
	size = 0;
	while (i < len)
	{
		if (inst.bin[i] == '0' && inst.bin[i + 1] == '1')
		{
			ft_termcaps_poscurs(60, COLONE_TEXT);
				ft_printf("reg = %d = %.2X\n", data->mem[proc->loca + 2 + size], data->mem[proc->loca + 2 + size]);
			if (data->mem[proc->loca + 2 + size] < 1 || data->mem[proc->loca + 2 + size] > 16)
				return (0);
			size += 1;
		}
		else if (inst.bin[i] == '1' && inst.bin[i + 1] == '1')
			size += 2;
		else if (inst.bin[i] == '1' && inst.bin[i + 1] == '0')
			size += check_opcode(proc->pc);
		i += 2;
	}
	return (1);
}

int			endof_instructions(int inst, int encod)
{
	char	*bin;
	int		size;
	int		i;
	int		len;

	i = 0;
	size = 0;
	len = size_encod(inst);
	bin = ft_itoa(encod, 2);
	bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(bin)), bin, 3);
	while (i < len)
	{
		if (bin[i] == '0' && bin[i + 1] == '1')
			size += 1;
		else if (bin[i] == '1' && bin[i + 1] == '1')
			size += 2;
		else if (bin[i] == '1' && bin[i + 1] == '0')
			size += check_opcode(inst);
		i += 2;
	}
	free(bin);
	if (size == 0)
		return (size + 1);
	else
		return (size + 2);
}

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

int			check_encod(t_process *proc, t_cwdata *data, int ok)
{
	char	*bin;
	int		size;
	int		i;

	i = 0;
	size = size_encod(proc->pc);
	bin = ft_itoa(data->mem[proc->loca + 1], 2);
	bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(bin)), bin, 3);
	while (i < size)
	{
		if (bin[i] == '0' && bin[i + 1] == '1')
		{
			if (!check_param(proc->pc, i, REG_CODE))
				ok = 1;
		}
		else if (bin[i] == '1' && bin[i + 1] == '0')
		{
			if (!check_param(proc->pc, i, DIR_CODE))
				ok = 1;
		}
		else if (bin[i] == '1' && bin[i + 1] == '1')
		{
			if (!check_param(proc->pc, i, IND_CODE))
				ok = 1;
		}
		else
			ok = 1;
		i += 2;
	}
	free(bin);
	return (endof_instructions(proc->pc, data->mem[proc->loca + 1]));
}