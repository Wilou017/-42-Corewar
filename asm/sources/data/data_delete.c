/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:42 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:19:44 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void				free_label_chain(t_asm_data *data)
{
	t_label		*label;
	t_label		*tmp;

	label = data->label;
	tmp = NULL;
	while (label)
	{
		tmp = label->next;
		ft_memdel((void **)&(label->name));
		free(label);
		label = tmp;
	}
}

static void				free_optab_chain(t_asm_data *data)
{
	t_optab_info		*op_tab;
	t_optab_info		*tmp;

	op_tab = data->info_op;
	tmp = NULL;
	while (op_tab)
	{
		tmp = op_tab->next;
		ft_memdel((void **)&(op_tab->name));
		free(op_tab);
		op_tab = tmp;
	}
}

static void				free_token_chain(t_asm_data *data)
{
	t_op_token			*token;
	t_op_token			*tmp;

	token = data->token;
	tmp = NULL;
	while (token)
	{
		tmp = token->next;
		tab_delete(&(token->arg));
		free(token);
		token = tmp;
	}
}

void					data_delete(t_asm_data *data)
{
	free_label_chain(data);
	free_optab_chain(data);
	free_token_chain(data);
	ft_memdel((void **)&(data->name));
	ft_memdel((void **)&(data->comment_name));
	data->label = NULL;
	data->token = NULL;
	data->info_op = NULL;
	data->file = NULL;
	data->prog_size = 0;
}
