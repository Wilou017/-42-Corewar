/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:15:30 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/29 18:14:26 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int main(int argc, t_tab argv)
{
	t_cwdata	data;

	if(argc > 1)
	{
		data.v = argv;
		data.c = argc - 1;
		cw_init(&data);
		cw_freeall(&data);
	}
	else
		ft_printf("{lgreen}use: ./corewar [-dump nbr_cycles] [[-n number] champ\
ion1.cor] ...{eoc}\n");
	return (0);
}