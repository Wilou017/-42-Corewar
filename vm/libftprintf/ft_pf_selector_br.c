/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_br.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:25 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_b_selector(t_pf_data *data, va_list ap)
{
	char *a;

	if (data->precision >= 0)
	{
		a = ft_itoa(va_arg(ap, t_intmax), 2);
		if (data->precision * 4 > (int)ft_strlen(a))
			a = ft_strjoin(ft_chartostr('0', data->precision * 4 - \
				ft_strlen(a)), a, 3);
	}
	else
		a = ft_strdup("");
	return (a);
}

char	*ft_pf_r_selector(t_pf_data *data, va_list ap)
{
	char	*bimaire;
	char	*unaire;
	int		nb;

	if (data->precision >= 0)
	{
		unaire = ft_strnew(0);
		bimaire = ft_itoa(va_arg(ap, t_intmax), 2);
		while (bimaire[0] != '\0')
		{
			if (unaire[0] != '\0')
				unaire = ft_strjoin(unaire, " ", 1);
			if ((nb = ft_delcharinstr(&bimaire, '1', 1)) > 0)
				unaire = ft_strjoin(unaire, "0 ", 1);
			else if ((nb = ft_delcharinstr(&bimaire, '0', 1)) > 0)
				unaire = ft_strjoin(unaire, "00 ", 1);
			unaire = ft_strjoin(unaire, ft_chartostr('0', nb), 3);
		}
	}
	else
		unaire = ft_strdup("");
	return (unaire);
}
