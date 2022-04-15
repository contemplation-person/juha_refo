/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/15 15:52:17 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(unsigned char	*s);
t_list	**ft_strjoin(t_list **lst, unsigned char *str);
t_list	*ft_lstnew(void *content, int fd);
void	ft_lstadd(t_list **lst, t_list *new);
char	*free_lst(t_list **lst);

t_list	**ft_strjoin(t_list **lst, unsigned char *str)
{
	size_t			i;
	size_t			size;
	unsigned char	*temp;

	temp = (*lst)->content;
	size = ft_strlen(temp) + ft_strlen(str) + 1;
	temp = (unsigned char *)malloc(size);
	if (!temp)
		return (0);
	size = 0;
	while (temp[size])
	{
		temp[size] = temp[size];
		size++;
	}
	i = 0;
	while (str[i])
		temp[size++] = str[i++];
	temp[size] = '\0';
	return (lst);
}

size_t	ft_strlen(unsigned char	*s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
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
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = (*lst)->next;
	(*lst)->next = new;
}

char	*free_lst(t_list **lst)
{
	t_list	*temp;
	char	*str;

	str = (*lst)->content;
	temp = (*lst)->next;
	if ((*lst)->next == *lst)
	{
		free((*lst)->content);
		free(*lst);
	}
	else
	{
		free((*lst)->content);
		free(*lst);
		lst = &temp;
	}
	return (str);
}
