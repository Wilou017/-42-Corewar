/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:18:54 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:18:55 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				find_index(t_asm_data *data)
{
	t_op_token	*tmp;
	int			i;

	i = 0;
	if (data->token)
	{
		tmp = data->token;
		while (tmp->next)
			tmp = tmp->next;
		i = tmp->index + 1;
	}
	return (i);
}

void			process_data(t_asm_data *data)
{
	int			i;
	t_op_token	*token;

	i = -1;
	token = NULL;
	while ((data->file)[++i])
		if (!is_name((data->file)[i]) && !is_comment((data->file)[i]))
			fill_token(data, (data->file)[i]);
	token = data->token;
	while (token)
	{
		set_byte_encoding(data, token);
		set_size(data, token);
		data->prog_size += token->size;
		token = token->next;
	}
	tab_delete(&(data->file));
	set_label_value(data);
}
