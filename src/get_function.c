/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:24:41 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/18 16:50:50 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			get_option(t_cwdata *data, int *i)
{
	lastoption(data, *i);
	if (data->lastoption && data->c > *i)
	{
		if (!ft_strisdigit(data->v[(*i) + 1]))
			return (ft_printf("{red}%s doit être un nomdre\n", data->v[*i]));
		*i = (*i) + 1;
	}
	else if (data->lastoption == 0)
		return(ft_printf("{red}l'option %s n'est pas valide\n", data->v[*i]));
	return (0);
}

static	int return_bytes(int num)
{
	if ((sizeof(num) * 8) == 32) // if 32bit
		return (((num >> 24) & 0xff) | // move byte 3 to byte 0
				((num << 8) & 0xff0000) | // move byte 1 to byte 2
				((num >> 8) & 0xff00) | // move byte 2 to byte 1
				((num << 24) & 0xff000000)); // byte 0 to byte 3
	else
		return (num >> 8) | (num << 8); // 16 bit
}

static int	reed_champion(char *champion)
{
	int			fd;
	int			ret;
	int			buf;
	header_t	header;

	fd = open(champion, O_RDONLY);
	while ((ret = read(fd, &buf, sizeof(int))))
	{
		if (ret < 0)
			return (ft_printf("{red}Champion invalide\n"));
		ft_printf("-> %08x\n", return_bytes(buf));
		buf = 0;
	}

	header.magic = return_bytes(header.magic);

	// ft_printf("My magic -> %#x\n", header.magic);


	// if (header.magic != COREWAR_EXEC_MAGIC)
	// 	return (ft_printf("{red}le magic n'est pas bon\n"));


	return (0);
}



int			get_champion(t_cwdata *data, int i)
{
	data->nb_champion++;
	if (ft_strlen(data->v[i]) < 5 ||
		ft_strcmp(&data->v[i][ft_strlen(data->v[i]) - 4], ".cor"))
		return (ft_printf("{red}les champion doivent etre des fichier .cor\n"));
	ft_printf("Champion -> %s\n", data->v[i]);
	if (reed_champion(data->v[i]))
		return (1);
	return (0);
}
