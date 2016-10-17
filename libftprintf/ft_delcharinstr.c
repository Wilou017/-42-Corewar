/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delcharinstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:32:31 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/04 17:56:59 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delcharinstr(char **alpha, char c, int start)
{
	size_t		i;
	char		*new_alpha;
	int			len;

	i = 0;
	len = ft_strlen(*alpha);
	if (start == 0)
		*alpha = ft_strrev(*alpha);
	while ((*alpha)[i] == c)
		i++;
	if (i == 0)
		return (0);
	new_alpha = ft_strnew(len - i);
	ft_strcpy(new_alpha, &(*alpha)[i]);
	ft_strdel(alpha);
	(*alpha) = new_alpha;
	return (i);
}
