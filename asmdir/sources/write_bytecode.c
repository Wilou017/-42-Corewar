/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:18:27 by dgalide           #+#    #+#             */
/*   Updated: 2017/01/12 11:18:28 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int			dec_value(char c)
{
	return (c - ((c >= 97 && c <= 122) ? 87 : 48));
}

static int			write_bytecode_ext(int i, char *tmp, int power)
{
	if (i > 0)
	{
		return (dec_value(tmp[i]) * ft_power(16, power)) +
		(dec_value(tmp[i - 1]) * ft_power(16, power + 1));
	}
	else
		return (tmp[i] - ((tmp[i] >= 97 && tmp[i] <= 122) ? 87 : 48));
}

int		return_bytes(int num, int octet)
{
	if (octet == 4)
	{

		return (((num >> 24) & 0xff) |
			((num << 8) & 0xff0000) |
			((num >> 8) & 0xff00) |
			((num << 24) & 0xff000000));
	}
	if (octet == 3)
	{
		return (((num << 16) & 0xff0000) |
			((num << 0) & 0xff00) |
			((num >> 16) & (0xff)));
	}
	else if (octet == 2)
		return (num >> 8) | (num << 8);
	else
		return (num);
}

void				write_bytecode1(unsigned int value, int size_value, int fd)
{
	char			*tmp;
	char			*tmp1;
	int				i;
	int				j;
	char			*tmp2;

	tmp = ft_itoa(value, 16);
	tmp1 = ft_strnew(size_value);
	i = ft_strlen(tmp) - 1;
	j = size_value - 1;
	while (i > 0)
	{
		tmp2 = ft_strsub(tmp, i - 1, 2);
		tmp1[j--] = ft_atoi_base(tmp2, 16);
		i -= 2;
	}
	while (j > 0)
		tmp1[j--] = 0;
	write(fd, tmp1, size_value);
}

void				write_bytecode(unsigned int value, int size_value, int fd)
{
	char			*tmp;
	char			*tmp1;
	int				i;
	int				j;
	int				power;

	tmp = ft_itoa(value, 16);
	tmp1 = ft_strnew(size_value);
	i = ft_strlen(tmp) - 1;
	j = size_value - 1;
	power = 0;
	while (i >= 0)
	{
		tmp1[j] = write_bytecode_ext(i, tmp, power);
		i -= 2;
		j -= 1;
		power += 2;
	}
	while (j >= 0)
		tmp1[j--] = 0;
	free(tmp);
	write(fd, tmp1, size_value);
	free(tmp1);
}
