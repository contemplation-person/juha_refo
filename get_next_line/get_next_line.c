/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/14 16:47:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_substr(char const *s, size_t start, size_t len);
char	*cut_line(t_list *start_l, int len);
t_list	*check_fd(t_list **start_l, int fd);
void	free_node(t_list **removal);

char	*get_next_line(int fd)
{
	static t_list	*start_l;
	unsigned char	*str;
	int				len;

	str = 0;
	len = read(fd, str, BUFFER_SIZE);
	if ((!start_l && len == 0) || len < 0)
		return (0);
	else if (start_l)
	{
		if (!check_fd(&start_l, fd))
			ft_lstadd(&start_l, ft_lstnew(str, fd));
	}
	else
	{
		if (len != 0)
			start_l = ft_lstnew(str, fd);
	}
	return (cut_line(start_l, len));
}

t_list	*check_fd(t_list **start_l, int fd)
{
	t_list	*temp;

	temp = *start_l;
	while ((*start_l)->next == temp)
	{
		if ((*start_l)->fd == fd)
			return (*start_l);
		start_l = &((*start_l)->next);
	}
	return (0);
}

char	*cut_line(t_list *start_l, int len)
{
	char	*str;
	char	*temp;
	int		line;
	int		end_of_str;

	end_of_str = ft_strlen(start_l->content, &line);
	if (len == 0)
	{
		str = ft_substr(start_l->content, len, end_of_str);
		free_node(&start_l);
	}
	else if (end_of_str != line)
	{
		str = ft_substr(start_l->content, 0, line);
		temp = ft_substr(start_l->content, line + 1, end_of_str);
		free(start_l->content);
		start_l->content = temp;
	}
	else
	{
		str = start_l->content;
		free_node(&start_l);
	}
	return (str);
}

void	free_node(t_list **removal)
{
	t_list	*temp;

	if ((*removal)->next == (*removal))
	{
		free((*removal)->content);
		(*removal)->content = 0;
		free(*removal);
		*removal = 0;
	}
	else
	{
		temp = *removal;
		while (temp->next == *removal)
			temp = temp->next;
		temp->next = (*removal)->next;
		free((*removal)->content);
		free(*removal);
		*removal = temp;
	}
}
