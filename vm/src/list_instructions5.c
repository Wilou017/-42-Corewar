/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:16:36 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/21 20:16:38 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			cw_add(t_cwdata *data, t_process *proc)
{
	t_inst		inst;

	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_ADD;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		init_instruc(proc, &inst);
		if (!if_registre(data, proc, inst))
			return ;
		if (data->verbose)
			ft_printf("P %4d | add", proc->name);
		proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE] - 1] = \
		proc->reg[data->mem[(proc->loca + 2) % MEM_SIZE] - 1] + \
		proc->reg[data->mem[(proc->loca + 3) % MEM_SIZE] - 1];
		check_reg_carry(proc, proc->reg[data->mem[(proc->loca + 4) % MEM_SIZE]
			- 1]);
		if (data->verbose)
			ft_printf(" r%d r%d r%d\n", data->mem[(proc->loca + 2) % MEM_SIZE]
			, data->mem[(proc->loca + 3) % MEM_SIZE]\
			, data->mem[(proc->loca + 4) % MEM_SIZE]);
	}
	else
		bad_encodage(proc);
}

void			cw_stinorme2(int *adresse, t_process *proc, int *new_loca,
	int *newloca_verbose)
{
	if (adresse < 0)
	{
		*new_loca = (proc->loca - (-(*adresse) % IDX_MOD)) % MEM_SIZE;
		*newloca_verbose = (proc->loca - (-(*adresse) % IDX_MOD));
	}
	else
	{
		*new_loca = (proc->loca + (*adresse % IDX_MOD)) % MEM_SIZE;
		*newloca_verbose = (proc->loca + (*adresse % IDX_MOD));
	}
	if (new_loca < 0)
		*adresse = *new_loca + MEM_SIZE;
	else
		*adresse = *new_loca;
}

int				cw_stinorme1(t_inst inst, t_process *proc, t_cwdata *data)
{
	if (!if_registre(data, proc, inst))
		return (0);
	if (data->verbose)
		ft_printf("P %4d | sti", proc->name);
	return (1);
}

int				cw_stinorme3(t_cwdata *data, t_process *proc)
{
	t_inst		inst;
	t_param		param;
	int			adresse;
	int			new_loca;
	int			newloca_verbose;

	init_param(&param);
	init_instruc(proc, &inst);
	if (!cw_stinorme1(inst, proc, data))
		return (0);
	param.param1 = bin_offset(proc, data, 0, &inst) - 1;
	param.param2 = bin_offset(proc, data, 2, &inst);
	if (inst.param == REG_CODE)
		param.param2 = proc->reg[param.param2 - 1];
	param.param3 = bin_offset(proc, data, 4, &inst);
	if (inst.param == REG_CODE)
		param.param3 = proc->reg[param.param3 - 1];
	adresse = param.param2 + param.param3;
	cw_stinorme2(&adresse, proc, &new_loca, &newloca_verbose);
	write_map(data, proc, adresse, param.param1);
	if (data->verbose)
		print_verbose_details(param.param1, param.param2, param.param3,
		newloca_verbose);
	return (1);
}

void			cw_sti(t_cwdata *data, t_process *proc)
{
	proc->encod = data->mem[(proc->loca + 1) % MEM_SIZE];
	if (proc->wait_cicle == -1)
		proc->wait_cicle = WAIT_STI;
	if (proc->wait_cicle == 0 && !proc->bad_encodage)
	{
		if (!cw_stinorme3(data, proc))
			return ;
	}
	else
		bad_encodage(proc);
}
