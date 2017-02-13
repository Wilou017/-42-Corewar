/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:55:12 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/11 18:54:47 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst)
		return ;
	tmp = NULL;
	while (*lst)
	{
		tmp2 = (*lst)->next;
		(*lst)->next = tmp;
		tmp = *lst;
		*lst = tmp2;
	}
	*lst = tmp;
}
