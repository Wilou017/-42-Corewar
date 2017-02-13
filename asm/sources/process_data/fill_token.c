/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:58:22 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 14:58:24 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static t_op_token	*init_token(t_op_token *new, int index,
	char *opcode, t_asm_data *data)
{
	t_optab_info	*tmp;

	tmp = data->info_op;
	while (tmp && ft_strequ(opcode, tmp->name) != 1)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	new = (t_op_token *)malloc(sizeof(t_op_token));
	new->arg = NULL;
	new->index = index;
	new->size = 1;
	if (tmp)
		new->opcode = tmp->opcode;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void			add_token(t_asm_data *data, t_op_token *new)
{
	t_op_token		*tmp;

	tmp = NULL;
	if (data->token)
	{
		tmp = data->token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		data->token = new;
}

static void			fill_token_ext(t_asm_data *data, char **tmp, int i)
{
	t_op_token		*new;
	int				j;

	new = NULL;
	new = init_token(new, find_index(data), tmp[i], data);
	j = -1;
	if (new)
	{
		new->arg = (char **)malloc(sizeof(char *) * tab_len(tmp));
		while (tmp && tmp[++i])
			(new->arg)[++j] = ft_strdup(tmp[i]);
		(new->arg)[++j] = NULL;
		new->nbr_args = tab_len(new->arg);
		add_token(data, new);
	}
}

static void			set_label_index(t_asm_data *data, char *buff)
{
	t_label			*tmp;
	char			*label_name;

	tmp = data->label;
	label_name = ft_strsub(buff, 0, ft_strlen(buff) - 1);
	while (ft_strequ(tmp->name, label_name) != 1)
		tmp = tmp->next;
	tmp->index = find_index(data);
	ft_memdel((void **)&label_name);
}

void				fill_token(t_asm_data *data, char *buff)
{
	char			**tmp;
	char			*str;
	int				i;

	tmp = ft_strsplit(buff, ' ');
	i = 0;
	str = ft_strdup(tmp[i]);
	if (str && is_label(str))
	{
		set_label_index(data, str);
		i++;
	}
	if (tmp && tmp[i])
		fill_token_ext(data, tmp, i);
	ft_memdel((void **)&str);
	tab_delete(&tmp);
}
