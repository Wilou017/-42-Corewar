/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:24:41 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/09 22:45:35 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				cw_get_option(t_cwdata *data, int *i)
{
	cw_lastoption(data, *i);
	if (data->lastoption && data->c > *i)
	{
		if (!ft_strisdigit(data->v[(*i) + 1]))
			return (ft_printf("{red}%s doit être un nomdre\n", data->v[*i]));
		if (data->lastoption == DUMP)
			data->dumpcycles = ft_atoi(data->v[(*i) + 1]);
		else
			data->lastdata = ft_strdup(data->v[(*i) + 1]);
		*i = (*i) + 1;
	}
	else if (data->lastoption == 0)
		return (ft_printf("{red}l'option %s n'est pas valide\n", data->v[*i]));
	return (0);
}

static int		distrib_data(t_reedstruct *reed, t_header2 *champion)
{
	if (reed->status == 0)
		champion->magic = reed->buf;
	else if (reed->status <= PROG_NAME_LENGTH / 4)
		champion->prog_name = ft_strjoin(champion->prog_name, ft_inttostr(reed->buf), 3);
	else if (reed->status <= PROG_NAME_LENGTH / 4 + 1)
		ft_printf("%d Padding -> %.8X\n", reed->status, reed->buf);
	else if (reed->status <= PROG_NAME_LENGTH / 4 + 2)
	{
		ft_printf("%d Progsize ? -> %.8X\n", reed->status, reed->buf);
		reed->inst_tab = ft_inttabnew(reed->buf);
		reed->inst_size = reed->buf;
		reed->inst_index = 0;
	}
	else if (reed->status <= PROG_NAME_LENGTH / 4 + 2 + COMMENT_LENGTH / 4)
		champion->comment = ft_strjoin(champion->comment, ft_inttostr(reed->buf), 3);
	else if (reed->status == PROG_NAME_LENGTH / 4 + 2 + COMMENT_LENGTH / 4 + 1)
	{
		ft_printf("%d Padding -> %.8X\n", reed->status, reed->buf);
		return (1);
	}
	else
	{
		reed->inst_tab[reed->inst_index] = reed->buf;
		reed->inst_index++;
		ft_printf("%d Programme-> {lred}%.2X{eoc} -> {lblue}%.2b{eoc}\n", reed->status, reed->buf, reed->buf);
		return (1);
	}
	return (sizeof(int));
}

static int		reed_champion(char *name, t_header2 *champion)
{
	t_reedstruct reed;

	reed.fd = open(name, O_RDONLY);
	reed.status = 0;
	reed.reedsize = sizeof(int);
	ft_printf("\n\n------------------------------------\n\n");
	while ((reed.ret = read(reed.fd, &reed.buf, reed.reedsize)))
	{
		if (reed.ret < 0)
			return (ft_printf("{red}Champion invalide\n"));
		reed.buf = return_bytes(reed.buf, reed.ret);
		reed.reedsize = distrib_data(&reed, champion);
		reed.buf = 0;
		reed.status++;
	}
	if (champion->magic != 0xea83f3)
		return (ft_printf("{red}Magic invalide\n"));


	ft_printf("\n\nNom     = %s\n", champion->prog_name);
	ft_printf("Comment = %s\n", champion->comment);

	// ft_showtabint(reed.inst_tab, reed.inst_size, "inst_tab", 0); // Affiche le tableau du programme en int decimal

	// cw_createnode(champion, reed.inst_tab, reed.inst_size); // emvoye le tableau a la fonction de paring de dave

	return (0);
}

int				cw_get_champion(t_cwdata *data, int i)
{
	t_header2	*champion;

	data->nb_champion++;
	champion = cw_add_champ_to_lst(data);
	champion->id = (data->lastdata) ? ft_atoi(data->lastdata) :\
	data->nb_champion * -1;
	champion->inst.start = NULL;
	champion->inst.end = NULL;

	ft_printf("\nid -> %d\n", champion->id);
	ft_strdel(&data->lastdata);

	if (ft_strlen(data->v[i]) < 5 ||
		ft_strcmp(&data->v[i][ft_strlen(data->v[i]) - 4], ".cor"))
		return (ft_printf("{red}les champions doivent etre des fichier .cor\n"));

	ft_printf("Champion -> %s\n", data->v[i]);

	if (reed_champion(data->v[i], champion))
		return (1);
	return (0);
}
