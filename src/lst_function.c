/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:03:17 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/05 22:15:34 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_header	*cw_add_champ_to_lst(t_cwdata *data)
{
	t_header	new_node;
	t_list		*champion_node;
	t_process	*proc;

	proc = NULL;
	new_node.prog_name = ft_strnew(0);
	new_node.comment = ft_strnew(0);
	new_node.prog_size = 0;
	new_node.id = (data->lastdata) ? ft_atoi(data->lastdata) :\
	data->nb_champion;
	new_node.id = -(new_node.id);
	new_node.nb_live = 0;
	new_node.if_live = 1;
	cw_add_process_to_lst(data, new_node.id, proc, 0);
	champion_node = ft_lstnew((void *)&new_node, sizeof(new_node));
	ft_lstadd(&data->beginlist, champion_node);
	return ((t_header*)champion_node->content);
}

t_process	*cw_add_process_to_lst(t_cwdata *data, int id, t_process *proc, int fork)
{
	static		int		i = 1;
	t_process	new_node;
	t_list		*process_node;

	new_node.name = i;
	i++;
	new_node.encod = 0;
	new_node.size = 0;
	new_node.carry = 0;
	new_node.id = data->nb_process;
	new_node.if_live = 1;
	new_node.nb_live = 0;
	new_node.wait_cicle = 0;
	new_node.move = 1;
	new_node.dont_move = 0;
	data->nb_process++;
	if (!fork)
		new_node.id_champ = id;
	else
		new_node.id_champ = proc->id_champ;
	new_node.good_cicle = 0;
	new_node.reg = ft_inttabnew(REG_NUMBER, 0);
	if (!fork)
		new_node.reg[0] = id;
	else
		new_node.reg = ft_inttabdup(proc->reg, REG_NUMBER);
	process_node = ft_lstnew((void *)&new_node, sizeof(new_node));
	ft_lstadd(&data->processlist, process_node);
	return ((t_process*)process_node->content);
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
