/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 11:50:14 by conteng          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_success	get_list(t_list **head, t_list **fd_lst, int fd);
t_success	free_lst(t_list **fd_lst);

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*fd_lst;
	t_success		chk_success;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!get_list(&head, &fd_lst, fd))
		return (0);
	if (!read_str(&fd_lst, fd))
		return (free_lst(fd_lst) >> 1);
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
	if (!prev || !next)
		*fd_lst = 0;
	return (SUCCESS);
}
// good

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
		if (*fd_lst && (*fd_lst)->fd == fd)
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
	if (prev)
		prev->next = *fd_lst;
	else
		*head = *fd_lst;
	return (SUCCESS);
}
//good

t_success	join_str(t_list **fd_lst, char **str, ssize_t read_len)
{
	char		*temp;
	ssize_t		i;
	t_success	include_line;

	include_line = CONTINUE;
	temp = (char *)malloc((*fd_lst)->buf_len + read_len);
	if (!temp)
		return (ERROR);
	i = -1;
	while (++i < (*fd_lst)->buf_len)
	{
		temp[i] = (*fd_lst)->buf[i];
		if (temp[i] == '\n')
			include_line = SUCCESS;
	}
	while (++i % (*fd_lst)->buf_len < read_len)
	{
		temp[i] = (*str)[i % (*fd_lst)->buf_len];
		if (temp[i] == '\n')
			include_line = SUCCESS;
	}
	free(*str);
	free((*fd_lst)->buf);
	(*fd_lst)->buf_len = (*fd_lst)->buf_len + read_len;
	return (include_line);
}

t_success	read_str(t_list **fd_lst, int fd)
{
	char		*str;
	ssize_t		read_len;
	t_success	state;

	str = (char *)malloc(BUFFER_SIZE);
	if (!str)
		return (ERROR);
	read_len = read(fd, str, BUFFER_SIZE);
	if (read_len < 0 || (read_len == 0 && (*fd_lst)->buf_len == 0))
	{
		free(str);
		return (ERROR);
	}
	if (read_len == 0)
	{
		free(str);
		return (CONTINUE);
	}
	state = join_str(fd_lst, &str, read_len);
	if (state == SUCCESS)
		return (state);
	if (state == CONTINUE)
		return (read_str(fd_lst, fd));
	return (ERROR);
}
