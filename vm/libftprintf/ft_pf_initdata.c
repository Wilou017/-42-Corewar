/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_initdata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:21:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:15 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		pf_check_specifieur(char spe)
{
	if (spe == 's' || spe == 'p' || spe == 'S' || spe == 'd' || spe == 'D'
		|| spe == 'o' || spe == 'O' || spe == 'x' || spe == 'X' || spe == 'b'
		|| spe == 'i' || spe == 'U' || spe == 'c' || spe == 'C' || spe == 'B'
		|| spe == 'j' || spe == 'z' || spe == 'l' || spe == 'h' || spe == 'r'
		|| spe == '%' || spe == 'u' || spe == 'f' || spe == 'F' || spe == ' '
		|| spe == 'n' || spe == 'e' || spe == 'E' || spe == 't' || spe == 'T'
		|| spe == 'k' || spe == 'K')
		return (1);
	return (0);
}

void	pf_initdatamodifieur(t_pf_data *data)
{
	size_t	deleted;

	data->modifieur.ll = 0;
	data->modifieur.l = 0;
	data->modifieur.j = 0;
	data->modifieur.z = 0;
	data->modifieur.hh = 0;
	data->modifieur.h = 0;
	data->modifieur.majspe = 0;
	while (ft_strstr(data->setting, "l") || ft_strstr(data->setting, "h") ||
		ft_strstr(data->setting, "j") || ft_strstr(data->setting, "z"))
	{
		if ((deleted = ft_delcharinstr(&(data->setting), 'l', 1)) > 0)
			(deleted % 2 == 1) ? (data->modifieur.l = 1) : \
		(data->modifieur.ll = 1);
		if ((deleted = ft_delcharinstr(&(data->setting), 'h', 1)) > 0)
			(deleted % 2 == 1) ? (data->modifieur.h = 1) : \
		(data->modifieur.hh = 1);
		if (ft_delcharinstr(&(data->setting), 'z', 1))
			data->modifieur.z = 1;
		if (ft_delcharinstr(&(data->setting), 'j', 1))
			data->modifieur.j = 1;
	}
}

void	pf_initprec(t_pf_data *data)
{
	char *prec;

	prec = ft_strdup(&data->setting[ft_nbchar(data->setting, '.') + 1]);
	data->precision = ft_atoi(prec);
	data->setting = ft_strsub(data->setting, 0,\
		ft_nbchar(data->setting, '.'), 1);
	if (data->precision == 0)
		data->precision = -1;
	else if (data->precision < 0)
		data->precision = 0;
	ft_strdel(&prec);
}

int		pf_initdata2(t_pf_data *data)
{
	data->flag.completchar = ' ';
	if (ft_delcharinstr(&(data->setting), '0', 1) > 0 && !data->flag.signemoins)
		data->flag.completchar = '0';
	pf_initdata_sizefin(data);
	pf_initdatamodifieur(data);
	ft_strcpy((data->ox = ft_strnew(2)), \
		(ft_isupper(data->specifieur)) ? "0X" : "0x");
	if (ft_isupper(data->specifieur))
	{
		data->modifieur.l = (data->modifieur.l ||
			data->specifieur != 'X') ? 1 : 0;
		data->specifieur = ft_tolower(data->specifieur);
		data->modifieur.majspe = 1;
	}
	(data->specifieur == 'o') ? (data->ox[1] = '\0') : 0;
	ft_strdel(&data->setting);
	return (1);
}

int		pf_initdata(t_pf_data *data, va_list ap)
{
	pf_initpreset(data, ap);
	if (ft_strchr(data->setting, '.') != 0)
		pf_initprec(data);
	if (ft_strchr(data->setting, '#') != 0 || data->specifieur == 'p')
	{
		if (data->specifieur == 'o' || data->specifieur == 'x' ||
			data->specifieur == 'p' || data->specifieur == 'O' ||
			data->specifieur == 'X')
			data->flag.diez = 1;
		data->setting = ft_replace("#", "", data->setting, 1);
	}
	if (ft_strchr(data->setting, '+') != 0)
		data->flag.signeplus = 1;
	if (ft_strchr(data->setting, ' ') != 0)
		data->space = (data->flag.signeplus) ? 0 : 1;
	else if (ft_strchr(data->setting, '-') != 0)
		data->flag.signemoins = 1;
	data->setting = ft_replace("-", "", data->setting, 1);
	data->setting = ft_replace(" ", "", data->setting, 1);
	data->setting = ft_replace("+", "", data->setting, 1);
	return (pf_initdata2(data));
}
