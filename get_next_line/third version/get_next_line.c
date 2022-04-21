/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/20 21:13:34 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd);
t_list	*check_fd(t_list *head, int fd);
char	*cut_until_null(t_list **head, int fd);
char	*ft_strdup(const char *s1, char c);

char	*get_next_line(int fd)
{
	static t_list	*head;
	int				read_len;
	t_list			*new;

	if (BUFFER_SIZE <= 0)
		return (0);
	new = ft_lstnew((char *)malloc(BUFFER_SIZE + 1), fd);
	((char *)(new->content))[BUFFER_SIZE + 1] = '\0';
	if (!new)
		return (0);
	read_len = read(fd, new->content, BUFFER_SIZE);
	if (read_len < 0)
		return (ft_lstclear(&head, fd));
	ft_lstadd_back(&head, new);
	if (read_len == BUFFER_SIZE)
		return (cut_until_null(&head, fd));
	else if (BUFFER_SIZE + 1 > read_len && read_len >= 0)
	{
		if (!check_fd(head, fd))
			return (0);
		return (cut_until_null(&head, fd));
	}
	else
		ft_lstclear(&head, fd);
	return (0);
}

t_list	*check_fd(t_list *head, int fd)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	return (0);
}

char	*cut_until_null(t_list **head, int fd)
{
	char	*str;
	t_list	*fd_temp;
	t_list	*pre_temp;

	pre_temp = *head;
	while ((*head)->fd == fd)
		*head = (*head)->next;
	while (pre_temp)
	{
		if (pre_temp->content)
	}
	/*
		현재 노드의 문자열에 n이 포함되어 있으면   n까지 dup(반환)  //  n에서 끝까지 dup
		fd node 문자열 free() 

		현재 노드의 문자열에 n이 포함되어 있지 않으면 join (str, n까지 dup)
	*/
	
	if ()
	return ();
}

char	*ft_strdup(const char *s1, char c)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	temp = (char *)malloc(i + 1);
	if (!temp)
		return (0);
	i = 0;
	while (s1[i] && s1[i] != c)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
