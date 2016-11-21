/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:03:17 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/17 17:40:34 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_header	*cw_add_champ_to_lst(t_cwdata *data)
{
	t_header	new_node;
	t_list		*champion_node;
	int			i;

	i = 0;
	new_node.prog_name = ft_strnew(0);
	new_node.comment = ft_strnew(0);
	new_node.prog_size = 0;
	new_node.process.pc = 0;
	new_node.process.loca = 0;
	new_node.process.carry = 0;
	new_node.process.reg = ft_inttabnew(REG_NUMBER, 0);
	champion_node = ft_lstnew((void *)&new_node, sizeof(new_node));
	ft_lstadd(&data->beginlist, champion_node);
	return ((t_header*)champion_node->content);
}

void		cw_freeall(t_cwdata *data)
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = data->beginlist;
	while (tmp)
	{
		free(((t_header*)tmp->content)->prog_name);
		free(((t_header*)tmp->content)->comment);
		free(tmp->content);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

void		cw_pushback_inst(t_header *champion, t_instnode *new)
{
	new->prev = champion->inst.end;
	new->next = NULL;
	champion->inst.size++;
	(champion->inst.end) ? champion->inst.end->next = new : 0;
	champion->inst.end = new;
	(champion->inst.start == NULL) ? champion->inst.start = new : 0;
}
