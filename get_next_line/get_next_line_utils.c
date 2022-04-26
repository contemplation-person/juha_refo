/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/26 18:07:01 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*check_fd(t_list **head, int fd);
void	free_lst(t_list **target_lst);
t_list	*create_lst(t_list **head, int fd);
ssize_t	ft_strlen(const char *s, ssize_t end);
void	*ft_memcpy(void *dst, const void *src, size_t n);

t_list	*check_fd(t_list **head, int fd)
{
	t_list	*prev;
	t_list	*next;

	if (!(*head))
		return (0);
	prev = (*head)->prev;
	next = (*head)->next;
	if (*head && (*head)->fd > fd)
	{
		while ((*head)->next != next)
		{
			prev = (*head);
			(*head) = (*head)->next;
			next = (*head)->next;
		}
		return (*head);
	}
	while (*head && (*head)->next != next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		next = (*head)->next;
	}
	return ((*head));
}

void	free_lst(t_list **target_lst)
{
	t_list	*next;
	t_list	*prev;
	int		rm_pointer;

	rm_pointer = 0;
	if (*target_lst)
	{
		next = (*target_lst)->next;
		prev = (*target_lst)->prev;
		if (next == *target_lst)
			rm_pointer = 1;
		free((*target_lst)->buf);
		prev->next = next;
		next->prev = prev;
		free(*target_lst);
		if (rm_pointer)
			*target_lst = 0;
	}
}

t_list	*create_lst(t_list **head, int fd)
{
	t_list	*prev;
	t_list	*next;
	t_list	*temp;

	temp = *head;
	prev = temp->prev;
	next = temp->next;
	if (temp->fd == fd)
		return (*head);
	if (temp && temp->fd > fd)
	{
		while (temp->next != next)
		{
			prev = temp;
			temp = temp->next;
			next = temp->next;
		}
	}
	else if (temp && temp->fd < fd)
	{
		while (temp->prev != prev)
		{
			next = temp;
			temp = temp->prev;
			prev = temp->prev;
		}
	}
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp->fd = fd;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}

ssize_t	ft_strlen(const char *s, ssize_t end)
{
	ssize_t	i;

	i = 0;
	while (i != end)
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp		/*존재하지 않는데 read_len == 0이 아님.*/;
	size_t			cnt;

	temp = (unsigned char *)src;
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = temp[cnt];
		cnt++;
	}
	return (dst);
}
