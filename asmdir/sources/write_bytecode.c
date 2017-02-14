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

int					return_bytes(int num, int octet)
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

void				write_bytecode(int value, int size_value, int fd)
{
	unsigned int bin;

	bin = return_bytes(value, size_value);
	write(fd, &value, size_value);
}
