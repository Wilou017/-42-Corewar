/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:03:09 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 14:03:11 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static char			*get_comment_name(char *buff)
{
	int				len;
	int				i;
	int				j;

	len = 0;
	i = 0;
	j = ft_strlen(buff) - 1;
	while (buff && buff[i] && buff[i] != '\"')
		i++;
	while (buff && buff[j] && buff[j] != '\"')
		j--;
	len = j - i - 1;
	return (ft_strsub(buff, i + 1, len));
}

int					fill_header(t_asm_data *data, char *buffer)
{
	if (is_name(buffer))
	{
		data->name = get_comment_name(buffer);
		return ((ft_strlen(data->name) > PROG_NAME_LENGTH) ? 0 : 1);
	}
	else
	{
		data->comment_name = get_comment_name(buffer);
		return ((ft_strlen(data->comment_name) > COMMENT_LENGTH) ? 0 : 1);
	}
}
