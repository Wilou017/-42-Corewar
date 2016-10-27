/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:03:17 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/27 18:13:04 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

header2_t	*cw_add_champ_to_lst(t_cwdata *data)
{
	header2_t	new_champion_node;
	t_list		*champion_node;


	new_champion_node.prog_name = ft_strnew(0);
	new_champion_node.comment = ft_strnew(0);
	champion_node = ft_lstnew((void *)&new_champion_node, sizeof(new_champion_node));

	ft_lstadd_push_back(&data->beginlist, champion_node);

	return ((header2_t*)champion_node->content);
}
