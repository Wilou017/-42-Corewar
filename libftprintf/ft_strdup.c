/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:23:53 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/06 16:35:09 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *s2;

	if (!s)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s));
	ft_strcpy(s2, s);
	return (s2);
}
