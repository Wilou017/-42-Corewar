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
	unsigned int 		bin;

	value = ft_atoi(arg);
	if (value < 0)
	{
		value *= -1;
		bin = return_bytes(65536 - value, 2);
		write(fd, &bin, 2);
	}
	else
	{
		bin = return_bytes(value, 2);
		write(fd, &bin, 2);
	}
}

static void		write_dir(int fd, t_op_token *token,
	int index, t_asm_data *data)
{
	int					label_size;
	int					value;
	char				*tmp;
	unsigned int 		bin;

	label_size = search_label_size(data, token->opcode);
	tmp = ft_strsub(token->arg[index], 1, ft_strlen(token->arg[index]) - 1);
	value = ft_atoi(tmp);
	if (value < 0)
	{
		value *= -1;
		if (label_size == 2)
			bin = return_bytes(65536 - value, 2);
		else
			bin = return_bytes(4294967296 - value, 4);
	}
	else
		bin = return_bytes(value, label_size);
	write(fd, &bin, label_size);
}

static void		write_label(int fd, t_op_token *token, t_asm_data *data)
{
	unsigned int value;
	int			 label_size;

	value = 0;
	label_size = search_label_size(data, token->opcode);
	if (token->label_index < 0)
	{
		token->label_index *= -1;
		if (label_size == 2)
			value = return_bytes(65535 - token->label_index, label_size);
		else
			value = return_bytes(4294967296 - token->label_index, label_size);
	}
	else
		value = return_bytes(token->label_index, label_size);
	write(fd, &value, label_size);
}

static void		write_reg(int fd, char *arg)
{
	int					value;
	char				*tmp;

	tmp = ft_strsub(arg, 1, ft_strlen(arg) - 1);
	value = ft_atoi(tmp);
	free(tmp);
	value = return_bytes(value, 1);
	write(fd, &value, 1);
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
