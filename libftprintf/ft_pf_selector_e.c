/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:39 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_e_selector(t_pf_data *data, va_list ap)
{
	char			*a;
	long double		nb;
	long double		nb2;
	int				i;

	nb = va_arg(ap, long double);
	i = 0;
	nb2 = nb;
	if (nb < 0)
		nb2 = -nb;
	while (nb2 / ft_pwe(10, i) > 10)
	{
		nb2 /= 10;
		i++;
	}
	a = ft_strjoin(ft_ftoa(nb2, 6), ft_strjoin(\
		(data->modifieur.majspe) ? "E+" : "e+", (i > 10) ? ft_itoa(i, 10) : \
		ft_strjoin("0", ft_itoa(i, 10), 2), 2), 3);
	return ((nb < 0) ? ft_strjoin("-", a, 2) : a);
}
