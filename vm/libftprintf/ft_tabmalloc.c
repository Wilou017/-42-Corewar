/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:54:49 by fsimmet           #+#    #+#             */
/*   Updated: 2016/09/15 15:18:24 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	ft_tabmalloc(size_t cote, char i)
{
	t_tab	tab;
	size_t	l;

	tab = (t_tab)malloc(sizeof(char *) * (cote + 1));
	if (!tab)
		return (NULL);
	tab[cote] = NULL;
	l = 0;
	while (l < cote)
	{
		tab[l] = ft_strnew(cote);
		if (!tab[l])
			return (NULL);
		ft_memset(tab[l], i, cote);
		tab[l][cote] = '\0';
		l++;
	}
	return (tab);
}
