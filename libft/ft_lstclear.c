/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:56:15 by juha              #+#    #+#             */
/*   Updated: 2022/03/25 19:21:40 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_l;
	}
	*lst = 0;
}
