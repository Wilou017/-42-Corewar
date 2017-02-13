/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:03:26 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/22 15:03:28 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			param_sti(int param, int name)
{
	if (param == 1 && name == 1)
		return (1);
	else if (param == 2 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 3 && (name == 1 || name == 2))
		return (1);
	return (0);
}

int			param_ldi(int param, int name)
{
	if (param == 1 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 2 && (name == 1 || name == 2))
		return (1);
	else if (param == 3 && name == 1)
		return (1);
	return (0);
}

int			param_zjmp(int param, int name)
{
	if (param == 1 && name == 2)
		return (1);
	else
		return (0);
}

int			param_xor(int param, int name)
{
	if (param == 1 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 2 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 3 && name == 1)
		return (1);
	return (0);
}

int			param_or(int param, int name)
{
	if (param == 1 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 2 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 3 && name == 1)
		return (1);
	return (0);
}
