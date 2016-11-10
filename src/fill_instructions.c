/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:35:50 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/09 22:23:04 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			check_encodage(int opcode)
{
	if (opcode == 1 || opcode == 2 || opcode == 6 || opcode == 6 || \
		opcode == 7 || opcode == 8 || opcode == 13)
		return (4);
	else if (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12 || \
		opcode == 14 || opcode == 15)
		return (2);
	return (0);
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
	ft_printf("bin = %s\n", bin);
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

void		cw_createnode(t_header2 *champion, int *tab, int size)
{
	t_instnode	*new;
	int			i;
	int			j;
	int			end;

	j = 0;
	i = 0;
	//ft_showtabint(tab, size, "inst_tab", 0);
	while (i < size - 1)
	{
		end = 0;
		//ft_printf("\n\n\n{red}----- Boucle  %d/%d ------{eoc}\n", i, size-1);
		ft_printf("tab[%d] = %.2X -> %.2b -> %d\n", i, tab[i], tab[i], tab[i]);
		new = (t_instnode*)malloc(sizeof(t_instnode));
		new->inst = ft_inttabnew(size);
		new->inst[i] = tab[i];
		new->encodage = tab[i + 1];
		end = endof_instructions(tab[i], tab[i + 1]);
		ft_printf("size = %d\n", end);
		i += end + 2;
		cw_pushback_inst(champion, new);
	}
}