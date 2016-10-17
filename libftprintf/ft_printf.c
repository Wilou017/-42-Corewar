/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:41:56 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/12 12:21:16 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	pf_specifier(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == 'l' || s[i] == 'h' ||
	s[i] == 'z' || s[i] == 'j' || s[i] == '.' || s[i] == '#' || s[i] == '+' ||
	s[i] == '-' || s[i] == ' ' || s[i] == '*' || s[i] == 'L'))
		i++;
	return (i + 1);
}

void	pf_setting(char **setting, char const *s, int i)
{
	int	size;

	size = pf_specifier(&s[i + 1]);
	*setting = ft_strnew(size);
	ft_strncpy(*setting, &s[i + 1], size);
}

void	pf_fill(char const *s, va_list ap, t_ret *retval, t_pf_data *data)
{
	data->i = 0;
	data->adjusting = 0;
	retval->posbs = ft_inttabnew(ft_countchar(s, '%'));
	while (s[data->i] != '\0')
	{
		if (s[data->i] == '%')
		{
			pf_setting(&((*data).setting), s, data->i);
			if (data->setting[0] != '\0' && pf_initdata(data, ap))
				pf_select(data, ap, retval);
			else if (data->setting[0] == '\0')
				free((*data).setting);
		}
		else
			retval->finalstr = ft_strjoin(retval->finalstr, \
				ft_chartostr(s[data->i], 1), 3);
		data->i++;
	}
}

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
