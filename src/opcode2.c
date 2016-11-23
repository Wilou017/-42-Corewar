/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:03:19 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/22 15:03:21 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			param_aff(int param, int name)
{
	if (param == 1 && name == 1)
		return (1);
	else
		return (0);
}

int			param_lfork(int param, int name)
{
	if (param == 1 && name == 2)
		return (1);
	else
		return (0);
}

int			param_lldi(int param, int name)
{
	if (param == 1 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 2 && (name == 1 || name == 2))
		return (1);
	else if (param == 3 && name == 1)
		return (1);
	return (0);
}

int			param_lld(int param, int name)
{
	if (param == 1 && (name == 2 || name == 3))
		return (1);
	else if (param == 2 && name == 1)
		return (1);
	return (0);
}

int			param_fork(int param, int name)
{
	if (param == 1 && name == 2)
		return (1);
	else
		return (0);
}
