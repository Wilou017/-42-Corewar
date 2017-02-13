/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coltostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:41:43 by fsimmet           #+#    #+#             */
/*   Updated: 2015/12/12 17:59:23 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_coltostr(char **grille, size_t c)
{
	char	*str;
	size_t	l;

	l = 0;
	str = ft_strnew(4);
	while (grille[l])
	{
		str[l] = grille[l][c];
		l++;
	}
	return (str);
}
