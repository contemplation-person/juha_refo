/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 11:49:42 by conteng          ###   ########seoul.kr  */
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
		return (free_lst(fd_lst));
	ft_memcpy(ret, (*fd_lst)->buf, ret_len);
	ret[ret_len] = '\0';
	if ((*fd_lst)->buf_len - ret_len)
	{
		save = (char *)malloc((*fd_lst)->buf_len - ret_len);
		if (!save)
		{
			free(ret);
			return (free_lst(fd_lst));
		}
		ft_memcpy(save, (*fd_lst)->buf[ret_len], (*fd_lst)->buf_len - ret_len);
		free((*fd_lst)->buf);
		(*fd_lst)->buf = save;
		(*fd_lst)->buf_len = (*fd_lst)->buf_len - ret_len;
	}
	else
		free_lst(fd_lst);
	return (ret);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;
	size_t			cnt;

	temp = (unsigned char *)src;
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = temp[cnt];
		cnt++;
	}
	return (dst);
}