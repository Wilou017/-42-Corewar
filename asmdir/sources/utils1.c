/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:56:11 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 15:56:12 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			find_label(t_label *label, char *str)
{
	t_label *tmp;
	char	*tmp1;

	tmp = label;
	tmp1 = NULL;
	if (str[ft_strlen(str) - 1] != ':')
		return (0);
	else
		tmp1 = ft_strsub(str, 0, ft_strlen(str) - 1);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, tmp1))
		{
			ft_strdel(&tmp1);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			ind_label(char *str, t_label *label)
{
	char	*tmp;
	int		i;
	int		j;
	t_label	*data;

	j = 0;
	i = 2;
	data = label;
	tmp = ft_strsub(str, 2, ft_strlen(str) - 2);
	while (data)
	{
		if (ft_strequ(tmp, data->name))
		{
			ft_memdel((void **)&tmp);
			return (1);
		}
		data = data->next;
	}
	ft_memdel((void **)&tmp);
	return (0);
}

int			dir_value(char *str)
{
	int		i;

	i = 1;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int			is_label(char *str)
{
	if (str && (str[0] == '%' && str[1] == ':'))
		return (1);
	else if (str && str[ft_strlen(str) - 1] == ':')
		return (1);
	else
		return (0);
}
