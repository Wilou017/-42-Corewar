/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_initdata2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:21:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/11 11:34:41 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	pf_initdata_sizefin(t_pf_data *data)
{
	char *tmp;

	data->flag.sizefin = ft_atoi(data->setting);
	if (data->flag.sizefin > 0)
	{
		tmp = data->setting;
		data->setting = ft_strsub(data->setting, ft_intlen(data->flag.sizefin),\
			LEN(data->setting) - ft_intlen(data->flag.sizefin), 0);
		ft_strdel(&tmp);
	}
}

char	*pt_delchraround(char *set, int pos, int arg)
{
	int pos2;

	pos2 = pos;
	while (--pos >= 0 && set[pos] != '.'
		&& set[pos] != '#' && set[pos] != '+'
		&& set[pos] != '-' && set[pos] != ' ')
		set[pos] = '}';
	pos = pos2;
	if (set[++pos] != '\0' && set[pos] != '.'
		&& set[pos] != '#' && set[pos] != '+'
		&& set[pos] != '-' && set[pos] != ' ' && set[pos] != '*')
		set[pos2] = (arg < 0) ? '-' : '}';
	return (ft_replace("}", "", set, 1));
}

char	*pf_transform_star(char *set, va_list ap)
{
	int nb;
	int arg;

	while (ft_strstr(set, "*"))
	{
		arg = va_arg(ap, int);
		nb = ft_nbchar(set, '*');
		set = pt_delchraround(set, nb, arg);
		if (ft_strstr(set, "*"))
			set = (arg != 0) ? ft_nreplace("*", ft_itoa(arg, 10), set, 6) :\
			ft_nreplace("*", "", set, 3);
	}
	return (set);
}

void	pf_initpreset(t_pf_data *data, va_list ap)
{
	data->size = LEN(data->setting);
	data->specifieur = data->setting[data->size - 1];
	data->setting[data->size - 1] = '\0';
	if (pf_check_specifieur(data->specifieur))
		data->invalidspe = NULL;
	else
		data->invalidspe = ft_chartostr(data->specifieur, 1);
	data->flag.signeplus = 0;
	data->flag.signemoins = 0;
	data->flag.diez = 0;
	data->flag.sizefin = 0;
	data->space = 0;
	data->precision = 0;
	data->setting = pf_transform_star(data->setting, ap);
	while (ft_strstr(data->setting, ".."))
		data->setting = ft_replace("..", ".", data->setting, 1);
}
