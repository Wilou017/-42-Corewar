/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:18:35 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:18:38 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void		write_indir(int fd, char *arg)
{
	int					value;

	value = ft_atoi(arg);
	write_bytecode(value, 2, fd);
}

static void		write_dir(int fd, t_op_token *token,
	int index, t_asm_data *data)
{
	int					label_size;
	int					value;
	char				*tmp;
	unsigned char		*bytecode;

	bytecode = NULL;
	label_size = search_label_size(data, token->opcode);
	tmp = ft_strsub(token->arg[index], 1, ft_strlen(token->arg[index]) - 1);
	value = ft_atoi(tmp);
	if (value < 0)
	{
		value *= -1;
		if (label_size == 2)
			write_bytecode1(65536 - value, 2, fd);
		else
			write_bytecode1(4294967296 - value, 4, fd);
	}
	else
		write_bytecode(value, label_size, fd);
}

static void		write_label(int fd, t_op_token *token, t_asm_data *data)
{
	unsigned char *bytecode;

	bytecode = NULL;
	if (token->label_index < 0)
	{
		token->label_index *= -1;
		if (search_label_size(data, token->opcode) == 2)
			write_bytecode1(65535 - token->label_index, 2, fd);
		else
			write_bytecode1(4294967295 - token->label_index, 4, fd);
	}
	else
		write_bytecode(token->label_index,
			search_label_size(data, token->opcode), fd);
}

static void		write_reg(int fd, char *arg)
{
	int					value;
	char				*tmp;

	tmp = ft_strsub(arg, 1, ft_strlen(arg) - 1);
	value = ft_atoi(tmp);
	free(tmp);
	write_bytecode(value, 1, fd);
}

void			write_arg(int fd, t_op_token *tok, int i, t_asm_data *data)
{
	char *tmp;

	tmp = ft_strdup(tok->arg[i]);
	if (tmp[0] == '%' && tmp[1] == ':')
		write_label(fd, tok, data);
	else if (tmp[0] == '%' && tmp[1] != ':')
		write_dir(fd, tok, i, data);
	else if (tmp && tmp[0] == 'r')
		write_reg(fd, tok->arg[i]);
	else
		write_indir(fd, tok->arg[i]);
	free(tmp);
}
