/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/22 22:25:13 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd);
ssize_t	all_free(t_list	**head, ssize_t fd, char *str);
t_list	*chk_lst(t_list *head, ssize_t fd);
char	*ret_line(t_list **head, ssize_t fd);

char	*get_next_line(int fd)
{
	static t_list	*head;
	ssize_t			read_len;
	char			*str;

	str = (char *)malloc(BUFFER_SIZE);
	if (!str || fd < 0 || BUFFER_SIZE < 0)
		return (all_free(&head, fd, str));
	read_len = read(fd, str, BUFFER_SIZE);
	if (read_len < 0)
		return (all_free(&head, fd, str));
	else if (read_len != 0)
	{
		new_lst(&head, fd, str, read_len);
	}
	return (ret_line(&head, fd));
}

char	*ret_line(t_list **head, ssize_t fd)
{
	t_list	*fd_lst;
	char	*line;


	fd_lst = chk_lst(*head, fd);
	
	if (!fd_lst)
		return (0);
	else
	{
		
	}
	
/* 
	fd_lst가 있으면 리스트의 str을 \n까지 반환 strInfo값을 바꿔줌, 
	개행이 없으면 전체 반환 (전체 반환시(커서로 확인) 구조체 free)
*/;
}

t_list	*chk_lst(t_list *head, ssize_t fd)
{
	t_list	*ret;

	ret = head;
	while (ret && ret->fd != fd)
		ret->next_fd_lst;
	return (ret);
}
