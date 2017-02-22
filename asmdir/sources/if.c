/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:20:53 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:20:55 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			if_dir(char *s, t_label *label, int last_arg)
{
	if (s[ft_strlen(s) - 1] == ',')
	{
		if (last_arg)
			return (0);
		s[ft_strlen(s) - 1] = '\0';
	}
	if (s[0] == DIRECT_CHAR)
	{
		if (s[1] == LABEL_CHAR)
		{
			if (!ind_label(s, label))
				return (0);
		}
		else if (s[1] == '\0')
			return (0);
		else if (!dir_value(s))
			return (0);
		return (1);
	}
	return (0);
}

int			if_ind(char *s, t_label *label, int last_arg)
{
	int		i;

	i = 0;
	if (s[ft_strlen(s) - 1] == ',')
	{
		if (last_arg)
			return (0);
		s[ft_strlen(s) - 1] = '\0';
	}
	if (s[0] == LABEL_CHAR)
		if (!ind_label(s, label))
			return (0);
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int			if_reg(char *s, int last_arg)
{
	int		x;
	char	*str;

	last_arg = 0;
	if (!s || ((x = ft_strlen(s)) > 3 || x < 2))
		return (0);
	str = ft_strdup(s);
	if (str[0] != 'r')
	{
		ft_memdel((void **)&str);
		return (0);
	}
	str[0] = ' ';
	x = ft_atoi(str);
	ft_memdel((void **)&str);
	if (x >= 1 && x <= REG_NUMBER)
		return (1);
	else
		return (0);
}
