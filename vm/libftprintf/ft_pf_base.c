/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:52:51 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/21 15:57:30 by amaitre          ###   ########.fr       */
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
	retval->posbs = ft_inttabnew(ft_countchar(s, '%'), -1);
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
