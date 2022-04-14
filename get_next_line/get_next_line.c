/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/15 02:53:15 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	unsigned char	*str;
	int				len;

	str = (char *)malloc(BUFFER_SIZE);
	if (!str)
		return (0);
	len = read(fd, str, BUFFER_SIZE);
	if ((!chk_fd(&lst, fd) && len == 0) || len < 0 || fd < 0 || BUFFER_SIZE < 1)
	{
		free(str);
		return (0);
	}
	else if (chk_fd(&lst, fd) && len == 0)
		ft_strjoin(lst->content, str);
	else if (lst)
	{
		if (len == 0)
			return (free_lst(&lst));
		else
			add_lst(&lst, new_lst(&lst, str, fd));
	}
	else
		new_lst(&lst, str, fd);
	return (return_str(&lst));
}

int	chk_fd(t_list **lst, int fd)
{
	t_list	*temp;

	temp = *lst;
	while ((*lst)->fd != fd)
	{
		if ((*lst)->next == temp)
			return (0);
		(*lst) = (*lst)->next;
	}
	return (1);
}