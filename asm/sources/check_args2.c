/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:25:45 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/28 16:25:46 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ldi_instruction_bis(t_asm_data *data, char **tab, int len)
{
	if (len != 4)
		return (0);
	if (!if_reg(tab[1], 0) && !if_dir(tab[1], data->label, 0) &&
		!if_ind(tab[1], data->label, 0))
		return (0);
	if (!if_reg(tab[2], 0) && !if_ind(tab[2], data->label, 0))
		return (0);
	if (!if_reg(tab[3], 1))
		return (0);
	return (1);
}

int				ldi_instruction(t_asm_data *data, char **tab)
{
	int			len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 5)
			return (0);
		if (!if_reg(tab[2], 0) && !if_dir(tab[2], data->label, 0) &&
			!if_ind(tab[2], data->label, 0))
			return (0);
		if (!if_reg(tab[3], 0) && !if_ind(tab[3], data->label, 0))
			return (0);
		if (!if_reg(tab[4], 1))
			return (0);
	}
	else
		return (ldi_instruction_bis(data, tab, len));
	return (1);
}

int				zjmp_instruction(t_asm_data *data, char **tab)
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

int				xor_instruction_bis(t_asm_data *data, char **tab, int len)
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

int				xor_instruction(t_asm_data *data, char **tab)
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
		return (xor_instruction_bis(data, tab, len));
	return (1);
}
