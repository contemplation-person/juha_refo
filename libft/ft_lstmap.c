/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:28:23 by juha              #+#    #+#             */
/*   Updated: 2022/03/26 11:43:26 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_l;
	t_list	*l;

	first_l = ft_lstnew(f(lst));
	lst = lst->next;
	while (lst)
	{
		l = ft_lstnew(f(lst));
		if (!l)
		{
			ft_lstclear(&first_l, del);
			return (0);
		}
		ft_lstadd_back(&first_l, l);
		lst = lst->next;
	}
	return (first_l);
}
