/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 18:45:25 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t ft_strlen(const char *s, unsigned char target_char)
{
	size_t i;

	i = 0;
	while (s && s[i] && target_char != s[i])
		i++;
	return (i);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
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

static int str_join(char **dst, int dst_len, char *src, int src_len)
{
	char *sum_buf;
	int sum_len;

	if (!dst_len && !src_len)
		return 0;
	sum_len = dst_len + src_len;
	sum_buf = malloc(sum_len + 1);
	if (!sum_buf)
		return (-1);
	ft_memcpy(sum_buf, *dst, dst_len);
	ft_memcpy(&sum_buf[dst_len], src, src_len);
	sum_buf[sum_len] = '\0';
	free(*dst);
	*dst = sum_buf;
	return sum_len;
}

static char *pass_one_line(t_gnl *gnl, int fd_index)
{
	char *ret_str;
	char *save_str;
	int line_len;
	int len;
	
	ret_str = NULL;
	save_str = NULL;
	line_len = ft_strlen(gnl[fd_index].rb, '\n');
	if (line_len++ != gnl[fd_index].rb_capacity)
	{
		len = str_join(&ret_str, 0, gnl[fd_index].rb, line_len);
		if (len == -1)
			return (NULL);
		len = str_join(&save_str, 0, &gnl[fd_index].rb[line_len], gnl[fd_index].rb_capacity - len);
		if (len == -1)
		{
			free(ret_str);
			free(save_str);
			len = 0;
			return (NULL);
		}
		free(gnl[fd_index].rb);
	}
	else
	{
		ret_str = gnl[fd_index].rb;
		save_str = NULL;
		len = 0;
	}
	gnl[fd_index].rb = save_str;
	gnl[fd_index].rb_capacity = len;
	return (ret_str);
}

char *get_next_line(int fd)
{
	static t_gnl gnl[OPEN_MAX];
	char tmp_str[BUFFER_SIZE + 1];
	int fd_index = fd - 1;
	int read_len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_len = read(fd, tmp_str, BUFFER_SIZE);
	while (read_len > 0)
	{
		tmp_str[read_len] = '\0';
		read_len = str_join(&gnl[fd_index].rb, gnl[fd_index].rb_capacity, tmp_str, ft_strlen(tmp_str, '\0'));
		if (read_len == -1)
		{
			free(gnl[fd_index].rb);
			gnl[fd_index].rb = NULL;
			gnl[fd_index].rb_capacity = 0;
			return (NULL);
		}
		gnl[fd_index].rb_capacity = read_len;
		read_len = read(fd, tmp_str, BUFFER_SIZE);
	}
	return (pass_one_line(gnl, fd_index));
}