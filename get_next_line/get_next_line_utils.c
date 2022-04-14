/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/14 16:45:25 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char	*s, int *line)
{
	size_t	cnt;

	cnt = 0;
	if (!line)
	{
		while (s[cnt])
			cnt++;
		return (cnt);
	}
	else
	{
		line = 0;
		while (s[cnt])
		{
			if (s[cnt] == '\n')
			{
				*line = cnt;
				break ;
			}
			cnt++;
		}
		while (s[cnt])
			cnt++;
		return (cnt);
	}
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			size;
	char			*temp;

	if (s1 && s2)
		size = ft_strlen(s1, (void *)0) + ft_strlen(s2, (void *)0) + 1;
	else if (!s2)
		size = ft_strlen(s1, (void *)0) + 1;
	else
		size = ft_strlen(s2, (void *)0) + 1;
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

static t_list	*ft_lstnew(void *content, int fd)
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

static void	ft_lstadd(t_list **lst, t_list *new)
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

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	k;

	if (start > ft_strlen(s, (void *)0))
	{
		temp = (char *)malloc(1);
		temp[0] = '\0';
		return (temp);
	}
	k = 0;
	while (s[start + k])
		k++;
	if (len > k)
		len = k;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	i = start;
	j = 0;
	while (j < len)
		temp[j++] = (char)s[i++];
	temp[j] = '\0';
	return (temp);
}
