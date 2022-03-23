/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/24 00:08:08 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

static size_t	cnt_word(char const *s, char c);
static char		**make_pp(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**pp;
	ssize_t	i;
	size_t	front;
	size_t	tail;

	if (!s)
		return (0);
	pp = make_pp(s, c);
	i = -1;
	front = 0;
	while (pp && ++i < (ssize_t)cnt_word(s, c))
	{
		front = tail;
		while (s[tail] == c)
			tail++;
		pp[i] = ft_substr(s, front, tail);
		if (!pp[i])
			break ;
	}
	if (pp && !pp[i])
	{
		while (-1 < i)
		{
			free(pp[i]);
			pp[i--] = 0;
		}
		free(pp);
		pp = 0;
	}
	return (pp);
}

static size_t	cnt_word(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	return (cnt + 1);
}

static char	**make_pp(char const *s, char c)
{
	char	**pp;

	pp = (char **)malloc(sizeof(char *) * cnt_word(s, c));
	if (!pp)
		return (0);
	return (pp);
}
