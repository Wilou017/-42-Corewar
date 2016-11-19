/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:35:50 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/18 20:02:31 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			check_encodage(int opcode)
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

int			endof_instructions(int inst, int encod)
{
	char	*bin;
	int		size;
	int		i;

	i = 0;
	size = 0;
	bin = ft_itoa(encod, 2);
	bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(bin)), bin, 3);
	if (!ft_countchar(bin, '1') || !ft_countchar(bin, '0'))
	{
		size += check_encodage(inst);
		return (size - 1);
	}
	while (i < 8)
	{
		if (bin[i] == '0' && bin[i + 1] == '1')
			size += 1;
		else if (bin[i] == '1' && bin[i + 1] == '1')
			size += 2;
		else if (bin[i] == '1' && bin[i + 1] == '0')
			size += check_encodage(inst);
		i += 2;
	}
	return (size);
}

void		cw_createnode(t_header *champion, int *tab, int size)
{
	t_instnode	*new;
	int			i;
	int			j;
	int			end;

	i = 0;
	while (i < size - 1)
	{
		j = 2;
		end = 0;
		//ft_printf("tab[%d] = %.2X -> %.2b -> %d\n", i, tab[i], tab[i], tab[i]);
		new = (t_instnode*)malloc(sizeof(t_instnode));
		end = endof_instructions(tab[i], tab[i + 1]);
		new->inst = ft_inttabnew(end + 2, -1);
		new->inst[0] = tab[i];
		if (if_encodage(tab[i]))
			new->encodage = tab[i + 1];
		new->size = end + 2;
		new->inst[1] = tab[i + 1];
		i += 2;
		while (j < end + 2)
		{
			new->inst[j] = tab[i];
			i++;
			j++;
		}
		cw_pushback_inst(champion, new);
		//ft_showtabint(new->inst, end + 2, "inst_tab", 0);
	}
}
