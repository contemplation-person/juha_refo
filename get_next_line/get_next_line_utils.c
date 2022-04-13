/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/13 19:53:28 by juha             ###   ########seoul.kr  */
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

	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
	else if (!s1 && s2)
		size = ft_strlen(s2) + 1;
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

t_list	*ft_lstnew(void *content, int fd)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(t_list));
	if (!t)
		return (0);
	t->content = content;
	t->fd = fd;
	t->next = t;
	return (t);
}

void	ft_lstadd(t_list **lst, t_list *new)
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
	t->next = new;
	new->next = *lst;
}

void	ft_lstdelone(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	while (temp->next == *lst)
		temp->next;
	del((*lst)->content);
	temp->next = (*lst)->next;
	free(lst);
	lst = 0;
}
