/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:18:45 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:18:46 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void		instructions_generator(int fd, t_asm_data *data)
{
	t_op_token	*tok;
	char		*tmp;
	int			i;

	tok = data->token;
	i = 0;
	tmp = NULL;
	while (tok)
	{
		i = -1;
		write_bytecode(tok->opcode, 1, fd);
		if (tok->byte_encoding != -1)
			write_bytecode(tok->byte_encoding, 1, fd);
		while (++i < tok->nbr_args)
			write_arg(fd, tok, i, data);
		tok = tok->next;
	}
}

static void		header_generator(int fd, t_asm_data *data)
{
	unsigned char *tmp;

	tmp = (unsigned char *)malloc(sizeof(unsigned char) * 2052);
	write(fd, "\x00\xea\x83\xf3", sizeof(int));
	write(fd, data->name, ft_strlen(data->name));
	tmp = ft_memset(tmp, 0, (PROG_NAME_LENGTH - ft_strlen(data->name)) + 4);
	write(fd, tmp, PROG_NAME_LENGTH - ft_strlen(data->name) + 4);
	write_bytecode(data->prog_size, sizeof(int), fd);
	write(fd, data->comment_name, ft_strlen(data->comment_name));
	tmp = ft_memset(tmp, 0, COMMENT_LENGTH - ft_strlen(data->comment_name) + 4);
	write(fd, tmp, COMMENT_LENGTH - ft_strlen(data->comment_name) + 4);
	ft_memdel((void **)&tmp);
}

static char		*get_name(char *argv)
{
	char *name;
	char *tmp;

	name = NULL;
	tmp = NULL;
	if (argv && argv[ft_strlen(argv) - 1] == 's'
		&& argv[ft_strlen(argv) - 2] == '.')
	{
		tmp = ft_strsub(argv, 0, ft_strlen(argv) - 2);
		name = ft_strjoin(tmp, ".cor");
		ft_memdel((void **)&tmp);
	}
	else
		name = ft_strjoin(argv, ".cor");
	return (name);
}

void			bytecode_generator(t_asm_data *data, char *argv)
{
	int			fd;
	char		*champion;

	champion = get_name(argv);
	fd = open(champion, O_RDWR | O_CREAT, 00700);
	header_generator(fd, data);
	instructions_generator(fd, data);
	ft_putstr("Writing Output In ");
	ft_putendl(champion);
	ft_memdel((void **)&champion);
}
