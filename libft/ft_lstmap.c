/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:28:23 by juha              #+#    #+#             */
/*   Updated: 2022/03/25 19:47:35 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;

	l = ft_lstnew(f(lst->content));
	while (lst)
	{
		l->next = ft_lstnew(f(lst->content));
		l = l->next;
		lst = lst->next;
	}
	return (l);
}
