/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:20:08 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:20:10 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		epur_check_char(char c)
{
	return ((c != ' ' && c != ',' && c != '\t') ? 1 : 0);
}

static char		*epur_buff(char *str)
{
	char	*output;
	int		i;
	int		j;

	output = ft_strnew(ft_strlen(str) + 100);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (str[i] == ';' || str[i] == '#')
			str[i] = '\0';
		else if (str[i] == ' ' || str[i] == ',' || str[i] == '\t')
			i += 1;
		else
		{
			while (str && str[i] && epur_check_char(str[i]))
				output[j++] = str[i++];
			output[j++] = ' ';
		}
	}
	output[j] = '\0';
	ft_memdel((void **)&str);
	return (output);
}

static void		add_buff(t_asm_data *asm_data, char *buff, int *i)
{
	if (!buff || !buff[0] || buff[0] == '\n' || buff[0] == '\0' ||
		buff[0] == '#' || buff[0] == ';')
		return ;
	else
		(asm_data->file)[(*i)++] = ft_strdup(buff);
}

int				read_clean(t_asm_data *asm_data, char *arg)
{
	int			fd;
	int			ret;
	char		*buff;
	int			i;

	fd = open(arg, O_RDONLY);
	ret = 0;
	buff = NULL;
	i = 0;
	asm_data->file = (char **)malloc(sizeof(char *) * 10000);
	while ((ret = get_next_line(fd, &buff)) == 1)
	{
		if (!is_comment(buff) && !is_name(buff))
			buff = epur_buff(buff);
		add_buff(asm_data, buff, &i);
		ft_memdel((void **)&buff);
	}
	(asm_data->file)[i] = NULL;
	return ((ret == -1) ? ret : 0);
}
