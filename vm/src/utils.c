/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:17:02 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/01 19:26:51 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		if_encodage(int opcode)
{
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
		return (0);
	else
		return (1);
}

void	init_param(t_param *param)
{
	param->param1 = 0;
	param->param2 = 0;
	param->param3 = 0;
}

void	check_reg_carry(t_process *proc, int reg)
{
	if (reg == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}

void	good_cicle(t_process *proc)
{
	if (proc->wait_cicle == 0)
		proc->good_cicle = 1;
	else
		proc->good_cicle = 0;
}

int		return_size_reg(t_cwdata *data, t_process *proc, int adresse, int lldi)
{
	int	new_loca;
	int	value;

	if (adresse < 0 && lldi != 1)
		new_loca = (proc->loca - (-adresse % IDX_MOD)) % MEM_SIZE;
	else
		new_loca = (proc->loca + (adresse % IDX_MOD)) % MEM_SIZE;
	if (adresse < 0 && lldi == 1)
		new_loca = (proc->loca + adresse) % MEM_SIZE;
	new_loca = (new_loca < 0) ? new_loca + MEM_SIZE : new_loca;
	if (data->verbose && lldi != 2)
		ft_printf(" %d)\n", new_loca);
	value = (data->mem[new_loca] << 8) + data->mem[(new_loca + 1) % MEM_SIZE];
	value = (value << 8) + data->mem[(new_loca + 2) % MEM_SIZE];
	value = (value << 8) + data->mem[(new_loca + 3) % MEM_SIZE];
	return (value);
}
