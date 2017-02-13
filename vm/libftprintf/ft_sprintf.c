/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:54:07 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/21 15:57:11 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_printf.h>

void	ft_trasstrerror(t_ret *retval)
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
			retval->finalstr[j] = '\0';
		}
		j++;
	}
	retval->return_val = ft_strlen(retval->finalstr);
}

char	*ft_sprintf(char const *s, ...)
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
		ft_trasstrerror(&retval);
	free(retval.posbs);
	return (retval.finalstr);
}
