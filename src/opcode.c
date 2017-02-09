/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:16:14 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/20 17:16:17 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			param_live(int param, int name)
{
	if (param == 1 && name == 2)
		return (1);
	return (0);
}

int			size_without_encod(t_func opcode)
{
	if (opcode == LIVE)
		return (5);
	else if (opcode == ZJUMP || opcode == FORK || opcode == LFORK)
		return (3);
	return (0);
}

int			size_encod(t_func opcode)
{
	if (opcode == AFF)
		return (2);
	else if (opcode == LD || opcode == ST || opcode == LLD)
		return (4);
	else if (opcode == ADD || opcode == SUB || opcode == AND || opcode == OR \
		|| opcode == XOR || opcode == LDI || opcode == STI || opcode == LLDI)
		return (6);
	return (0);
}