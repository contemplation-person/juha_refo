/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 01:00:59 by conteng          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ret_str(t_list **fd_lst)
{
	char	*ret;
	char	*save;
	size_t	ret_len;

	ret_len = 0;
	while (ret_len < (*fd_lst)->buf_len)
	{
		if ((*fd_lst)->buf[ret_len++] == '\n')
			break ;
	}
	ret = (char *)malloc(ret_len + 1);
	if (!ret)
		return (ERROR);
/*ret 복사 + 끝에 \0*/
	if ((*fd_lst)->buf_len - ret_len)
	{
		save = (char *)malloc((*fd_lst)->buf_len - ret_len);
		if (!save)
		{
			free(ret);
			return (ERROR);
		}
		/*save 복사 (*fd_list)->buf = save & (*fd_lst)->buf_len 넣기*/
	}
	else
		free_lst(fd_lst);
	return (ret);
}
