/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/26 22:12:58 by juha             ###   ########seoul.kr  */
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

	read_len = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	fd_lst = check_fd(&head, fd);
	str = (char *)malloc(BUFFER_SIZE);
	if (!str || read_len < 0)
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
	if (fd_lst && read_len != 0)
		head = input_buf(&fd_lst, fd, &str, read_len);
	free (str);
	str = ret_line(fd_lst); /* ret_line 에서 읽은 게 없으면 return (null) */
	return (str);
}

char	*ret_line(t_list *fd_lst)
{
	char	*ret;
	char	*save;
	ssize_t	ret_len;	

	if (!fd_lst)
		return (0);
	ret_len = ft_strlen(fd_lst->buf, fd_lst->buf_len);
	make_ret_and_save(&ret, &save, &fd_lst, ret_len);
	if (!ret || !save)
		return (0);
	ft_memcpy(ret, fd_lst->buf, fd_lst->buf_len);
	ft_memcpy(save, fd_lst->buf + ret_len, fd_lst->buf_len - ret_len);
	if (!(fd_lst->buf_len - ret_len))
		free_lst(&fd_lst);
	else
		fd_lst->buf_len = fd_lst->buf_len - ret_len; /* 오류나면 여기가 문제 */
	return (ret);
}

void	make_ret_and_save(char **ret, char **save, \
t_list **fd_lst, ssize_t ret_len)
{
	*ret = (char *)malloc(ret_len);
	if (!*ret)
	{
		free_lst(fd_lst);
		*fd_lst = 0;
		return ;
	}		
	*save = (char *)malloc((*fd_lst)->buf_len - ret_len);
	if (!*save)
	{
		free(*ret);
		free_lst(fd_lst);
		ret = 0;
		fd_lst = 0;
	}
}

t_list	*input_buf(t_list **fd_lst, int fd, char **read_str, ssize_t read_len)
{
	char	*save;

	if (fd_lst)
	{
		save = (char *)malloc((*fd_lst)->buf_len + read_len);
		if (!save)
			return (0);
		save = ft_memcpy(save, (*fd_lst)->buf, (*fd_lst)->buf_len);
		save = ft_memcpy(save + (*fd_lst)->buf_len, read_str, read_len);
		(*fd_lst)->buf_len = (*fd_lst)->buf_len + read_len;
	}
	else
	{
		*fd_lst = create_lst(fd_lst, fd);
		(*fd_lst)->buf = *read_str;
		(*fd_lst)->buf_len = read_len;
	}
	return (*fd_lst);
}
