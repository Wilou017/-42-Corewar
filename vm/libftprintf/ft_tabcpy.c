/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:10:12 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/15 15:20:15 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <newlibft.h>

t_tab	ft_tabcpy(t_tab tab)
{
	t_tab	cpytab;
	size_t	size;
	size_t	l;

	size = ft_tablen(tab, 0);
	l = 0;
	cpytab = (t_tab)malloc(sizeof(char *) * (size + 1));
	if (!cpytab)
		return (NULL);
	cpytab[size] = NULL;
	while (l < size)
	{
		cpytab[l] = ft_strdup(tab[l]);
		l++;
	}
	return (cpytab);
}
