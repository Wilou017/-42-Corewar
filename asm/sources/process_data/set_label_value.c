/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_label_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:29 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:19:31 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			set_label_value(t_asm_data *data)
{
	int			i;
	char		*name;
	t_op_token	*tmp;
	t_op_token	*t1;
	t_label		*label;

	i = -1;
	tmp = data->token;
	label = data->label;
	name = NULL;
	while (tmp)
	{
		i = -1;
		while (tmp->arg && tmp->arg[++i])
		{
			name = ft_strdup(tmp->arg[i]);
			if (is_label(name))
			{
				t1 = tmp;
				set_index(data, tmp, tmp->arg[i]);
			}
			ft_memdel((void **)&name);
		}
		tmp = tmp->next;
	}
}
