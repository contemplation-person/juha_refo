/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/05/03 18:19:38 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*str;
	int				is_success;
	t_list			*temp;

	is_success = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (lst)
	{
		temp = lst;
		while (lst->next != temp && lst->fd != fd)
			lst = lst->next;
	}
	input_str(&lst, fd, &is_success);
	if (is_success)
		str = ret_line(&lst, &is_success);
	if (!is_success)
		return (0);
	return (str);
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

char	*ret_line(t_list **fd_lst, int *is_success)
{
	char	*ret;
	char	*save;
	ssize_t	ret_len;

	*is_success = 1;
	ret_len = 0;
	if (!(*fd_lst))
		return (0);
	while ((*fd_lst)->buf_len > ret_len)
	{
		if ((*fd_lst)->buf[ret_len] == '\n')
		{
			ret_len++;
			break ;
		}
		ret_len++;
	}
	if ((*fd_lst)->buf_len - ret_len)
	{
		ret = (char *)malloc(ret_len + 1);
		if (!ret)
		{
			free((*fd_lst)->buf);
			free(*fd_lst);
			*is_success = 0;
			return (0);
		}
		save = (char *)malloc((*fd_lst)->buf_len - ret_len);
		if (!save)
		{
			free(ret);
			free((*fd_lst)->buf);
			free(*fd_lst);
			*is_success = 0;
			return (0);
		}
		ft_memcpy(ret, (*fd_lst)->buf, ret_len);
		ret[ret_len] = '\0';
		ft_memcpy(save, (*fd_lst)->buf + ret_len, (*fd_lst)->buf_len - ret_len);
		free((*fd_lst)->buf);
		(*fd_lst)->buf = save;
		(*fd_lst)->buf_len = (*fd_lst)->buf_len - ret_len;
		/*save 와 ret을 분할.*/ /*join_str함수 활용방안 고민*/
	}
	else
	{
		ret = (char *)malloc((*fd_lst)->buf_len + 1);
		if (!ret)
		{
			free((*fd_lst)->buf);
			free((*fd_lst));
			*is_success = 0;
			return (0);
		}
		ft_memcpy(ret, (*fd_lst)->buf, (*fd_lst)->buf_len);
		ret[(*fd_lst)->buf_len] = '\0';
		free((*fd_lst)->buf);
		free((*fd_lst));
		*fd_lst = 0;
	}
	return (ret);
}
