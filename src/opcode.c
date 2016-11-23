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

int			size_without_encod(int opcode)
{
	if (opcode == 1)
		return (5);
	else if (opcode == 9 || opcode == 12 || opcode == 15)
		return (3);
	return (0);
}

int			size_encod(int opcode)
{
	if (opcode == 16)
		return (2);
	else if (opcode == 2 || opcode == 3 || opcode == 13)
		return (4);
	else if (opcode == 4 || opcode == 5 || opcode == 6 || opcode == 7 \
		|| opcode == 8 || opcode == 10 || opcode == 11 || opcode == 14)
		return (6);
	return (0);
}