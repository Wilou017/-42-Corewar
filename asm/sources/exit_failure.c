/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:56:11 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 15:56:12 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		exit_failure(char *error, t_asm_data *asm_data)
{
	ft_putendl_fd(error, 2);
	data_delete(asm_data);
	exit(1);
}
