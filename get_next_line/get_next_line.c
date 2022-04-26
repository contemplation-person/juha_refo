/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/26 18:06:51 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*str;
	ssize_t			read_len;
	t_list			*fd_lst;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	fd_lst = check_fd(head, fd);
	str = (char *)malloc(BUFFER_SIZE);
	if (!str || read_len < 0)
	{
		if (str)
			free(str);
		if (fd_lst)
			free_lst(&fd_lst);
		return (0);
	}
	read_len = read(fd, str, BUFFER_SIZE);
	if (fd_lst && read_len != 0)
		head = input_buf(&fd_lst, str, read_len);
	free (str);
	str = ret_line(fd_lst, fd); /* ret_line 에서 읽은 게 없으면 return (null) */
	return (str);
}

t_list	*input_buf(t_list **fd_lst, char **read_str, ssize_t read_len)
{
	// fd_lst가 0일때 create_lst
	// input_buf
}
