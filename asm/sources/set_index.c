/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:40:43 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 14:40:44 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		label_position(t_asm_data *data, t_op_token *token, char *label)
{
	t_label		*lab;

	lab = data->label;
	while (ft_strequ(lab->name, label) != 1)
		lab = lab->next;
	return ((lab->index > token->index) ? 1 : 0);
}

static int		search_label_index(t_asm_data *data, char *label)
{
	int			i;
	t_label		*lab;

	i = 0;
	lab = data->label;
	while (ft_strequ(label, lab->name) != 1)
		lab = lab->next;
	return (lab->index);
}

static void		set_positiv_index(t_op_token *token, int index)
{
	t_op_token	*tmp;
	int			value;

	tmp = token;
	value = 0;
	while (tmp && tmp->index != index)
	{
		value += tmp->size;
		tmp = tmp->next;
	}
	token->label_index = value;
}

static void		set_negativ_index(t_op_token *token, int index)
{
	t_op_token	*tmp;
	int			value;

	tmp = token;
	value = 0;
	while (tmp && tmp->index != index)
	{
		tmp = tmp->prev;
		value -= tmp->size;
	}
	value += 1;
	token->label_index = value;
}

void			set_index(t_asm_data *data, t_op_token *token, char *input)
{
	char		*label;
	int			index;

	label = ft_strsub(input, 2, ft_strlen(input) - 2);
	index = search_label_index(data, label);
	if (label_position(data, token, label) == 1)
		set_positiv_index(token, index);
	else
		set_negativ_index(token, index);
	ft_memdel((void **)&label);
}
