/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:11:23 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:59:38 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strchr(const char *s, int c)
{
	char	comp;
	int		i;

	comp = c;
	i = 0;
	if (comp == '\0')
	{
		while (s[i] != comp)
			i++;
	}
	while (s[i] != comp && s[i] != '\0')
		i++;
	if (s[i] == comp)
		return (char *)(&s[i]);
	else
		return (NULL);
}
