/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:24:41 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/27 18:42:29 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			cw_get_option(t_cwdata *data, int *i)
{
	cw_lastoption(data, *i);
	if (data->lastoption && data->c > *i)
	{
		if (!ft_strisdigit(data->v[(*i) + 1]))
			return (ft_printf("{red}%s doit être un nomdre\n", data->v[*i]));
		data->lastdata = ft_strdup(data->v[(*i) + 1]);
		*i = (*i) + 1;
	}
	else if (data->lastoption == 0)
		return(ft_printf("{red}l'option %s n'est pas valide\n", data->v[*i]));
	return (0);
}

static void	distrib_data(int status, int octet, header2_t *champion)
{
	char oct[5];

	if(status == 0)
		champion->magic = octet;
	if(status >= 1 && status <= (PROG_NAME_LENGTH/4 + 1))
	{
		oct[0] = octet >> 24;
		oct[1] = octet >> 16;
		oct[2] = octet >> 8;
		oct[3] = octet >> 0;
		oct[4] = 0;
		champion->prog_name = ft_strjoin(champion->prog_name, oct, 1);
	}
	if(status > (PROG_NAME_LENGTH/4 + 2) &&
		status - (PROG_NAME_LENGTH/4 + 2) < COMMENT_LENGTH/4)
	{
		oct[0] = octet >> 24;
		oct[1] = octet >> 16;
		oct[2] = octet >> 8;
		oct[3] = octet >> 0;
		oct[4] = 0;
		champion->comment = ft_strjoin(champion->comment, oct, 1);
	}
}

static int	reed_champion(char *name, header2_t *champion)
{
	int			fd;
	int			ret;
	int			buf;
	int			status;

	fd = open(name, O_RDONLY);
	status = 0;
	while ((ret = read(fd, &buf, sizeof(int))))
	{
		if (ret < 0)
			return (ft_printf("{red}Champion invalide\n"));
		buf = return_bytes(buf, ret);
		// ft_printf("%d -> %.8x\n", ret, buf);
		distrib_data(status, buf, champion);
		buf = 0;
		status++;
	}
	if (champion->magic != 0xea83f3)
		return (ft_printf("{red}Magic invalide\n"));

	ft_printf("Nom     = %s\n", champion->prog_name);
	ft_printf("Comment = %s\n", champion->comment);


	return (0);
}

int			cw_get_champion(t_cwdata *data, int i)
{
	header2_t	*champion;

	data->nb_champion++;
	champion = cw_add_champ_to_lst(data);
	champion->id = data->nb_champion * -1;
	ft_printf("\nid -> %d\n", champion->id);
	ft_printf("data->lastdata -> %s\n", data->lastdata);
	data->lastdata = NULL;
	if (ft_strlen(data->v[i]) < 5 ||
		ft_strcmp(&data->v[i][ft_strlen(data->v[i]) - 4], ".cor"))
		return (ft_printf("{red}les champions doivent etre des fichier .cor\n"));
	ft_printf("Champion -> %s\n", data->v[i]);
	if (reed_champion(data->v[i], champion))
		return (1);
	return (0);
}
