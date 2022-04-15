/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/15 15:52:15 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int		chk_fd(t_list **lst, int fd);
char	*return_str(t_list **lst);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *s1);

char	*get_next_line(int fd)
{
	static t_list	*lst;
	unsigned char	*str;
	int				len;

	str = (unsigned char *)malloc(BUFFER_SIZE);
	if (!str)
		return (0);
	len = read(fd, str, BUFFER_SIZE);
	if ((!chk_fd(&lst, fd) && len == 0) || len < 0 || fd < 0 || BUFFER_SIZE < 1)
	{
		free(str);
		return (0);
	}
	else if (chk_fd(&lst, fd) && len == 0)
		ft_strjoin(&lst, str);
	else if (lst)
	{
		if (len == 0)
			return (free_lst(&lst));
		else
			ft_lstadd(&lst, ft_lstnew(str, fd));
	}
	else
		lst = ft_lstnew(str, fd);
	return (return_str(&lst));
}

int	chk_fd(t_list **lst, int fd)
{
	t_list	*temp;

	temp = *lst;
	if (!temp)
		return (0);
	while ((*lst)->fd != fd)
	{
		if ((*lst)->next == temp)
			return (0);
		(*lst) = (*lst)->next;
	}
	return (1);
}

char	*return_str(t_list **lst)
{
	char	*str;
	int		line;
	char	*temp;
	int		len;

	str = (*lst)->content;
	len = 0;
	line = 0;
	while (str[len])
	{
		if (str[len] == '\n')
		{
			line = len;
			break ;
		}
		len++;
	}
	while (str[len])
		len++;
	if (len == 0 || len - 1 == line)
		return (free_lst(lst));
	else
	{
		(*lst)->content = ft_substr(str, line, len);
		temp = ft_substr(str, 0, line);
		free(str);
		return (temp);
	}
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	k;

	if (start > ft_strlen((unsigned char *) s))
		return (ft_strdup(""));
	k = 0;
	while (s[start + k])
		k++;
	if (len > k)
		len = k;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	i = start;
	j = 0;
	while (j < len)
		temp[j++] = (char)s[i++];
	temp[j] = '\0';
	return (temp);
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	temp = (char *)malloc(i + 1);
	if (!temp)
		return (0);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
