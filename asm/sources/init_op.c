/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:34:26 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/19 14:34:28 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void				list_add_next(t_optab_info **data, t_optab_info *link)
{
	t_optab_info *tmp;

	tmp = *data;
	if (link)
	{
		if (!tmp)
			(*data) = link;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = link;
			link->prev = tmp;
			link->next = NULL;
		}
	}
}

t_optab_info		*link_init(void *data)
{
	t_optab_info	*new_link;

	new_link = (t_optab_info *)malloc(sizeof(t_optab_info));
	if (new_link == NULL)
		return (NULL);
	new_link->name = (char *)ft_strdup(data);
	new_link->next = NULL;
	new_link->prev = NULL;
	new_link->nbr_args = 0;
	new_link->opcode = 0;
	new_link->nbr_cycles = 0;
	new_link->if_codage = 0;
	new_link->if_carry = 0;
	new_link->label_size = 0;
	return (new_link);
}
