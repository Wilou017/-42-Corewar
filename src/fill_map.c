/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:30:07 by dmathe            #+#    #+#             */
/*   Updated: 2016/12/08 19:30:24 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		write_map(t_cwdata *data, t_process *proc, int dest, int src)
{
	int		size;
	int		octet;
	int		value;

	(void)dest;
	(void)data;
	size = sizeof(proc->reg[src]) - 1;
	value = proc->reg[src];
	while (size >= 0)
	{
		octet = value & 0xFF;
		value >>= 8;
		data->mem[(dest + size) % MEM_SIZE] = octet;
		size--;
	}
}