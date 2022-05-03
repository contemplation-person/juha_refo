/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/05/03 16:57:38 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;
	size_t			cnt;

	temp = (unsigned char *)src;
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *) dst)[cnt] = temp[cnt];
		cnt++;
	}
	return (dst);
}

t_list	*create_lst(t_list **head, int fd, char **buf, ssize_t buf_len)
{
	t_list	*prev;

	prev = *head;
	if (prev)
	{
		while (prev->next->fd < fd && prev->next != prev)
			*head = prev->next;
	}
	*head = (t_list *)malloc(sizeof(t_list));
	if (!*head)
		return (0);
	(*head)->fd = fd;
	(*head)->buf = *buf;
	(*head)->buf_len = buf_len;
	if (!prev)
	{
		(*head)->next = *head;
		(*head)->prev = *head;
		return (*head);
	}
	prev->next->prev = *head;
	(*head)->next = prev->next;
	(*head)->prev = prev;
	prev->next = *head;
	return (*head);
}

int	join_str(t_list **fd_lst, char **save, ssize_t read_len)
{
	char	*temp;

	temp = (char *)malloc(read_len + (*fd_lst)->buf_len);
	if (!temp)
		return (0);
	ft_memcpy(temp, (*fd_lst)->buf, (*fd_lst)->buf_len);
	ft_memcpy(temp + (*fd_lst)->buf_len, *save, read_len);
	free((*fd_lst)->buf);
	free(*save);
	(*fd_lst)->buf = temp;
	(*fd_lst)->buf_len = (*fd_lst)->buf_len + read_len;
	return (1);
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	temp = (char *)malloc(i + 1);
	if (!temp)
		return (0);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
