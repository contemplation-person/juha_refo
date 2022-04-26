/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/26 13:56:51 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd);
t_list	*chk_lst(t_list **head, ssize_t fd);
char	*ret_line(t_list **head, ssize_t fd, char **str);

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*read_str;
	ssize_t			read_len;
	t_list			*fd_lst;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	read_str= (char *)malloc(BUFFER_SIZE);
	fd_lst = check_fd(head);
	if (!read_str)
	{
		if (fd_lst)
			/*fd안의 모든 값을 free*/
		return (0);
	}
	read_len = read(fd, read_str, BUFFER_SIZE);
	else if(read_len != 0)
		new_lst(&head, fd, &read_str, read_len);
	else if (read_len < 0)
	{
		if (check_fd(&head, fd))
			/* if (check_fd) free(check_fd)모든 값을 free*/;
	}
	free (read_str);
	return (ret_line(&head, fd));
}

char	*ret_line(t_list **head, ssize_t fd, char **str)
{
	t_list	*fd_lst;
	ssize_t	ret_len;
	char	*ret_line;
	char	*save_str;

	fd_lst = chk_lst(head, fd);
	if (!fd_lst)
		return (all_free(head, fd, str));
	ret_len = ft_strlen(fd_lst->str_info->buffer, fd_lst->str_info->end);
	ret_line = (char *)malloc(ret_len + 1);
	if (!ret_line)
		return (all_free(head, fd, str));
	ret_line[ret_len] = '\0';
	save_str = (char *)malloc(fd_lst->str_info->end - ret_len);
	if (!save_str)
		return (all_free(head, fd, str));
	ft_memcpy(ret_line, fd_lst->str_info->buffer, ret_len);//확인필요.
	ft_memcpy(save_str, fd_lst->str_info->buffer + ret_len, fd_lst->str_info->end - ret_len);
	char *backup = fd_lst->str_info->buffer;
	fd_lst->str_info->buffer = save_str;
	fd_lst->str_info->end = fd_lst->str_info->end - ret_len;
	if (fd_lst->str_info->end <= 0)
	{
		//free(save_str);
		all_free(head, fd, str);
	}
	else
	{
		free(backup);
	}
	

	return (save_str);
/* 
	fd_lst가 있으면 리스트의 str을 \n까지 반환 strInfo값을 바꿔줌, 
	개행이 없으면 전체 반환 (전체 반환시(커서로 확인) 구조체 free)
*/
}

t_list	*chk_lst(t_list **head, ssize_t fd)
{
	t_list	*ret;

	ret = *head;
	while (ret && ret->fd != fd)
		ret = ret->next_fd_lst;
	return (ret);
}
