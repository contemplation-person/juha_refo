/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/05/03 22:14:32 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	create_ret_save(t_list **fd_lst, char **ret, ssize_t ret_len, char **save)
{
	*ret = (char *)malloc(ret_len + 1);
	if (!(*ret))
	{
		free((*fd_lst)->buf);
		free(*fd_lst);
		return (0);
	}
	if ((*save))
	{
		*save = (char *)malloc((*fd_lst)->buf_len - ret_len);
		if (!(*save))
		{
			free(*ret);
			free((*fd_lst)->buf);
			free(*fd_lst);
			return (0);
		}
	}
	return (1);
}

ssize_t	check_line(t_list *fd_lst, ssize_t ret_len)
{
	while (fd_lst->buf_len > ret_len)
	{
		if (fd_lst->buf[ret_len] == '\n')
		{
			ret_len++;
			break ;
		}
		ret_len++;
	}
	return (ret_len);
}

char	*split_line(t_list **fd_lst, ssize_t *ret_len, int *is_success)
{
	char	*ret;
	char	*save;

	if ((*fd_lst)->buf_len - *ret_len)
	{
		*is_success = create_ret_save(fd_lst, &ret, *ret_len, &save);
		ft_memcpy(ret, (*fd_lst)->buf, *ret_len);
		ret[*ret_len] = '\0';
		ft_memcpy(save, (*fd_lst)->buf + *ret_len, \
			(*fd_lst)->buf_len - *ret_len);
		free((*fd_lst)->buf);
		(*fd_lst)->buf = save;
		(*fd_lst)->buf_len = (*fd_lst)->buf_len - *ret_len;
	}
	else
	{
		save = 0;
		*is_success = create_ret_save(fd_lst, &ret, (*fd_lst)->buf_len, &save);
		ft_memcpy(ret, (*fd_lst)->buf, (*fd_lst)->buf_len);
		ret[(*fd_lst)->buf_len] = '\0';
		free((*fd_lst)->buf);
		free((*fd_lst));
		*fd_lst = 0;
	}
	return (ret);
}

char	*ret_line(t_list **fd_lst, int *is_success)
{
	ssize_t	ret_len;

	ret_len = 0;
	if (!(*fd_lst))
		return (0);
	ret_len = check_line(*fd_lst, ret_len);
	return (split_line(fd_lst, &ret_len, is_success));
}
