/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:20:00 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:20:01 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void				parse(t_asm_data *data, char *av)
{
	int				i;

	i = -1;
	if (read_clean(data, av) == -1)
		exit_failure(" -- Error While Reading File", data);
	while ((data->file)[++i])
		if (!parse_label(data, (data->file)[i]))
			exit_failure(" -- Error Label Format", data);
	i = -1;
	while ((data->file)[++i])
		parse_instructions(data, (data->file)[i]);
}
