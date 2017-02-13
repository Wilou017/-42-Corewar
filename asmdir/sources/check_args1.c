/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:12:29 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/28 16:12:30 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			fork_instruction(t_asm_data *data, char **tab)
{
	int		len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 3)
			return (0);
		if (!if_dir(tab[2], data->label, 1))
			return (0);
	}
	else
	{
		if (len != 2)
			return (0);
		if (!if_dir(tab[1], data->label, 1))
			return (0);
	}
	return (1);
}

int			or_instruction_bis(t_asm_data *data, char **tab, int len)
{
	if (len != 4)
		return (0);
	if (!if_reg(tab[1], 0) && !if_dir(tab[1], data->label, 0) &&
		!if_ind(tab[1], data->label, 0))
		return (0);
	if (!if_reg(tab[2], 0) && !if_dir(tab[2], data->label, 0) &&
		!if_ind(tab[2], data->label, 0))
		return (0);
	if (!if_reg(tab[3], 1))
		return (0);
	return (1);
}

int			or_instruction(t_asm_data *data, char **tab)
{
	int		len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 5)
			return (0);
		if (!if_reg(tab[2], 0) && !if_dir(tab[2], data->label, 0) &&
			!if_ind(tab[2], data->label, 0))
			return (0);
		if (!if_reg(tab[3], 0) && !if_dir(tab[3], data->label, 0) &&
			!if_ind(tab[3], data->label, 0))
			return (0);
		if (!if_reg(tab[4], 1))
			return (0);
	}
	else
	{
		if (!or_instruction_bis(data, tab, len))
			return (0);
	}
	return (1);
}

int			and_instruction_bis(t_asm_data *data, char **tab, int len)
{
	if (len != 4)
		return (0);
	if (!if_reg(tab[1], 0) && !if_dir(tab[1], data->label, 0) &&
		!if_ind(tab[1], data->label, 0))
		return (0);
	if (!if_reg(tab[2], 0) && !if_dir(tab[2], data->label, 0) &&
		!if_ind(tab[2], data->label, 0))
		return (0);
	if (!if_reg(tab[3], 1))
		return (0);
	return (1);
}

int			and_instruction(t_asm_data *data, char **tab)
{
	int		len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 5)
			return (0);
		if (!if_reg(tab[2], 0) && !if_dir(tab[2], data->label, 0) &&
			!if_ind(tab[2], data->label, 0))
			return (0);
		if (!if_reg(tab[3], 0) && !if_dir(tab[3], data->label, 0) &&
			!if_ind(tab[3], data->label, 0))
			return (0);
		if (!if_reg(tab[4], 1))
			return (0);
	}
	else
	{
		if (!and_instruction_bis(data, tab, len))
			return (0);
	}
	return (1);
}
