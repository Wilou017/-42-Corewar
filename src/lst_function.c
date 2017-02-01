/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:03:17 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/01 19:08:25 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_header	*cw_add_champ_to_lst(t_cwdata *data)
{
	t_header	new_node;
	t_list		*champion_node;

	new_node.prog_name = ft_strnew(0);
	new_node.comment = ft_strnew(0);
	new_node.prog_size = 0;
	new_node.id = cw_get_valid_champ_id(data);
	new_node.nb_live = 0;
	new_node.if_live = 1;
	cw_add_process_to_lst(data, new_node.id, NULL);
	champion_node = ft_lstnew((void *)&new_node, sizeof(new_node));
	ft_lstadd(&data->beginlist, champion_node);
	return ((t_header*)champion_node->content);
}

t_process	cw_init_proc_data(t_cwdata *data, int id, t_process *proc)
{
	static		int		i = 1;
	t_process	new_node;

	new_node.name = i;
	i++;
	new_node.encod = 0;
	new_node.size = 0;
	new_node.carry = (proc) ? proc->carry : 0;
	new_node.id = data->nb_process;
	new_node.if_live = 1;
	new_node.nb_live = 0;
	new_node.wait_cicle = 0;
	new_node.move = 1;
	new_node.dont_move = 0;
	new_node.id_champ = id;
	new_node.good_cicle = 0;
	new_node.reg = ft_inttabnew(REG_NUMBER, 0);
	return (new_node);
}

t_process	*cw_add_process_to_lst(t_cwdata *data, int id, t_process *proc)
{

	t_process	new_node;
	t_list		*process_node;

	new_node = cw_init_proc_data(data, id, proc);
	data->nb_process++;
	data->nb_process_total++;
	if (data->verbose)
		ft_printf("\nProcess %d is born", new_node.name);
	if (data->verbose && proc)
		ft_printf(" in %d +", proc->loca);
	else
		ft_putchar('\n');
	if (proc == NULL)
		new_node.reg[0] = id;
	else if (!data->init)
		new_node.reg = ft_inttabdup(proc->reg, REG_NUMBER);
	process_node = ft_lstnew((void *)&new_node, sizeof(new_node));
	ft_lstadd(&data->processlist, process_node);
	return ((t_process*)process_node->content);
}

void	cw_del_process_to_lst(t_cwdata *data, t_list *prev_proc, t_list *del_proc)
{
	t_list *next_proc;

	if (del_proc)
	{
		next_proc = del_proc->next;
		free(((t_process*)(del_proc->content))->reg);
		free(((t_process*)(del_proc->content)));
		free(del_proc);
		if (prev_proc)
			prev_proc->next = next_proc;
		else
			data->processlist = next_proc;
	}
}
