/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:17:12 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:17:17 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			check_argv(char *av, t_asm_data *asm_data)
{
	int			fd;
	char		*tmp;

	tmp = ft_strsub(av, ft_strlen(av) - 2, 2);
	if (!ft_strequ(tmp, ".s"))
	{
		exit_failure(" - Only \".s\" extension", asm_data);
		asm_data->error = 1;
	}
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		exit_failure(" - File not found", asm_data);
		asm_data->error = 1;
	}
	ft_memdel((void **)&tmp);
}
