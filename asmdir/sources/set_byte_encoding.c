/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_byte_encoding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:19:01 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:19:02 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int			opcode_need_encoding(t_asm_data *data, t_op_token *token)
{
	t_optab_info	*tmp;

	tmp = data->info_op;
	while (tmp->opcode != token->opcode)
		tmp = tmp->next;
	return (tmp->if_codage);
}

int					arg_identifier(char *str)
{
	if (str)
	{
		if (str[0] == '%')
			return (2);
		else if (str[0] == 'r')
			return (1);
		else
			return (3);
	}
	else
		return (0);
}

static void			set_byte_encoding_ext(char **byte, char *arg, int j)
{
	if (arg_identifier(arg) == 1)
	{
		(*byte)[j] = '0';
		(*byte)[j + 1] = '1';
	}
	else if (arg_identifier(arg) == 2)
	{
		(*byte)[j] = '1';
		(*byte)[j + 1] = '0';
	}
	else if (arg_identifier(arg) == 3)
	{
		(*byte)[j] = '1';
		(*byte)[j + 1] = '1';
	}
}

void				set_byte_encoding(t_asm_data *data, t_op_token *token)
{
	char			*byte;
	int				i;
	int				j;

	byte = NULL;
	i = 0;
	j = 0;
	if (opcode_need_encoding(data, token))
	{
		byte = ft_memset(ft_strnew(8), '0', 8);
		while (i < token->nbr_args)
		{
			set_byte_encoding_ext(&byte, (token->arg)[i], j);
			i++;
			j += 2;
		}
		token->byte_encoding = ft_atoi_base(byte, 2);
		ft_memdel((void **)&byte);
	}
	else
		token->byte_encoding = -1;
}
