/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/21 19:47:21 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	all_free(t_list	**head, int fd, char *str);

char	*get_next_line(int fd)
{
	static t_list	*head;
	ssize_t			read_len;
	char			*str;

	str = (char *)malloc(BUFFER_SIZE);
	if (!str)
		return (all_free(&head, fd, str));
	read_len = read(fd, str, BUFFER_SIZE);
	if (0 > read_len || 0 > BUFFER_SIZE)
		return (all_free(&head, fd, str));
	if (0 == read_len)
	{
		if (check_lst(head, fd))
			return (ret_line(head)); /*남은 값이 0면 free_all;*/
		return (0);
	}
	else
	{
		/* 개행까지 반환 및 함수를 조인 */
	}
}

t_list	*check_lst(head, fd)
{
/*
	fd_node가 있는지 확인. fd_node의 주솟값 반환;
*/
}

int	all_free(t_list	**head, int fd, char *str)
{
	t_list	*prev_del_lst;
	t_list	*del_lst;

	prev_del_lst = *head;
	del_lst = 0;
	*head = (*head)->next_fd;
	if (str)
		free(str);
	if (prev_del_lst)
	{
		while (prev_del_lst->next_fd->fd == fd)
			prev_del_lst->next_fd;
		del_lst = prev_del_lst->next_fd;
		prev_del_lst->next_fd = del_lst->next_fd;
		free(del_lst);
	}
	return (0);
}
