/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:28:37 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/19 15:51:08 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	init_data_default(t_cwdata *data)
{
	data->mem = ft_inttabnew(MEM_SIZE, 0);
	data->dumpcycles = -1;
	data->nb_champion = 0;
	data->beginlist = NULL;
	data->lastdata = NULL;
	data->begin_champ = ft_inttabnew(3, 0);
}

void		cw_lastoption(t_cwdata *data, int i)
{
	if (!ft_strcmp(data->v[i], "-dump"))
		data->lastoption = DUMP;
	else if (!ft_strcmp(data->v[i], "-n"))
		data->lastoption = N;
	else
		data->lastoption = ERROR;
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
	if (data->nb_champion < 1 || data->nb_champion > 4)
		return (ft_printf("{red}Nombre de champion invalide{eoc}\n"));
	return (0);
}
