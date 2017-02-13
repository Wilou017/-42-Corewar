/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:20:41 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:20:43 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static t_label			*label_init(void *data)
{
	t_label *new_link;

	new_link = (t_label *)malloc(sizeof(t_label));
	if (new_link == NULL)
		return (NULL);
	new_link->name = (char *)ft_strdup(data);
	new_link->index = 0;
	new_link->next = NULL;
	new_link->prev = NULL;
	return (new_link);
}

static void				label_add_next(t_label **data, t_label *link)
{
	t_label *tmp;

	tmp = *data;
	if (link)
	{
		if (!tmp)
			(*data) = link;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = link;
			link->prev = tmp;
			link->next = NULL;
		}
	}
}

static int				check_label_chars(char *str)
{
	int					i;

	i = 0;
	while (str && str[i + 1])
	{
		if (ft_islower(str[i]) || ft_isdigit(str[i]) || str[i] == '_')
			i++;
		else
			return (0);
	}
	return (1);
}

static int				fill_label(char *str, t_asm_data *data)
{
	int			i;
	char		*tmp;

	i = -1;
	tmp = ft_strdup(str);
	if (tmp && ft_strchr(tmp, LABEL_CHAR) != NULL)
	{
		if (tmp[ft_strlen(tmp) - 1] != LABEL_CHAR)
			return (0);
		if (!check_label_chars(tmp))
			return (0);
		tmp[ft_strlen(tmp) - 1] = '\0';
		label_add_next(&(data->label), label_init((void *)tmp));
	}
	ft_memdel((void **)&tmp);
	return (1);
}

int						parse_label(t_asm_data *data, char *buf)
{
	char				**tab;

	tab = NULL;
	if (!is_comment(buf) && !is_name(buf))
	{
		tab = ft_strsplit(buf, ' ');
		if (!fill_label(tab[0], data))
		{
			tab_delete(&tab);
			return (0);
		}
		tab_delete(&tab);
	}
	return (1);
}
