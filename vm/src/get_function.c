/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:24:41 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/21 18:12:32 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				cw_get_option(t_cwdata *data, int *i)
{
	cw_lastoption(data, *i);
	if (data->lastoption && data->c > *i)
	{
		if ((data->lastoption == N || data->lastoption == DUMP
			|| data->lastoption == R || data->lastoption == W)
			&& !ft_strisdigit(data->v[(*i) + 1]))
			return (ft_printf("{red}%s doit être un nomdre\n", data->v[*i]));
		if (data->lastoption == DUMP && data->show_vm == 0
			&& data->verbose == 0)
			data->dumpcycles = ft_atoi(data->v[(*i) + 1]);
		else if (data->lastoption == R)
			data->slow = ft_atoi(data->v[(*i) + 1]);
		else if (data->lastoption == W)
			data->slow_time = ft_atoi(data->v[(*i) + 1]);
		else if (data->lastoption == N)
			data->lastdata = ft_strdup(data->v[(*i) + 1]);
		data->hide = (data->lastoption == H) ? 1 : 0;
		data->boost = (data->lastoption == B) ? 1 : 0;
		if (data->lastoption != VM && data->lastoption != V
			&& data->lastoption != B && data->lastoption != H)
			*i = (*i) + 1;
	}
	else if (data->lastoption == 0)
		return (ft_printf("{red}l'option %s n'est pas valide\n", data->v[*i]));
	return (0);
}

static int		distrib_data(t_reedstruct *reed, t_header *champion)
{
	if (reed->status == 0)
	{
		champion->magic = reed->buf;
		reed->status += 3;
		return ((champion->magic == COREWAR_EXEC_MAGIC) ? 1 : 0);
	}
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic))
		return (cw_distrib_name(reed, champion));
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic) + 4)
		return (cw_distrib_padding(reed, -1));
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic) + 8)
		return (cw_distrib_progsize(reed));
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic) + 8
		+ COMMENT_LENGTH)
		return (cw_distrib_comment(reed, champion));
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic) + 8
		+ COMMENT_LENGTH + 4)
		return (cw_distrib_padding(reed, -3));
	return (cw_distrib_program(reed, champion));
}

static int		get_error(t_reedstruct reed, char *name)
{
	if (reed.reedsize == 0)
		return (ft_printf("{red}Magic invalide\n"));
	else if (reed.reedsize == -1)
		return (ft_printf("{red}%s -> Nom trop long | taille max = %d\n",
		name, PROG_NAME_LENGTH));
	else if (reed.reedsize == -2)
		return (ft_printf("{red}%s -> Progsize = 0\n", name));
	else if (reed.reedsize == -3)
		return (ft_printf("{red}%s -> Commentaire trop (%d) long | \
taille max = %d\n", name, reed.buf, COMMENT_LENGTH));
	else if (reed.reedsize == -5)
		return (ft_printf("{red}%s -> Champion trop long (%d) | \
taille max = %d\n", name, reed.buf, CHAMP_MAX_SIZE));
	else if (reed.reedsize == -4)
		return (ft_printf("{red}%s -> Premier octet a 0\n", name));
	return (0);
}

static int		reed_champion(char *name, t_header *champion)
{
	t_reedstruct	reed;
	int				boolean;

	reed.fd = open(name, O_RDONLY);
	reed.status = 0;
	reed.reedsize = sizeof(int);
	boolean = 0;
	while ((reed.ret = read(reed.fd, &reed.buf, reed.reedsize)))
	{
		if (reed.ret < 0)
			return (ft_printf("{red}Champion invalide\n"));
		reed.buf = return_bytes(reed.buf, reed.ret);
		reed.reedsize = distrib_data(&reed, champion);
		if (get_error(reed, name))
			return (1);
		reed.buf = 0;
		reed.status++;
		boolean = 1;
	}
	if (!boolean || !ft_strlen(champion->prog_name) ||
		!ft_strlen(champion->comment))
		return (ft_printf("{red}Champion invalide\n"));
	return (cw_norme1(reed, champion));
}

int				cw_get_champion(t_cwdata *data, int i)
{
	t_header	*champion;

	data->nb_champion++;
	data->init = 1;
	if (!(champion = cw_add_champ_to_lst(data)))
		return (ft_printf("{red}Error\n"));
	data->init = 0;
	ft_strdel(&data->lastdata);
	if (ft_strlen(data->v[i]) < 5 ||
		ft_strcmp(&data->v[i][ft_strlen(data->v[i]) - 4], ".cor"))
		return (ft_printf("{red}les champions doivent etre des .cor\n"));
	if (reed_champion(data->v[i], champion))
		return (1);
	return (0);
}
