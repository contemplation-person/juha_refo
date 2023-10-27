/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:28:23 by juha              #+#    #+#             */
/*   Updated: 2022/04/04 15:29:17 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_lst;
	t_list	*tmp_lst;

	first_lst = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		tmp_lst = ft_lstnew(f(lst->content));
		if (!tmp_lst)
		{
			ft_lstclear(&first_lst, del);
			return (0);
		}
		ft_lstadd_back(&first_lst, tmp_lst);
		lst = lst->next;
	}
	return (first_lst);
}
