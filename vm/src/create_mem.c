/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:29:21 by dmathe            #+#    #+#             */
/*   Updated: 2017/02/15 19:52:48 by amaitre          ###   ########.fr       */
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

void		fill_map(t_cwdata *data)
{
	t_list		*tmp;
	t_header	*champ;
	int			champ_field;
	int			index;
	int			i;

	tmp = data->beginlist;
	index = (data->nb_champion == 3) ? MEM_SIZE - 1 : MEM_SIZE;
	i = 0;
	champ_field = MEM_SIZE / data->nb_champion;
	while (tmp)
	{
		index -= champ_field;
		champ = (t_header*)tmp->content;
		data->begin_champ[i] = index;
		write_in_int(data, champ->prog, index, champ->prog_size);
		tmp = tmp->next;
		i++;
	}
}

static void	print_map2(t_cwdata *data)
{
	unsigned int	k;
	int				i;
	t_list			*tmp;
	t_header		*champ;

	tmp = data->beginlist;
	k = 0;
	ft_termcaps_poscurs(3, 4);
	while (tmp)
	{
		i = -1;
		champ = (t_header*)tmp->content;
		while (++i <= (int)champ->prog_size)
		{
			ft_termcaps_poscurs((i + data->begin_champ[k]) / NB_OCT_LINE + 3,
				((i + data->begin_champ[k]) % NB_OCT_LINE) * 3 + 4);
			ft_printf("{%s}%.2X ", right_color(data, champ->id), (data->hide) ?
			255 : data->mem[(i + data->begin_champ[k])]);
		}
		tmp = tmp->next;
		k++;
	}
	ft_printf("{eoc}");
}

void		print_map(t_cwdata *data)
{
	unsigned int	k;
	int				i;
	int				j;

	k = 3;
	i = -1;
	while (++i < MEM_SIZE / NB_OCT_LINE)
	{
		j = -1;
		ft_termcaps_poscurs(k++, 4);
		while (++j < NB_OCT_LINE)
			ft_printf("{lblack}%.2X {eoc}", (data->hide) ? 255 : 0);
	}
	print_map2(data);
}
