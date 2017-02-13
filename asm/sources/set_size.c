/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:08 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:19:11 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			set_size(t_asm_data *data, t_op_token *token)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (token->byte_encoding != -1)
		token->size += 1;
	while (i < token->nbr_args)
	{
		if ((a = arg_identifier(token->arg[i])) == 1)
			token->size += 1;
		else if (a == 2)
			token->size += search_label_size(data, token->opcode);
		else
			token->size += 2;
		i++;
	}
}
