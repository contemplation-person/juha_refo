/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/05/03 22:14:30 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

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

int	check_fd(t_list **fd_lst, int fd, char **temp, int read_len)
{
	int	is_join;

	if (*fd_lst && (*fd_lst)->fd == fd)
	{
		is_join = join_str(fd_lst, temp, read_len);
		if (!is_join)
		{
			free(*temp);
			return (0);
		}
	}
	else
	{
		if (!create_lst(fd_lst, fd, temp, read_len))
		{
			free(*temp);
			return (0);
		}
	}
	return (1);
}

int	input_str(t_list **fd_lst, int fd, int *is_success)
{
	ssize_t	read_len;
	ssize_t	i;
	char	*temp;

	temp = (char *)malloc(BUFFER_SIZE);
	if (!temp)
		return (0);
	read_len = read(fd, temp, BUFFER_SIZE);
	if (read_len < 0 || read_len == 0)
	{
		free(temp);
		return (read_len == 0);
	}
	if (!check_fd(fd_lst, fd, &temp, read_len))
		return (0);
	i = -1;
	while (++i < (*fd_lst)->buf_len)
	{
		if ((*fd_lst)->buf[i] == '\n')
			return (1);
	}
	*is_success = input_str(fd_lst, fd, is_success);
	return (1);
}
