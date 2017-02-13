/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:20:15 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:20:16 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				is_comment(char *buff)
{
	char		*tmp;
	int			bol;

	tmp = NULL;
	bol = 0;
	if (ft_strlen(buff) > 8)
	{
		tmp = ft_strsub(buff, 0, 8);
		if (ft_strequ(tmp, COMMENT_CMD_STRING))
			bol = 1;
		ft_memdel((void **)&tmp);
	}
	return (bol);
}
