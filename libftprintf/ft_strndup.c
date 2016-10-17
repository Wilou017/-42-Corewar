/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:23:53 by amaitre           #+#    #+#             */
/*   Updated: 2016/03/17 12:32:25 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char *s2;

	if (!s)
		return (NULL);
	if (n < 1)
		n = ft_strlen(s);
	s2 = ft_strnew(n);
	ft_strncpy(s2, s, n);
	return (s2);
}
