/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/23 01:21:55 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd);
ssize_t	all_free(t_list	**head, ssize_t fd, char **str);
t_list	*chk_lst(t_list *head, ssize_t fd);
char	*ret_line(t_list **head, ssize_t fd);

char	*get_next_line(int fd)
{
	static t_list	*head;
	ssize_t			read_len;
	char			*str;

	str = (char *)malloc(BUFFER_SIZE);
	if (!str || fd < 0 || BUFFER_SIZE < 0)
		return (all_free(&head, fd, &str));
	read_len = read(fd, str, BUFFER_SIZE);
	if (read_len < 0)
		return (all_free(&head, fd, &str));
	else if (read_len != 0)
	{
		new_lst(&head, fd, &str, read_len);
	}
	return (ret_line(&head, fd, &str));
}

char	*ret_line(t_list **head, ssize_t fd, char **str)
{
	t_list	*fd_lst;
	ssize_t	ret_len;
	char	*ret_line;
	char	*save_str;

	fd_lst = chk_lst(*head, fd);
	if (!fd_lst)
		retrun (all_free(head, fd, str));
	ret_len = ft_strlen(fd_lst->str_info->buffer, 0, fd_lst->str_info->end);
	ret_line = (char *)malloc(ret_len + 1);
	if (!ret_len)
	{
		free(fd_lst);
		return (all_free(head, fd, str));
	}
	ret_line[ret_len] = '\0';
	save_str = (char *)malloc(fd_lst->str_info->end - ret_len);
	if (!save_str)
	{
		free(ret_line);
		free(fd_lst);
		return (all_free(head, fd, str));
	}
	ft_memcpy(ret_line, fd_lst->str_info->buffer, ret_len);//확인필요.
	ft_memcpy(save_str, fd_lst->str_info->buffer + ret_len, end - ret_len);
	free(fd_lst->str_info->buffer);
	fd_lst->str_info->buffer = save_str;
	fd_lst->str_info->end = end - ret_len;
	if (fd_lst->str_info->end <= 0)
		all_free(head, fd, str);
	return (save_str);
/* 
	fd_lst가 있으면 리스트의 str을 \n까지 반환 strInfo값을 바꿔줌, 
	개행이 없으면 전체 반환 (전체 반환시(커서로 확인) 구조체 free)
*/
}

t_list	*chk_lst(t_list *head, ssize_t fd)
{
	t_list	*ret;

	ret = head;
	while (ret && ret->fd != fd)
		ret->next_fd_lst;
	return (ret);
}
