/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/23 01:21:57 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(const char *s, ssize_t start, ssize_t end);
ssize_t	all_free(t_list	**head, ssize_t fd, char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

ssize_t	ft_strlen(const char *s, ssize_t start, ssize_t end)
{
	ssize_t	i;

	i = 0;
	while (start != end && s[i] != '\n')
		i++;
	return (i);
}

ssize_t	all_free(t_list	**head, ssize_t fd, char **str)
{
	t_list	*prev_del_lst;
	t_list	*del_lst;

	del_lst = *head;
	prev_del_lst = del_lst;
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	if (*head)
	{	
		while (del_lst && del_lst->fd == fd)
		{
			prev_del_lst = del_lst;
			del_lst = del_lst->next_fd_lst;
		}
		if ((*head)->fd == del_lst->fd)
			*head = (*head)->next_fd_lst;
		prev_del_lst->next_fd_lst = del_lst->next_fd_lst;
		free(del_lst->str_info->buffer);
		free(del_lst->str_info);
		free(del_lst);
	}
	return (0);
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

void	new_lst(t_list **head, ssize_t fd, char **str, ssize_t read_len)
{
	t_list	*fd_lst;
	t_list	*prev_fd_lst;
	char	*temp;
	ssize_t	end;

	fd_lst = chk_lst(head, fd);
	if (fd_lst)
	{
		temp = fd_lst->str_info->buffer;
		end = fd_lst->str_info->end;
		fd_lst = (t_list *)malloc(sizeof(t_list));
		if (!fd_lst)
			all_free(head, fd, str);
		fd_lst->str_info->buffer = (char *)malloc(end + read_len);
		if (!fd_lst->str_info->buffer)
		{
			free(fd_lst->str_info->buffer);
			all_free(head, fd, str);
		}
		ft_memcpy(fd_lst->str_info->buffer, temp, end);
		ft_memcpy(fd_lst->str_info->buffer + end, *str, read_len);//확인 필요.
		fd_lst->str_info->end = end + read_len;
	}
	else if (read_len != 0)
	{
		prev_fd_lst = *head;
		while (prev_fd_lst && (prev_fd_lst->next_fd_lst == fd_lst))
			prev_fd_lst->next_fd_lst;
		fd_lst = (t_list *)malloc(sizeof(t_list));
		if (!fd_lst)
			all_free(head, fd, str);
		fd_lst->str_info->buffer = *str;
		if (prev_fd_lst)
			prev_fd_lst->next_fd_lst = fd_lst;
		else
			*head = fd_lst;
	}
}
