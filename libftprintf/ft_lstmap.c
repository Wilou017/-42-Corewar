/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:29:53 by amaitre           #+#    #+#             */
/*   Updated: 2016/02/19 16:48:03 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l_tmp;
	t_list	*l_result;

	if (!lst || !f)
		return (NULL);
	l_result = f(lst);
	l_tmp = l_result;
	lst = lst->next;
	while (lst)
	{
		l_tmp->next = f(lst);
		l_tmp = l_tmp->next;
		lst = lst->next;
	}
	return (l_result);
}
