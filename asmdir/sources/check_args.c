/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:16:29 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/22 17:16:31 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				sub_instruction(t_asm_data *data, char **tab)
{
	int			len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 5)
			return (0);
		if (!if_reg(tab[2], 0) || !if_reg(tab[3], 0) || !if_reg(tab[4], 1))
			return (0);
	}
	else
	{
		if (len != 4)
			return (0);
		if (!if_reg(tab[1], 0) || !if_reg(tab[2], 0) || !if_reg(tab[3], 1))
			return (0);
	}
	return (1);
}

int				add_instruction(t_asm_data *data, char **tab)
{
	int			len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 5)
			return (0);
		if (!if_reg(tab[2], 0) || !if_reg(tab[3], 0) || !if_reg(tab[4], 1))
			return (0);
	}
	else
	{
		if (len != 4)
			return (0);
		if (!if_reg(tab[1], 0) || !if_reg(tab[2], 0) || !if_reg(tab[3], 1))
			return (0);
	}
	return (1);
}

int				st_instruction(t_asm_data *data, char **tab)
{
	int			len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 4)
			return (0);
		if (if_reg(tab[2], 0) && (if_reg(tab[3], 1) ||
			if_ind(tab[3], data->label, 1)))
			return (1);
		else
			return (0);
	}
	else
	{
		if (len != 3)
			return (0);
		if (if_reg(tab[1], 0) && (if_reg(tab[2], 1) ||
			if_ind(tab[2], data->label, 1)))
			return (1);
		else
			return (0);
	}
	return (1);
}

int				ld_instruction(t_asm_data *data, char **tab)
{
	int			len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 4)
			return (0);
		if ((if_dir(tab[2], data->label, 0) ||
			if_ind(tab[2], data->label, 0)) && if_reg(tab[3], 1))
			return (1);
		else
			return (0);
	}
	else
	{
		if (len != 3)
			return (0);
		if ((if_dir(tab[1], data->label, 0) ||
			if_ind(tab[1], data->label, 0)) && if_reg(tab[2], 1))
			return (1);
		else
			return (0);
	}
	return (1);
}

int				live_instruction(t_asm_data *data, char **tab)
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
