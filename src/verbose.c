/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:36:33 by dmathe            #+#    #+#             */
/*   Updated: 2016/12/08 21:36:35 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		print_verbose(t_cwdata *data, int param, int end, t_inst inst)
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