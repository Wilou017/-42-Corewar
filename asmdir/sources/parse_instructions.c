/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:20:23 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:20:25 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int			check_instructions1(t_asm_data *data, char **tab, int i)
{
	if (i == 6)
		return (and_instruction(data, tab));
	else if (i == 7)
		return (or_instruction(data, tab));
	else if (i == 8)
		return (xor_instruction(data, tab));
	else if (i == 9)
		return (zjmp_instruction(data, tab));
	else if (i == 10)
		return (ldi_instruction(data, tab));
	else if (i == 11)
		return (sti_instruction(data, tab));
	else if (i == 12)
		return (fork_instruction(data, tab));
	else if (i == 13)
		return (lld_instruction(data, tab));
	else if (i == 14)
		return (lldi_instruction(data, tab));
	else if (i == 15)
		return (lfork_instruction(data, tab));
	else if (i == 16)
		return (aff_instruction(data, tab));
	return (1);
}

static int			check_instructions(t_asm_data *data, char **tab)
{
	int		i;

	if (find_label(data->label, tab[0]) && tab[1])
		i = op_tabcmp(data->info_op, tab[1]);
	else
		i = op_tabcmp(data->info_op, tab[0]);
	if (!i)
	{
		ft_printf("tab[0] = {%s} && tab[1] = {%s}\n", tab[0], tab[1]);
		exit_failure("Fail Check Instructions", data);
	}
	else if (i == 1)
		return (live_instruction(data, tab));
	else if (i == 2)
		return (ld_instruction(data, tab));
	else if (i == 3)
		return (st_instruction(data, tab));
	else if (i == 4)
		return (add_instruction(data, tab));
	else if (i == 5)
		return (sub_instruction(data, tab));
	else
		return (check_instructions1(data, tab, i));
	return (1);
}

static int			check_buf(t_asm_data *data, char **tab)
{
	int		i;

	i = 0;
	if (tab && tab[0])
	{
		if (tab_len(tab) > 1)
			if (!check_instructions(data, tab))
				return (0);
	}
	return (1);
}

void				parse_instructions(t_asm_data *data, char *buff)
{
	char	**tab;

	tab = NULL;
	if (is_name(buff) || is_comment(buff))
	{
		if (!fill_header(data, buff))
			exit_failure("Fail Header Format", data);
	}
	else
	{
		tab = ft_strsplit(buff, ' ');
		if (!check_buf(data, tab))
		{
			tab_delete(&tab);
			exit_failure("Fail Instructions Format", data);
		}
		tab_delete(&tab);
	}
}
