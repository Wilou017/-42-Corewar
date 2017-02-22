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

#include <asm.h>

int				main(int ac, char **av)
{
	t_asm_data	asm_data;
	int			i;

	i = 0;
	if (ac < 2)
		ft_putendl("Need some arguments");
	else
	{
		while (++i < ac)
		{
			data_init(&asm_data);
			check_argv(av[i], &asm_data);
			parse(&asm_data, av[i]);
			process_data(&asm_data);
			if (asm_data.prog_size <= 0)
				exit_failure("Error no code", &asm_data);
			bytecode_generator(&asm_data, av[i]);
			data_delete(&asm_data);
		}
	}
	return (0);
}
