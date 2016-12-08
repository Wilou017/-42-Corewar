/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:24:41 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/25 16:00:43 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				cw_get_new_loca(t_cwdata *data, int loca)
{
	int	param;
	int	tmp_param1;
	int	tmp_param2;
	int	new_loca;

	param = 0;
	if (data->mem[(loca + 1) % MEM_SIZE] > 0x7F)
	{
		tmp_param1 = 0xFF - data->mem[loca + 1];
		tmp_param2 = 0xFF - data->mem[loca + 2];
		param = ((tmp_param1 << 8) + tmp_param2) + 1;
		new_loca = loca - param;
		new_loca = (new_loca < 0) ? new_loca + MEM_SIZE : new_loca;
	}
	else
	{
		param = (data->mem[(loca + 1) % MEM_SIZE] << 8) + data->mem[(loca + 2) % MEM_SIZE];
		new_loca = (loca + param) % MEM_SIZE;
	}
	return (new_loca);
}

int				cw_get_option(t_cwdata *data, int *i)
{
	cw_lastoption(data, *i);
	if (data->lastoption && data->c > *i)
	{
		if ((data->lastoption == N || data->lastoption == DUMP)
			&& !ft_strisdigit(data->v[(*i) + 1]))
			return (ft_printf("{red}%s doit être un nomdre\n", data->v[*i]));
		if (data->lastoption == DUMP)
			data->dumpcycles = ft_atoi(data->v[(*i) + 1]);
		else if (data->lastoption == N)
			data->lastdata = ft_strdup(data->v[(*i) + 1]);
		if (data->lastoption != VM && data->lastoption != V)
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
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic) + 4 + 4)
		return (cw_distrib_progsize(reed));
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic) + 4 + 4 + COMMENT_LENGTH)
		return (cw_distrib_comment(reed, champion));
	else if (reed->status < PROG_NAME_LENGTH + (int)sizeof(champion->magic) + 8 + COMMENT_LENGTH + 4)
		return (cw_distrib_padding(reed, -3));
	return (cw_distrib_program(reed, champion));
}

static int		reed_champion(char *name, t_header *champion)
{
	t_reedstruct reed;

	reed.fd = open(name, O_RDONLY);
	reed.status = 0;
	reed.reedsize = sizeof(int);
	while ((reed.ret = read(reed.fd, &reed.buf, reed.reedsize)))
	{
		if (reed.ret < 0)
			return (ft_printf("{red}Champion invalide\n"));
		reed.buf = return_bytes(reed.buf, reed.ret);
		reed.reedsize = distrib_data(&reed, champion);
		if (reed.reedsize == 0)
			return (ft_printf("{red}Magic invalide\n"));
		else if (reed.reedsize == -1)
			return (ft_printf("{red}%s -> Nom trop long | taille max = %d\n", name, PROG_NAME_LENGTH));
		else if (reed.reedsize == -2)
			return (ft_printf("{red}%s -> Progsize = 0\n",  name));
		else if (reed.reedsize == -3)
			return (ft_printf("{red}%s -> Commentaire trop long | taille max = %d\n", name, COMMENT_LENGTH));
		else if (reed.reedsize == -4)
			return (ft_printf("{red}%s -> Premier octet du programme a 0\n", name));
		reed.buf = 0;
		reed.status++;
	}
	return (cw_norme1(reed, champion));
}

int				cw_get_champion(t_cwdata *data, int i)
{
	t_header	*champion;

	data->nb_champion++;
	champion = cw_add_champ_to_lst(data);

	//ft_printf("\nid -> %d\n", champion->id);
	ft_strdel(&data->lastdata);

	if (ft_strlen(data->v[i]) < 5 ||
		ft_strcmp(&data->v[i][ft_strlen(data->v[i]) - 4], ".cor"))
		return (ft_printf("{red}les champions doivent etre des fichier .cor\n"));

	//ft_printf("Champion -> %s\n", data->v[i]);

	if (reed_champion(data->v[i], champion))
		return (1);
	return (0);
}
