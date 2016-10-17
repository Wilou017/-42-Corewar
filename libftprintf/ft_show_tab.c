/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:07:48 by amaitre           #+#    #+#             */
/*   Updated: 2016/03/04 20:12:18 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_center(t_tab tab, int line)
{
	int nb_space;
	int biggersize;
	int l;
	int len;

	biggersize = 0;
	l = 0;
	while (tab[l])
	{
		len = ft_strlen(tab[l]);
		if (len > biggersize)
			biggersize = len;
		l++;
	}
	nb_space = (biggersize - ft_strlen(tab[line]));
	while (nb_space-- > 0)
		ft_putchar(' ');
}

void		ft_show_tab(t_tab tab, int mark, char c, int center)
{
	unsigned int line;
	unsigned int col;

	line = 0;
	while (tab && tab[line] != NULL)
	{
		if (mark >= 0 && mark != (int)line)
			ft_putstr("  ");
		else if (mark == (int)line)
			ft_putstr("\033[35m->\033[0m");
		col = 0;
		if (center == 1)
			ft_center(tab, line);
		while (tab[line][col] != '\0')
		{
			if (c)
				ft_putchar(c);
			ft_putchar(tab[line][col++]);
			if (c)
				ft_putchar(c);
		}
		ft_putchar('\n');
		line++;
	}
}
