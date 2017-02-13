/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:10:31 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/21 19:10:32 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			true_param(int param)
{
	if (param == 0)
		return (1);
	if (param == 2)
		return (2);
	if (param == 4)
		return (3);
	return (0);
}

int			check_param_bis(int opcode, int param, int name)
{
	if (opcode == 10)
		return (param_ldi(param, name));
	else if (opcode == 11)
		return (param_sti(param, name));
	else if (opcode == 12)
		return (param_fork(param, name));
	else if (opcode == 13)
		return (param_lld(param, name));
	else if (opcode == 14)
		return (param_lldi(param, name));
	else if (opcode == 15)
		return (param_lfork(param, name));
	else if (opcode == 16)
		return (param_aff(param, name));
	else
		return (0);
}

int			check_param(int opcode, int param, int name)
{
	param = true_param(param);
	if (opcode == 1)
		return (param_live(param, name));
	else if (opcode == 2)
		return (param_ld(param, name));
	else if (opcode == 3)
		return (param_st(param, name));
	else if (opcode == 4)
		return (param_add(param, name));
	else if (opcode == 5)
		return (param_sub(param, name));
	else if (opcode == 6)
		return (param_and(param, name));
	else if (opcode == 7)
		return (param_or(param, name));
	else if (opcode == 8)
		return (param_xor(param, name));
	else if (opcode == 9)
		return (param_zjmp(param, name));
	else
		return (check_param_bis(opcode, param, name));
}
