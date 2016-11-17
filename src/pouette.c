/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pouette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:17:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/17 17:44:27 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <corewar.h>

void	cw_printmemory(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%.2X ", (tab[i] == -1) ? 0 : tab[i]);
		i++;
		if (i % 10 == 0)
			ft_putchar('\n');
	}
}

int		cw_pouette(t_reedstruct reed, t_header2 *champion)
{
	ft_printf("\n\nNom     = %s\n", champion->prog_name);
	ft_printf("Comment = %s\n", champion->comment);

	// ft_showtabint(reed.inst_tab, reed.inst_size, "inst_tab", 0); // Affiche le tableau du programme en int decimal

	cw_createnode(champion, reed.inst_tab, reed.inst_size); // emvoye le tableau a la fonction de paring de dave
	cw_printmemory(reed.inst_tab, reed.inst_size);
	return (0);
}