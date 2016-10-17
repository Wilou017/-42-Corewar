/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:11:45 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/02 17:55:03 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	c1;
	int		i;

	i = ft_strlen(s);
	c1 = (char)c;
	s1 = (char*)s;
	while (i >= 0 && s1[i] != c1)
		i--;
	if (i < 0)
		return (0);
	else
		return (&s1[i]);
}
