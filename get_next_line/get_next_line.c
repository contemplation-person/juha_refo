/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/12 15:54:28 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*start_l;
	unsigned char	*str;
	int				len;

	len = read(fd, str, BUFFER_SIZE);
	if (len <= 0)
		return (0);
	else if (!start_l)
	{
		start_l = ft_lstnew(str, fd);
		start_l->content = str;
	}
	else
	{
		if (check_fd(start_l, fd))
		{
			
		}
		else
			ft_lstadd(&start_l, ft_lstnew(str, fd));
	}
	return (str);
}