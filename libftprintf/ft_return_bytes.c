/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:45:31 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/27 16:03:35 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		return_bytes(int num, int octet)
{
	if (octet == 4)
		return (((num >> 24) & 0xff) |
				((num << 8) & 0xff0000) |
				((num >> 8) & 0xff00) |
				((num << 24) & 0xff000000));
	if (octet == 3)
		 return (((num << 16) & 0xff0000)) |
				((num << 0) & 0xff00) |
				((num >> 16) & (0xff));
	else if(octet == 2)
		return (num >> 8) | (num << 8);
	else
		return (num);
}
