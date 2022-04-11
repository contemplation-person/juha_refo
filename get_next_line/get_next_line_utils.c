/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/09 18:59:29 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char	*s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			size;
	char			*temp;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	temp = (char *)malloc(size);
	if (!temp)
		return (0);
	size = 0;
	while (s1[size])
	{
		temp[size] = s1[size];
		size++;
	}
	i = 0;
	while (s2[i])
		temp[size++] = s2[i++];
	temp[size] = '\0';
	return (temp);
}

static t_list	*ft_lstnew(char *str)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(t_list));
	if (!t)
		return (0);
	t->str = str;
	t->next = NULL;
	return (t);
}

static void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_l = (*lst)->next;
		del((*lst)->str);
		free(lst);
		lst = 0;
		*lst = next_l;
	}
	*lst = 0;
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next)
		t = t->next;
	return (t);
	t->next = new;
}
