/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:28:37 by amaitre           #+#    #+#             */
/*   Updated: 2017/02/08 16:37:36 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	init_data_default(t_cwdata *data)
{
	data->init = 0;
	data->last_champ_live = 0;
	data->mem = ft_inttabnew(MEM_SIZE, 0);
	data->dumpcycles = -1;
	data->nb_champion = 0;
	data->beginlist = NULL;
	data->processlist = NULL;
	data->nb_process = 0;
	data->nb_process_total = 0;
	data->lastdata = NULL;
	data->begin_champ = ft_inttabnew(4, -1);
	data->cur_cycle = 0;
	data->nb_live_per_cycle = 0;
	data->show_vm = 0;
	data->slow = -1;
	data->verbose = 0;
	data->hide = 0;
	data->cycle_to_die = CYCLE_TO_DIE;
	data->color = ft_strsplit(CHAMP_COLOR, ' ');
}

void		cw_lastoption(t_cwdata *data, int i)
{
	if (!ft_strcmp(data->v[i], "-dump") || !ft_strcmp(data->v[i], "-d"))
	{
		data->d = (!ft_strcmp(data->v[i], "-d")) ? 1 : 0;
		data->lastoption = DUMP;
	}
	else if (!ft_strcmp(data->v[i], "-n"))
		data->lastoption = N;
	else if (!ft_strcmp(data->v[i], "-r"))
		data->lastoption = R;
	else if (!ft_strcmp(data->v[i], "-v"))
	{
		if (data->show_vm == 0 && data->dumpcycles == -1)
			data->verbose = 1;
		data->lastoption = V;
	}
	else if (!ft_strcmp(data->v[i], "-h"))
		data->lastoption = H;
	else if (!ft_strcmp(data->v[i], "-vm"))
	{
		if (data->verbose == 0 && data->dumpcycles == -1)
			data->show_vm = 1;
		data->lastoption = VM;
	}
	else
		data->lastoption = ERROR;
}

void		init_inst(t_inst *inst, t_process *proc)
{
	inst->label_size = 0;
	inst->size = 0;
	inst->param = 0;
	proc->good_cicle = 0;
}
static void	cw_prit_starter(t_cwdata *data)
{
	int			i;
	t_list		*tmp;
	t_header	*champ;

	ft_printf("Introducing contestants...\n");
	tmp = data->beginlist;
	i = 1;
	while (tmp)
	{
		champ = ((t_header*)tmp->content);
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", (i++), champ->prog_size, champ->prog_name, champ->comment);
		tmp = tmp->next;
	}
}

int			cw_init(t_cwdata *data)
{
	int	i;

	init_data_default(data);
	i = 1;
	while (data->c >= i)
	{
		data->lastoption = -1;
		if (data->v[i][0] != '-' && cw_get_champion(data, i))
			return (1);
		if (data->v[i][0] == '-' && cw_get_option(data, &i))
			return (1);
		i++;
	}
	if (data->nb_champion < 1 || data->nb_champion > MAX_PLAYERS)
		return (ft_printf("{red}Nombre de champion invalide{eoc}\n"));
	cw_prit_starter(data);
	return (0);
}
