/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_label_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:19 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:19:20 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					search_label_size(t_asm_data *data, int opcode)
{
	t_optab_info	*tmp;

	tmp = data->info_op;
	while (opcode != tmp->opcode)
		tmp = tmp->next;
	return (tmp->label_size);
}
