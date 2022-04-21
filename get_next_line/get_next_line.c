/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/22 00:47:17 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd);
int		all_free(t_list	**head, int fd, char *str);
t_list	*check_lst(t_list *head, int fd);

char	*get_next_line(int fd)
{
	static t_list	*head;
	ssize_t			read_len;
	char			*str;

	str = (char *)malloc(BUFFER_SIZE);
	if (!str)
		return (all_free(&head, fd, str));
	read_len = read(fd, str, BUFFER_SIZE);
	if (0 > read_len || 0 > BUFFER_SIZE)
		return (all_free(&head, fd, str));
	if (0 == read_len)
	{
		if (check_lst(head, fd))
		{
			str = (check_lst(head, fd))->str_info->str;
			return (str);
		}
		return (all_free(&head, fd, str));
	}
	else
	{
		return (ret_line(&head, fd, str, read_len));
	}
}

ret_line(t_list **head, int fd, char *str, int read_len)
{
	t_list	*find_lst;
	char	*ret_str;
	int		i;
	int		j;
/*커서로 있는지 없는지 체크*/
	j = 0;
	i = 0;
	find_lst = *head;
	while (find_lst->fd == fd)
		find_lst->next_fd;
	ret_str = (char *)malloc(ft_strlen(str, '\n') + 1);
	if (!ret_str)
		all_free(head, fd, str);
	if (!find_lst)
	{
		while (i < ft_strlen(str, '\n') + 1)
		{
			ret_str[i] = str[i];
			i++;
		}
		ret_str[i] = '\0';
		find_lst = make_lst(*head, fd);
		find_lst->str_info->str = (char *)malloc(read_len - ft_strlen(str, '\n') + 1);
		if (!find_lst->str_info->str)
		{
			all_free(head, fd, str);
			free(ret_str);
		}
		while (i < read_len)
			find_lst->str_info->str[j++] = str[i++];
		find_lst->str_info->str[j++] = '\0';
		find_lst->str_info->cnt_line = check_line()/*line이 있으면 n없으면 null*/
		free(str);
	}
	else/*t리스트가 존재 */
	{
		/*line이 있는지 체크*/
	}
	return (ret_line);
}

/* make node, 개행까지 반환 및 str을 조인 // 개행을 끝까지 반환했으면 free all*/

t_list	*check_lst(t_list *head, int fd)
{
	t_list	*ret;

	ret = head;
	while (ret->fd == fd)
		ret->next_fd;
	return (ret);
}

int	all_free(t_list	**head, int fd, char *str)
{
	t_list	*prev_del_lst;
	t_list	*del_lst;

	prev_del_lst = *head;
	del_lst = 0;
	*head = (*head)->next_fd;
	if (str)
		free(str);
	if (prev_del_lst)
	{
		while (prev_del_lst->next_fd->fd == fd)
			prev_del_lst->next_fd;
		del_lst = prev_del_lst->next_fd;
		prev_del_lst->next_fd = del_lst->next_fd;
		free(del_lst->str_info->str);
		free(del_lst->str_info);
		free(del_lst);
	}
	return (0);
}
