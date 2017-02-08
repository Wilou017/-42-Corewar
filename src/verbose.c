/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:37:43 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/08 15:37:46 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			print_verbose(t_cwdata *data, int param, int end, t_inst inst)
{
	if (data->verbose)
	{
		if (inst.param == REG_CODE)
			ft_printf(" r%d", param);
		else
			ft_printf(" %d", param);
		if (end)
			ft_printf("\n");
	}
}
