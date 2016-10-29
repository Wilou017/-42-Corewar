/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:03:17 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/29 18:10:18 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

header2_t	*cw_add_champ_to_lst(t_cwdata *data)
{
	header2_t	new_node;
	t_list		*champion_node;


	new_node.prog_name = ft_strnew(0);
	new_node.comment = ft_strnew(0);
	champion_node = ft_lstnew((void *)&new_node, sizeof(new_node));

	ft_lstadd_push_back(&data->beginlist, champion_node);

	return ((header2_t*)champion_node->content);
}

void		cw_freeall(t_cwdata *data)
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = data->beginlist;
	while (tmp)
	{
		free(((header2_t*)tmp->content)->prog_name);
		free(((header2_t*)tmp->content)->comment);
		free(tmp->content);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}