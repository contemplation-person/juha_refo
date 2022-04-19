/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:35 by juha              #+#    #+#             */
/*   Updated: 2022/04/19 18:19:54 by juha             ###   ########seoul.kr  */
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
	((char *)(new->content))[BUFFER_SIZE + 1] = '\0';
	if (new)
		return (0);
	read_len = read(fd, new->content, BUFFER_SIZE);
	ft_lstadd_back(&lst, new);
	if (read_len == BUFFER_SIZE)
		return (cut_until_null(&lst, fd));
	else if (BUFFER_SIZE > read_len && read_len >= 0)
	{
		if (!check_fd(lst, fd))/* lst부터 fd가 있는지 확인 */
			return (0);
		return (cut_until_null(&lst, fd));
	}
	else
		ft_lstclear(&lst, fd);
	return (0);
}

char	*cut_until_null(t_list **lst, int fd)
{
	char	*put_str;
	char	*save;
	t_list	*temp;
	int		null_idx;

	while (check_fd(temp, fd))
	{
		put_str = (*lst)->content;
		null_idx = ft_strlen(put_str, '\n');
		
	}


/*	
	if (is_last_lst(lst, fd))
	{
		ft_lstclear (&lst, fd);
		return (put_str);
	}
	else if (is_line(put_str))
	{
		save = ft_substr((const char *)put_str, null_idx + 1, ft_strlen(put_str, 0));
		if (!save)
		{
			ft_lstclear(lst, fd);
			return (0);
		}
		put_str = ft_substr((const char *)put_str, 0, null_idx + 1);
		free((*lst)->content);
		(*lst)->content = save;
		if (is_null(put_str))
			return (put_str);
	}
*/
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	k;

	if (start > ft_strlen(s, 0))
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