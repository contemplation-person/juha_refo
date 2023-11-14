/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/05/12 21:40:46 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t ft_strlen(const char *s, unsigned char target_char)
{
	ssize_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && target_char != s[i])
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

int str_join(t_gnl *gnl, int gnl_fd, char *tmp_str)
{
	char *sum_buf;
	int sum_len;
	int	tmp_len;
	
	tmp_len = ft_strlen(tmp_str, '\0');
	sum_len = tmp_len + gnl[gnl_fd].rb_capacity;
	sum_buf = malloc(sum_len + 1);
	if (!sum_buf)
		return (-1);
	ft_memcpy(sum_buf, gnl[gnl_fd].rb, gnl[gnl_fd].rb_capacity);
	ft_memcpy(sum_buf[gnl[gnl_fd].rb_capacity], tmp_str, tmp_len);
	sum_buf[sum_len] = '\0';
	free(gnl[gnl_fd].rb);
	gnl[gnl_fd].rb = sum_buf;
	gnl[gnl_fd].rb_capacity = sum_len;
	return sum_len;
}

char *get_next_line(int fd)
{
	static t_gnl gnl[OPEN_MAX];
	char tmp_str[BUFFER_SIZE];
	int gnl_fd = fd - 1;
	int read_len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_len = read(fd, tmp_str, BUFFER_SIZE - 1);
	while (read_len > 0)
	{
		tmp_str[read_len] = '\0';
		str_join(gnl, gnl_fd, tmp_str);
		read_len = read(fd, tmp_str, BUFFER_SIZE);
	}
	// line
	return ();
}