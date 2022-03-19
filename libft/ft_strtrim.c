/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/19 16:20:56 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static size_t	ft_trim_front(char const *s1, char const *set);
static size_t	ft_trim_tail(char const *s1, char const *set, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx[2];
	size_t	i;
	char	*temp;
	size_t	j;

	if (!s1)
		return (0);
	idx[0] = ft_trim_front(s1, set);
	if (idx[0] == sizeof(s1))
		return ("");
	idx[1] = ft_trim_tail(s1, set, sizeof(s1));
	i = idx[0];
	temp = (char *)malloc(idx[1] - idx[0] + 1);
	if (!temp)
		return (0);
	j = 0;
	while (i < idx[1])
		temp[j++] = s1[i++];
	temp[j] = '\0';
	return (temp);
}

static size_t	ft_trim_front(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		flag;

	flag = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (ft_strchr(s1, set[j]))
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		flag = 0;
		i++;
	}
	return (i);
}

static size_t	ft_trim_tail(char const *s1, char const *set, size_t len)
{
	size_t	i;
	size_t	j;
	int		flag;

	flag = 0;
	i = len;
	while (s1[--i])
	{
		j = 0;
		while (set[j])
		{
			if (ft_strchr(set, s1[i]))
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		flag = 0;
	}
	return (i);
}
