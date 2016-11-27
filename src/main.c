/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:15:30 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/26 16:41:29 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int	main(int argc, t_tab argv)
{
	t_cwdata	data;

	if (argc > 1)
	{
		data.v = argv;
		data.c = argc - 1;
		if (cw_init(&data))
			return (1);
		fill_map(&data);
		cw_loop(&data);
		cw_freeall(&data);
	}
	else
		ft_printf("{lgreen}use: ./corewar [-dump nbr_cycles] [[-n number] champ\
ion1.cor] ...{eoc}\n");
	return (0);
}
