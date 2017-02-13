/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:41:14 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/19 19:41:15 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		fill_and(t_optab_info *data)
{
	data->nbr_args = 3;
	data->opcode = 6;
	data->nbr_cycles = 6;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_or(t_optab_info *data)
{
	data->nbr_args = 3;
	data->opcode = 7;
	data->nbr_cycles = 6;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_xor(t_optab_info *data)
{
	data->nbr_args = 3;
	data->opcode = 8;
	data->nbr_cycles = 6;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 4;
}

void		fill_zjmp(t_optab_info *data)
{
	data->nbr_args = 1;
	data->opcode = 9;
	data->nbr_cycles = 20;
	data->if_codage = 0;
	data->if_carry = 1;
	data->label_size = 2;
}

void		fill_ldi(t_optab_info *data)
{
	data->nbr_args = 3;
	data->opcode = 10;
	data->nbr_cycles = 25;
	data->if_codage = 1;
	data->if_carry = 1;
	data->label_size = 2;
}
