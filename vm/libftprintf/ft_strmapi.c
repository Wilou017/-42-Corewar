/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:26:34 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/01 17:38:00 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = NULL;
	if (s && f)
	{
		s2 = ft_strdup(s);
		while (s[i])
		{
			s2[i] = f(i, (char)s[i]);
			i++;
		}
	}
	return (s2);
}
