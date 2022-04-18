/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/18 21:48:17 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content, int fd);
void	ft_lstclear(t_list **lst, int fd);
size_t	ft_strlen(const char	*s);
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
	t->next = t;
	return (t);
}

void	ft_lstclear(t_list **lst, int fd)
{
	t_list	*next_l;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->fd == fd)
		{
			next_l = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			(*lst) = 0;
			*lst = next_l;
		}
	}
	*lst = 0;
}

size_t	ft_strlen(const char	*s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	t = *lst;
	t = ft_lstlast(t);
	t->next = new;
}
