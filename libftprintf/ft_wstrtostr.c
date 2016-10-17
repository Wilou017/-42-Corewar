/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:58:11 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/05 21:31:08 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrtostr(wchar_t *str)
{
	char	*result;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	result = ft_strnew(0);
	while (str[i])
		result = ft_strjoin(result, ft_wchrtostr(str[i++]), 3);
	return (result);
}
