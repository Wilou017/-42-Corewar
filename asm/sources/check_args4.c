/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:59:26 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/28 16:59:27 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			aff_instruction(t_asm_data *data, char **tab)
{
	int		len;

	len = tab_len(tab);
	if (find_label(data->label, tab[0]))
	{
		if (len != 3)
			return (0);
		if (!if_reg(tab[2], 1))
			return (0);
	}
	else
	{
		if (len != 2)
			return (0);
		if (!if_reg(tab[1], 1))
			return (0);
	}
	return (1);
}

int			lfork_instruction(t_asm_data *data, char **tab)
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
