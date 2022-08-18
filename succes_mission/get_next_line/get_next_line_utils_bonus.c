/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/05/14 14:42:41 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*set_save(t_list **fd_lst, char **ret, ssize_t ret_len)
{
	char	*save;

	save = (char *)malloc((*fd_lst)->buf_len - ret_len);
	if (!save)
	{
		free(*ret);
		return (NULL);
	}
	ft_memcpy(save, (*fd_lst)->buf + ret_len, (*fd_lst)->buf_len - ret_len);
	free((*fd_lst)->buf);
	(*fd_lst)->buf_len = (*fd_lst)->buf_len - ret_len;
	(*fd_lst)->buf = save;
	return (save);
}

char	*ret_str(t_list **head, t_list **fd_lst)
{
	char	*ret;
	char	*save;
	ssize_t	ret_len;

	ret_len = get_ret_len(fd_lst);
	ret = (char *)malloc(ret_len + 1);
	if (!ret)
	{
		if (free_lst(head, fd_lst))
			return (NULL);
	}
	ft_memcpy(ret, (*fd_lst)->buf, ret_len);
	ret[ret_len] = '\0';
	if ((*fd_lst)->buf_len - ret_len)
	{
		save = set_save(fd_lst, &ret, ret_len);
		if (!save)
			return (NULL);
	}
	else
		free_lst(head, fd_lst);
	return (ret);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;
	size_t			cnt;

	temp = (unsigned char *)src;
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = temp[cnt];
		cnt++;
	}
	return (dst);
}

t_success	free_lst(t_list **head, t_list **fd_lst)
{
	t_list	*fd_prev;
	t_list	*fd_next;

	fd_prev = (*fd_lst)->prev;
	fd_next = (*fd_lst)->next;
	if ((*fd_lst)->buf_len != 0)
		free((*fd_lst)->buf);
	if ((*fd_lst)->fd == (*head)->fd)
		*head = fd_next;
	if (fd_prev)
		fd_prev->next = fd_next;
	if (fd_next)
		fd_next->prev = fd_prev;
	free(*fd_lst);
	if (!fd_prev || !fd_next)
		*fd_lst = 0;
	return (SUCCESS);
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
		if (*fd_lst && (*fd_lst)->fd == fd)
			return (CONTINUE);
	}
	*fd_lst = (t_list *)malloc(sizeof(t_list));
	if (!(*fd_lst))
		return (ERROR);
	set_fd_list(fd_lst, prev, fd);
	if (prev)
		prev->next = *fd_lst;
	else
		*head = *fd_lst;
	return (SUCCESS);
}
