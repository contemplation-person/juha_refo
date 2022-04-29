/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/29 14:31:53 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*fd_lst;
	char			*str;
	ssize_t			read_len;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	fd_lst = check_fd(&fd_lst, fd);
	str = (char *)malloc(BUFFER_SIZE);
	if (!str)
	{
		if (fd_lst)
			free_lst(&fd_lst);
		return (0);
	}
	read_len = read(fd, str, BUFFER_SIZE);
	if (read_len < 0)
	{
		free(str);
		free(fd_lst);
		return (0);
	}
	if (read_len != 0)
		fd_lst = input_buf(&fd_lst, fd, &str, read_len);
	free(str);
	return (ret_line(&fd_lst));
}

char	*ret_line(t_list **fd_lst)
{
	char	*ret;
	char	*save;
	ssize_t	ret_len;

	ret_len = ft_strlen((*fd_lst)->buf, (*fd_lst)->buf_len);
	if ((*fd_lst)->buf_len - ret_len)
	{
		ret = (char *)malloc(ret_len);
		if (!ret)
		{
			free_lst(fd_lst);
			return (0);
		}
		save = (char *)malloc((*fd_lst)->buf_len - ret_len);
		if (!save)
		{
			free_lst(fd_lst);
			free(ret);
			return (0);
		}
		ft_memcpy(ret, (*fd_lst)->buf, ret_len);
		ft_memcpy(save, (*fd_lst)->buf + ret_len, (*fd_lst)->buf_len - ret_len);
		free((*fd_lst)->buf);
		(*fd_lst)->buf = save;
		return (ret);
	}
	ret = (*fd_lst)->buf;
	free(*fd_lst);
	*fd_lst = 0;
	return (ret);
}

t_list	*input_buf(t_list **fd_lst, int fd, char **read_str, ssize_t read_len)
{
	char	*save;
	ssize_t	buf_len;

	if (*fd_lst)
	{
		buf_len = (*fd_lst)->buf_len;
		save = (char *)malloc(buf_len + read_len + 1);
		save[buf_len + read_len] = 0;
		if (!save)
			return (0);
		ft_memcpy(save, (*fd_lst)->buf, buf_len);
		ft_memcpy((save + (*fd_lst)->buf_len), *read_str, read_len);
		free((*fd_lst)->buf);
		(*fd_lst)->buf = save;
		(*fd_lst)->buf_len = (*fd_lst)->buf_len + read_len;
	}
	else
	{
		*fd_lst = create_lst(fd_lst, fd);
		(*fd_lst)->buf = (char *)malloc(read_len);
		if (!((*fd_lst)->buf))
		{
			free (*fd_lst);
			return (0);
		}
		(*fd_lst)->buf_len = read_len;
		ft_memcpy((*fd_lst)->buf, *read_str, read_len);
	}
	return (*fd_lst);
}
