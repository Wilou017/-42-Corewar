/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:16:34 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/19 18:16:35 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				corewar_start(t_header *champion, t_cwdata *data)
{
	t_process	*proc;

	proc = &champion->process;
	if (if_encodage(champion->process.pc))
	{
		ft_printf("pc = %.2X, loca = %.2X\n", champion->process.pc, data->mem[proc->loca + 1]);
		if (encod(champion, data) > 0)
			return(ft_printf("Encodage correct\n"));
		else
			return(ft_printf("Encodage incorrect\n"));
	}
	else
		return(ft_printf("Pas d'encodage\n"));
	return (0);
}

int				corewar(t_cwdata *data)
{
	t_list		*tmp;
	t_header	*champion;
	int			i;

	i = 0;
	tmp = data->beginlist;
	while (tmp)
	{
		champion = (t_header *)tmp->content;
		champion->process.reg[0] = champion->id;
		champion->process.loca = data->begin_champ[i];
		champion->process.pc = data->mem[data->begin_champ[i]];
		ft_printf("name = %s, pc = %.2X\n", champion->prog_name, champion->process.pc);
		corewar_start(champion, data);
		tmp = tmp->next;
		i++;
	}
	return (0);
}