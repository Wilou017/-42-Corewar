/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:29:21 by dmathe            #+#    #+#             */
/*   Updated: 2016/11/16 15:29:23 by dmathe           ###   ########.fr       */
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
		data->begin_champ2 = (MEM_SIZE / 2);
	else if (data->nb_champion == 3)
	{
		data->begin_champ2 = (MEM_SIZE / 3);
		data->begin_champ3 = (MEM_SIZE / 3 * 2);
	}
	else if (data->nb_champion == 4)
	{
		data->begin_champ2 = (MEM_SIZE / 4);
		data->begin_champ3 = (MEM_SIZE / 2);
		data->begin_champ4 = (MEM_SIZE / 4 * 3);
	}
}

void		fill_map(t_cwdata *data)
{
	int i;
	t_list *tmp;

	tmp = data->beginlist;
	i = 1;
	fill_len_champ(data);
	while (tmp)
	{
		if (i == 1)
			write_in_int(data, ((t_header2*)tmp->content)->prog, 0, ((t_header2*)tmp->content)->prog_size);
		else if (i == 2)
			write_in_int(data, ((t_header2*)tmp->content)->prog, data->begin_champ2, ((t_header2*)tmp->content)->prog_size);
		else if (i == 3)
			write_in_int(data, ((t_header2*)tmp->content)->prog, data->begin_champ3, ((t_header2*)tmp->content)->prog_size);
		else if (i == 4)
			write_in_int(data, ((t_header2*)tmp->content)->prog, data->begin_champ4, ((t_header2*)tmp->content)->prog_size);
		tmp = tmp->next;
		i++;
	}
}

void		fill_map_zero(t_cwdata *data)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (data->mem[i] == -1)
			data->mem[i] = 0;
		i++;
	}
}

unsigned int			begin_champ(t_cwdata *data, int x)
{
	if (x == 1)
		return (0);
	if (x == 2)
		return (data->begin_champ2);
	if (x == 3)
		return (data->begin_champ3);
	if (x == 4)
		return (data->begin_champ4);
	return (-1);
}

void		create_map(t_cwdata *data)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		x;
	t_list	*tmp;

	tmp = data->beginlist;
	i = 0;
	j = 0;
	x = 1;
	fill_map(data);
	fill_map_zero(data);
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0 && i)
			ft_printf("\n");
		//ft_printf("\nj = %d, size = %d, i = %d, begin = %d\n", j, ((t_header2 *)tmp->content)->prog_size, i, begin_champ(data, x));
		if (j < ((t_header2 *)tmp->content)->prog_size && i >= begin_champ(data, x))
		{
			ft_printf("{red}%.2X{eoc}", data->mem[i]);
			j++;
		}
		else if (j == ((t_header2 *)tmp->content)->prog_size && tmp->next)
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
