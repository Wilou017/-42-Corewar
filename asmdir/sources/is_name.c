/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:20:32 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:20:34 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				is_name(char *buff)
{
	char		*tmp;
	int			bol;

	tmp = NULL;
	bol = 0;
	if (ft_strlen(buff) > 5)
	{
		tmp = ft_strsub(buff, 0, 5);
		if (ft_strequ(tmp, NAME_CMD_STRING))
			bol = 1;
		ft_memdel((void **)&tmp);
	}
	return (bol);
}
