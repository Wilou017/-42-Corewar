/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:05:04 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/22 15:05:05 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			param_and(int param, int name)
{
	if (param == 1 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 2 && (name == 1 || name == 2 || name == 3))
		return (1);
	else if (param == 3 && name == 1)
		return (1);
	return (0);
}

int			param_sub(int param, int name)
{
	if (param == 1 || param == 2 || param == 3)
	{
		if (name == 1)
			return (1);
	}
	return (0);
}

int			param_add(int param, int name)
{
	if (param == 1 || param == 2 || param == 3)
	{
		if (name == 1)
			return (1);
	}
	return (0);
}

int			param_st(int param, int name)
{
	if (param == 1)
	{
		if (name == 1)
			return (1);
	}
	else if (param == 2)
	{
		if (name == 1 || name == 3)
			return (1);
	}
	return (0);
}

int			param_ld(int param, int name)
{
	if (param == 1)
	{
		if (name == 2 || name == 3)
			return (1);
	}
	else if (param == 2)
	{
		if (name == 1)
			return (1);
	}
	return (0);
}
