/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:39:48 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/05 20:10:42 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int ifre)
{
	char	*result;

	if (s1 && s2)
	{
		result = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (result)
		{
			ft_strcpy(result, s1);
			ft_strcat(result, s2);
		}
		else
			result = NULL;
	}
	else
		result = NULL;
	if (ifre == 1 || ifre == 3)
		ft_strdel((char **)&s1);
	if (ifre == 2 || ifre == 3)
		ft_strdel((char **)&s2);
	return (result);
}
