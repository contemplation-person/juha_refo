/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/05/10 02:23:40 by conteng          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*fd_lst;
	t_success		chk_success;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!get_list(&head, &fd_lst, fd))
		return (0);
	if (!read_str(&fd_lst, fd)) /*리드를 했으면 리드 반환 아니면 error반환*/
		return (0);
	return (ret_str(&fd_lst));
}

t_success	free_lst(t_list **fd_lst)
{
	t_list	*prev;
	t_list	*next;

	prev = (*fd_lst)->prev;
	next = (*fd_lst)->next;
	if ((*fd_lst)->buf_len != 0)
		free((*fd_lst)->buf);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	free(*fd_lst);
	return (SUCCESS);
}

t_success	read_str(t_list **fd_lst, int fd)
{
	
}

t_success	get_list(t_list **head, t_list **fd_lst, int fd)
{
	t_list	*prev;

	prev = NULL;
	if (*head)
	{
		*fd_lst = *head;
		while (*fd_lst && (*fd_lst)->fd != fd)
		{
			prev = *fd_lst;
			*fd_lst = (*fd_lst)->next;
		}
		if ((*fd_lst)->fd == fd)
			return (CONTINUE);
	}
	*fd_lst = (t_list *)malloc(sizeof(t_list));
	if (!(*fd_lst))
		return (ERROR);
	(*fd_lst)->fd = fd;
	(*fd_lst)->prev = prev;
	(*fd_lst)->next = NULL;
	(*fd_lst)->buf_len = 0;
	(*fd_lst)->buf = 0;
	if (*head)
		prev->next = *fd_lst;
	else
		*head = *fd_lst;
	return (SUCCESS);
}
