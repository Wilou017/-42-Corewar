/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:30:07 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/01 16:00:46 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		write_map(t_cwdata *data, t_process *proc, int dest, int src)
{
	int		size;
	int		octet;
	int		value;
	int		start_write;

	size = sizeof(proc->reg[src]) - 1;
	value = proc->reg[src];
	start_write = dest % MEM_SIZE;
	while (size >= 0)
	{
		octet = value & 0xFF;
		value >>= 8;
		data->mem[(dest + size) % MEM_SIZE] = octet;
		size--;
	}
	if (data->show_vm)
		vm_print(data, proc, start_write);
}
