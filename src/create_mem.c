/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:29:21 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/19 17:46:56 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			write_in_int(t_cwdata *data, int *src, int len, int size)
{
	int		i;

	i = 0;
	if (!src)
		return (0);
	while (i < size)
	{
		data->mem[len] = src[i];
		len++;
		i++;
	}
	return (1);
}

void		fill_len_champ(t_cwdata *data)
{
	if (data->nb_champion == 2)
		data->begin_champ[0] = (MEM_SIZE / 2);
	else if (data->nb_champion == 3)
	{
		data->begin_champ[0] = (MEM_SIZE / 3);
		data->begin_champ[1] = (MEM_SIZE / 3 * 2);
	}
	else if (data->nb_champion == 4)
	{
		data->begin_champ[0] = (MEM_SIZE / 4);
		data->begin_champ[1] = (MEM_SIZE / 2);
		data->begin_champ[2] = (MEM_SIZE / 4 * 3);
	}
}

void		fill_map(t_cwdata *data)
{
	int i;
	t_list		*tmp;
	t_header	*champ;

	tmp = data->beginlist;
	i = 1;
	fill_len_champ(data);
	while (tmp)
	{
		champ = (t_header*)tmp->content;
		if (i == 1)
			write_in_int(data, champ->prog, 0, champ->prog_size);
		else if (i == 2)
			write_in_int(data, champ->prog, data->begin_champ[0], champ->prog_size);
		else if (i == 3)
			write_in_int(data, champ->prog, data->begin_champ[1], champ->prog_size);
		else if (i == 4)
			write_in_int(data, champ->prog, data->begin_champ[2], champ->prog_size);
		tmp = tmp->next;
		i++;
	}
}

unsigned int			begin_champ(t_cwdata *data, int x)
{
	if (x == 1)
		return (0);
	if (x == 2)
		return (data->begin_champ[0]);
	if (x == 3)
		return (data->begin_champ[1]);
	if (x == 4)
		return (data->begin_champ[2]);
	return (-1);
}

void		print_map(t_cwdata *data)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		x;
	t_list	*tmp;

	tmp = data->beginlist;
	i = 0;
	j = 0;
	x = 1;
	while (i < MEM_SIZE)
	{
		if (i % NB_OCT_LINE == 0 && i)
			ft_printf("\n");
		if (j < ((t_header *)tmp->content)->prog_size && i >= begin_champ(data, x))
		{
			ft_printf("{%s}%.2X{eoc}", data->color[x], data->mem[i]);
			j++;
		}
		else if (j == ((t_header *)tmp->content)->prog_size && tmp->next)
		{
			ft_printf("%.2X", data->mem[i]);
			tmp = tmp->next;
			j = 0;
			x++;
		}
		else if (i != begin_champ(data, x))
			ft_printf("%.2X", data->mem[i]);
		if (i != MEM_SIZE - 1)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

void		create_map(t_cwdata *data)
{
	fill_map(data);
	cw_loop(data);
}
