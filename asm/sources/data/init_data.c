/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:50 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:19:51 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void				data_init(t_asm_data *asm_data)
{
	t_label			*label;
	t_op_token		*token;

	label = NULL;
	token = NULL;
	asm_data->file = NULL;
	asm_data->name = NULL;
	asm_data->comment_name = NULL;
	asm_data->prog_size = 0;
	asm_data->label = label;
	asm_data->info_op = NULL;
	asm_data->info_op = create_op_tab(asm_data->info_op);
	asm_data->token = token;
	asm_data->error = 0;
}
