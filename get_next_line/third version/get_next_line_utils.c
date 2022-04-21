/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/20 15:52:02 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content, int fd);
int		ft_lstclear(t_list **lst, int fd);
size_t	ft_strlen(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_lstadd_back(t_list **lst, t_list *new);

t_list	*ft_lstnew(void *content, int fd)
{
	t_list	*t;

	if (!content)
		return (0);
	t = (t_list *)malloc(sizeof(t_list));
	if (!t)
		return (0);
	t->fd = fd;
	t->content = content;
	t->next = 0;
	return (t);
}

int	ft_lstclear(t_list **lst, int fd)
{
	t_list	*pre_lst;

	if (!lst)
		return (0);
	while (*lst && (*lst)->fd == fd)
	{
		pre_lst = *lst;
		*lst = (*lst)->next;
		free(pre_lst->content);
		free(pre_lst);
	}
	pre_lst = *lst;
	while (pre_lst)
	{
		if (pre_lst->next->fd == fd)
		{
			pre_lst->next = pre_lst->next;
			pre_lst->next = pre_lst->next->next;
			free(pre_lst->next->content);
			free(pre_lst->next);
		}
		else
			pre_lst = pre_lst->next;
	}
	return (0);
}

size_t	ft_strlen(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] && s[cnt] != c)
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			size;
	char			*temp;

	if (s1 && s2)
		size = ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1;
	else if (!s2)
		size = ft_strlen(s1, 0) + 1;
	else
		size = ft_strlen(s2, 0) + 1;
	temp = (char *)malloc(size);
	if (!temp)
		return (0);
	size = 0;
	while (s1 && s1[size])
	{
		temp[size] = s1[size];
		size++;
	}
	i = 0;
	while (s2 && s2[i])
		temp[size++] = s2[i++];
	temp[size] = '\0';
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
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
}
