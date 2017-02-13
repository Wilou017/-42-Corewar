/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:20:07 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/19 16:20:08 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

const char		*g_opcode[] =
{
	"live",
	"ld",
	"st",
	"add",
	"sub",
	"and",
	"or",
	"xor",
	"zjmp",
	"ldi",
	"sti",
	"fork",
	"lld",
	"lldi",
	"lfork",
	"aff",
	NULL
};

static void		fill_op_bis(t_optab_info *data)
{
	if (!ft_strcmp(data->name, "fork"))
		fill_fork(data);
	else if (!ft_strcmp(data->name, "lld"))
		fill_lld(data);
	else if (!ft_strcmp(data->name, "lldi"))
		fill_lldi(data);
	else if (!ft_strcmp(data->name, "lfork"))
		fill_lfork(data);
	else if (!ft_strcmp(data->name, "aff"))
		fill_aff(data);
}

static void		fill_op(t_optab_info *data)
{
	if (!ft_strcmp(data->name, "live"))
		fill_live(data);
	else if (!ft_strcmp(data->name, "ld"))
		fill_ld(data);
	else if (!ft_strcmp(data->name, "st"))
		fill_st(data);
	else if (!ft_strcmp(data->name, "add"))
		fill_add(data);
	else if (!ft_strcmp(data->name, "sub"))
		fill_sub(data);
	else if (!ft_strcmp(data->name, "and"))
		fill_and(data);
	else if (!ft_strcmp(data->name, "or"))
		fill_or(data);
	else if (!ft_strcmp(data->name, "xor"))
		fill_xor(data);
	else if (!ft_strcmp(data->name, "zjmp"))
		fill_zjmp(data);
	else if (!ft_strcmp(data->name, "ldi"))
		fill_ldi(data);
	else if (!ft_strcmp(data->name, "sti"))
		fill_sti(data);
	else
		fill_op_bis(data);
}

static void		parse_name(t_optab_info *data)
{
	t_optab_info	*tmp;

	tmp = data;
	if (tmp)
	{
		while (tmp)
		{
			fill_op(tmp);
			tmp = tmp->next;
		}
	}
}

t_optab_info	*create_op_tab(t_optab_info *data)
{
	int				i;

	i = 0;
	while (g_opcode[i])
	{
		list_add_next(&data, link_init((void *)g_opcode[i]));
		i++;
	}
	parse_name(data);
	return (data);
}
