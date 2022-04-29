/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/30 07:36:31 by juha             ###   ########seoul.kr  */
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
	t_list	*temp;

	if (*head)
	{
		prev = *head;
		while ((*head)->next->fd < fd && (*head)->next != prev)
			*head = (*head)->next;
	}
	temp = *head;
	*head = (t_list *)malloc(sizeof(t_list));
	if (*head)
		return (0);
	temp->next->prev = *head;
	(*head)->next = temp->next;
	temp->next = *head;
	(*head)->prev = temp; /*확인 필요*/
	temp->fd = fd;
	temp->buf = *buf;
	temp->buf_len = buf_len;
	return (*head);
}

int	join_str(t_list **fd_lst, char **save, ssize_t read_len)
{
	char	*temp;

	temp = (char *)malloc(read_len + (*fd_lst)->buf_len);
	if (!temp)
		return (0);
	ft_memcpy(temp, (*fd_lst)->buf, (*fd_lst)->buf_len);
	ft_memcpy(temp + (*fd_lst)->buf_len, save, read_len);
	free((*fd_lst)->buf);
	free(*save);
	(*fd_lst)->buf = temp;
	(*fd_lst)->buf_len = (*fd_lst)->buf_len + read_len;
	return (1);
}
