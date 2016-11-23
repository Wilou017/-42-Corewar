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

int			endof_instructions(int inst, int encod)
{
	char	*bin;
	int		size;
	int		i;

	i = 0;
	size = 0;
	bin = ft_itoa(encod, 2);
	bin = ft_strjoin(ft_chartostr('0', 8 - ft_strlen(bin)), bin, 3);
	while (i < 8)
	{
		if (bin[i] == '0' && bin[i + 1] == '1')
			size += 1;
		else if (bin[i] == '1' && bin[i + 1] == '1')
			size += 2;
		else if (bin[i] == '1' && bin[i + 1] == '0')
			size += check_opcode(inst);
		i += 2;
	}
	if (size == 0)
		return (size);
	else
		return (size + 2);
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
