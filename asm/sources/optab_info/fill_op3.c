/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_op3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:08 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/20 16:10:10 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		fill_sti(t_optab_info *data)
{
	data->nbr_args = 3;
	data->opcode = 11;
	data->nbr_cycles = 25;
	data->if_codage = 1;
	data->if_carry = 1;
	data->label_size = 2;
}

void		fill_fork(t_optab_info *data)
{
	data->nbr_args = 1;
	data->opcode = 12;
	data->nbr_cycles = 800;
	data->if_codage = 0;
	data->if_carry = 1;
	data->label_size = 2;
}

void		fill_lld(t_optab_info *data)
{
	data->nbr_args = 2;
	data->opcode = 13;
	data->nbr_cycles = 10;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_lldi(t_optab_info *data)
{
	data->nbr_args = 3;
	data->opcode = 14;
	data->nbr_cycles = 50;
	data->if_codage = 1;
	data->if_carry = 1;
	data->label_size = 2;
}

void		fill_lfork(t_optab_info *data)
{
	data->nbr_args = 1;
	data->opcode = 15;
	data->nbr_cycles = 1000;
	data->if_codage = 0;
	data->if_carry = 1;
	data->label_size = 2;
}
