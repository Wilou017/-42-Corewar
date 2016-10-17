/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:24:41 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/30 19:09:05 by amaitre          ###   ########.fr       */
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

unsigned char		*decimal_to_bytecode(int value, int size_value)
{
	char *tmp;
	unsigned char *tmp1;
	int i;
	int j;

	tmp = ft_itoa(value, 16);
	tmp1 = ft_memset(ft_memalloc(size_value), 0, size_value);
	i = 0;
	j = size_value - ft_strlen(tmp) / 2;
	while (j < size_value)
	{
		tmp1[j] = ((tmp[i] - ((tmp[i] >= 97 && tmp[i] <= 122) ? 87 : 48))
		* ft_pwe(16, 1)) + ((tmp[i + 1] - ((tmp[i] >= 97 && tmp[i] <= 122)
		 ? 87 : 48)) * ft_pwe(16, 0));
		i += 2;
		j += 1;
	}
	free(tmp);
	return (tmp1);
}

static int	reed_champion(char *champion)
{
	int			fd;
	int			ret;
	header_t	header;

	fd = open(champion, O_RDONLY);
	ret = read(fd, &header.magic, sizeof(header.magic));
	ft_printf("My magic -> %s\n", decimal_to_bytecode(header.magic, sizeof(header.magic)));
	if (ret < 0)
		return (ft_printf("{red}Champion invalide\n"));
	if (header.magic != (unsigned int)-209458688)
		return (ft_printf("{red}le magic n'est pas bon\n"));
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
