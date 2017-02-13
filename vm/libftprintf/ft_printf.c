/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:41:56 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/21 15:55:27 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putstrerror(t_ret *retval)
{
	int pos;
	int j;

	j = 0;
	pos = 0;
	while (retval->finalstr[j])
	{
		if (retval->posbs[pos] == j)
		{
			pos++;
			ft_putchar('\0');
		}
		else
			ft_putchar(retval->finalstr[j]);
		j++;
	}
	retval->return_val = ft_strlen(retval->finalstr);
}

int		ft_printf(char const *s, ...)
{
	va_list		ap;
	t_pf_data	data;
	t_ret		retval;

	if (!s)
		return (0);
	retval.finalstr = ft_strnew(pf_specifier(s));
	data.ox = NULL;
	va_start(ap, s);
	pf_fill(s, ap, &retval, &data);
	va_end(ap);
	pf_color(&(retval.finalstr));
	if (retval.posbs[0] > -1)
		ft_putstrerror(&retval);
	else
		retval.return_val = ft_putstr(retval.finalstr);
	ft_strdel(&retval.finalstr);
	free(retval.posbs);
	return (retval.return_val);
}
