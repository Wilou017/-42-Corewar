/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:37:43 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/08 19:45:35 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			print_verbose_details_load(t_cwdata *data, t_param param)
{
	if (data->verbose)
		ft_printf("       | -> load from %d + %d = %d (with pc and mod", param.param1,
		param.param2, param.param1 + param.param2);
}

void			print_verbose_details(int param1, int param2, int param3, int newloca_verbose)
{
	ft_printf(" r%d %d %d\n", param1 + 1, param2, param3);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", param2, param3, param2 + param3, newloca_verbose);
}

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
