/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_op4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:18:27 by dmathe            #+#    #+#             */
/*   Updated: 2016/09/20 16:18:31 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		fill_aff(t_optab_info *data)
{
	data->nbr_args = 1;
	data->opcode = 16;
	data->nbr_cycles = 2;
	data->if_codage = 1;
	data->if_carry = 0;
	data->label_size = 0;
}
