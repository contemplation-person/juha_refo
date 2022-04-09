/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/09 19:30:20 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_list	*start_l;
	unsigned char	*str;
	int				check_zero;

	if (start_l)
		start_l->fd;
	
	read(fd, str, BUFFER_SIZE);
	save_line(start_l, str);
	return (str);
}

char	*save_line(t_list *start, unsigned char *str)
{
	int				check;
	unsigned char	*cutting_str;

	while (str != '\n' || str > -1)
	{
		
	}
}
