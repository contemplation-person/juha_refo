/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:48:37 by seongyle          #+#    #+#             */
/*   Updated: 2022/04/21 17:27:50 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*ret_line;
	t_list			*temp;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (!set_line(&head, fd))
		return (free_all(&head, fd));
	if (head->fd == fd)
	{
		ret_line = head->line;
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	else
	{
		temp = head;
		while (temp->fd != fd)
			temp = temp->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		ret_line = temp->line;
		free(temp);
	}
	return (ret_line);
/*
	static t_list	*head;
	char			*ret_line;
	t_list			**temp;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (!set_line(&head, fd))
		return (free_all(&head, fd));

	temp = &head;
	t_list *ttemp;

	while ((*temp)->fd != fd) 
		temp = &(*temp)->next;
	ret_line = (*temp)->line;
	ttemp = (*temp)->next;

	free(*temp);
	*temp = ttemp;
	return 
*/
}

int	free_all(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*next_temp;

	temp = *head;
	while (temp)
	{
		next_temp = temp->next;
		if (temp->fd == fd)
		{
			next_temp->prev = temp->prev;
			temp->prev->next = next_temp;
			free(temp);
		}
		temp = next_temp;
	}
	return (0);
}

char	*get_line(t_list **head, int fd, char **buffer, int *buffer_len)
{
	char	*put_str;
	int		put_strlen;
	int		i;	
	char	*temp;

	temp = 0;
	i = -1;
	put_strlen = ft_strlen(*buffer, '\n');
	if (0 < count_node(*buffer, *buffer_len))
	{
		put_str = (char *)malloc(put_strlen + 2);
		temp = (char *)malloc(buffer_len);
		if (!put_str || !temp)
			return (free_all(head, fd));
		while (++i < buffer_len)
		{				
			if (i < put_strlen + 1)
				put_str[i] = (*buffer)[i];
			else
				temp[i] = (*buffer)[i];
		}
		put_str[++i] = '\0';
		free (*buffer);
		*buffer = temp;
		buffer_len = buffer_len - put_strlen;
	}
	return (put_str);
}

char	*set_line(t_list **head, int fd)
{
	ssize_t	read_len;
	ssize_t	i;
	ssize_t	buffer_len;
	char	*buffer;
	t_list	*temp;

	i = 0;
	read_len = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len < 0)
			return (free_all(head, fd));
/*
		 if (read_len == 0)
		{
			return (check_buffer(head, fd));
		}
*/
		if (read_len == 0)
		{
			free(buffer);
			break ;
		}
		buffer[read_len] = '\0';
		buffer_len = read_len + 1;
		temp = head;
		i = 0;
		while (i < count_node(buffer, read_len))
		{
/*
				fd_node가  \n이 없는 경우, 문자열 붙여주기.
				그 끝의 fd_node->line in \n true next false 
*/
			while (temp->fd != fd)
				temp = temp->next;
			while (temp->fd == fd && temp->next->fd != fd)
				temp = temp->next;
			if (!count_node(temp->line, &buffer_len))
			{
			
			}
			else if (!add_node(head, create_node(fd, get_line(head, fd, &buffer, &buffer_len),buffer_len), fd))
				return (free_all(head, fd));
			i++;
		}
		if (ft_strlen(buffer, '\n') < read_len + 1)
			break ;
	}
	return ((*head)->line);
}

int	add_node(t_list **head, t_list *new, int fd)
{
	t_list	*temp;

	temp = *head;
	if (!head || !new || fd < 0)
		return (0);
	while (temp->fd != fd)
		temp = temp->next;
	while (temp->fd == fd && temp->next->fd != fd)
		temp = temp->next;
	new->next = temp->next;
	new->prev = temp;
	temp->next = new;
	return (1);
}

size_t	count_node(char *str, size_t read_len)
{
	size_t	cnt;
	size_t	idx;
	char	*check;

	cnt = 0;
	idx = 0;
	if (read_len <= 0)
		return (0);
	while (idx < read_len)
	{
		if (str[idx] == '\n')
			cnt++;
		check = &str[idx - 1];
		idx++;
	}
	if (cnt > 0 && *check != '\n')
		cnt++;
	return (cnt);
}
