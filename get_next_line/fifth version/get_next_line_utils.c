/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:16:46 by juha              #+#    #+#             */
/*   Updated: 2022/04/25 15:25:37 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(const char *s, ssize_t end);
char	*all_free(t_list	**head, ssize_t fd, char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		new_lst(t_list **head, ssize_t fd, char **str, ssize_t read_len);

ssize_t	ft_strlen(const char *s, ssize_t end)
{
	ssize_t	i;

	i = 0;
	while (i != end)
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

void	gnl_free(void *data)
{
	free(data);
	data = NULL;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp		/*존재하지 않는데 read_len == 0이 아님.*/;
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

int	new_lst(t_list **head, ssize_t fd, char **str, ssize_t read_len)
{
	t_list	*fd_lst;
	t_list	*prev_fd_lst;
	char	*temp;
	ssize_t	end;

	fd_lst = chk_lst(head, fd);
	if (fd_lst)
	{
		temp = fd_lst->str_info->buffer;
		end = fd_lst->str_info->end;
		fd_lst = (t_list *)malloc(sizeof(t_list));
		if (!fd_lst)
			return (0);
		fd_lst->str_info->buffer = (char *)malloc(end + read_len);
		if (!fd_lst->str_info->buffer)
		{
			
			all_free(head, fd, str);
			return (0);
		}
		ft_memcpy(fd_lst->str_info->buffer, temp, end);
		ft_memcpy(fd_lst->str_info->buffer + end, *str, read_len);//확인 필요.
		fd_lst->str_info->end = end + read_len;
	}
	else if (read_len != 0)
	{
		/*존재하지 않는데 read_len == 0이 아님.*/
		prev_fd_lst = *head;
		while (prev_fd_lst && (prev_fd_lst->next_fd_lst == fd_lst))
			prev_fd_lst = prev_fd_lst->next_fd_lst;
		fd_lst = (t_list *)malloc(sizeof(t_list));
		if (!fd_lst)
			all_free(head, fd, str);
		fd_lst->str_info = (t_str *)malloc(sizeof(t_str));
		if (!fd_lst->str_info)
			all_free(head, fd, str);
		fd_lst->str_info->buffer = *str;
		fd_lst->fd = fd;
		fd_lst->str_info->end = read_len;
		if (prev_fd_lst)
			prev_fd_lst->next_fd_lst = fd_lst;
		else
			*head = fd_lst;
	}
}
