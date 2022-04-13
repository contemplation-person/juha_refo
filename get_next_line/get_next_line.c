/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/13 19:53:27 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/*
char	*get_next_line(int fd)
{
	static t_list	*start_l;
	unsigned char	*str;
	int				len;

	len = read(fd, str, BUFFER_SIZE);
	if (len <= 0)
		return (0);
	else if (start_l)
	{
		if (check_fd(&start_l, fd))
		{
			if (check_line(start_l))
				return (cut_line(start_l));
		}
		else
			ft_lstadd(&start_l, ft_lstnew(str, fd));
	}
	else
	{
		start_l = ft_lstnew(str, fd);
		if (!start_l)
			return (0);
	}
	start_l->content = ft_strjoin(start_l->content, str);
	return (cut_line(start_l));
}
*/

char	*get_next_line(int fd)
{
	static t_list	*start_l;
	unsigned char	*str;
	int				len;

	len = read(fd, str, BUFFER_SIZE);
	if ((!start_l && len == 0) || len < 0)
		return (0);
	else if (start_l)
	{
		if (!check_fd(&start_l, fd, str, len))
			ft_lstadd(&start_l, ft_lstnew(str, fd));
	}
	else
	{
		if (len != 0)
			start_l = ft_lstnew(str, fd);
	}
	return (cut_line(start_l));
}

/*
	check_fd
	check_line
	cut_line -> free_list;
*/
