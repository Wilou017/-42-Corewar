/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:21:19 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:21:20 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void				tab_delete(char ***tab)
{
	int				i;

	i = 0;
	if (*tab)
	{
		while (*tab && (*tab)[i])
		{
			free((*tab)[i]);
			i++;
		}
		free(*tab);
	}
}

int					op_tabcmp(t_optab_info *op_tab, char *str)
{
	t_optab_info	*tmp;

	tmp = op_tab;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str))
			return (tmp->opcode);
		tmp = tmp->next;
	}
	return (0);
}

int					tab_len(char **tab)
{
	int				i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void				print_tab(char **tab)
{
	int				i;

	i = 0;
	while (tab && tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
