/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 21:40:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*fd_lst;

	fd_lst = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!get_list(&head, &fd_lst, fd))
		return (0);
	if (!read_str(&fd_lst, fd))
	{
		if (free_lst(&head, &fd_lst))
			return (NULL);
	}
	return (ret_str(&head, &fd_lst));
}

t_success	join_str(t_list **fd_lst, char **str, ssize_t read_len)
{
	char		*temp;
	ssize_t		i;

	i = 0;
	temp = (char *)malloc((*fd_lst)->buf_len + read_len);
	if (!temp)
		return (ERROR);
	ft_memcpy(temp, (*fd_lst)->buf, (*fd_lst)->buf_len);
	ft_memcpy(temp + (*fd_lst)->buf_len, *str, read_len);
	free(*str);
	free((*fd_lst)->buf);
	(*fd_lst)->buf_len = (*fd_lst)->buf_len + read_len;
	(*fd_lst)->buf = temp;
	while (i < (*fd_lst)->buf_len)
	{
		if (temp[i] == '\n')
			return (SUCCESS);
		i++;
	}
	return (CONTINUE);
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

void	set_fd_list(t_list **fd_lst, t_list *prev, int fd)
{
	(*fd_lst)->fd = fd;
	(*fd_lst)->prev = prev;
	(*fd_lst)->next = NULL;
	(*fd_lst)->buf_len = 0;
	(*fd_lst)->buf = 0;
}

ssize_t	get_ret_len(t_list **fd_lst)
{
	ssize_t	ret_len;

	ret_len = 0;
	while (ret_len < (*fd_lst)->buf_len)
	{
		if ((*fd_lst)->buf[ret_len++] == '\n')
			break ;
	}
	return (ret_len);
}
