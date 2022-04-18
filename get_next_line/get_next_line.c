/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/18 22:12:59 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	int				read_len;
	t_list			*new;

	if (BUFFER_SIZE <= 0)
		return (0);
	new = ft_lstnew((char *)malloc(BUFFER_SIZE + 1), fd);
	if (new)
		return (0);
	read_len = read(fd, new->content, BUFFER_SIZE);
	if (read_len == BUFFER_SIZE)
	{
		ft_lstadd_back(&lst, new);
		return (cut_null(&lst));
	}
	else if (BUFFER_SIZE > read_len && read_len >= 0)
	{
		join_buffer(&lst, fd);
		return (strjoin(freeall);
		
		/* 조인 및 반환 후 올 프리 
		그럼요? emptybuffer
		{
			char *str1;
			char *str2;
			while ()
		}
			return (0);
		*/
	}
	else
		ft_lstclear(&lst, fd); /* 올 프리 */
	return (0);
}
