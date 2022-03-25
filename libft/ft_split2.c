/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/25 13:14:33 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <stdio.h>

static size_t	cnt_word(char const *s, char c);
static char		**make_pp(char const *s, char c);
static char		*make_p(char const *s, char c, size_t cnt_tok);

char	**ft_split(char const *s, char c)
{
	char	**pp;
	size_t	i;

	if (!s)
		return (0);
	pp = make_pp(s, c);
	i = 0;
	while (pp && i++ < cnt_word(s, c))
	{
		pp[i] = make_p(s, c, i);
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
		while (s[i] && s[i] == c)
			i++;
		cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}
/*
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

 방식 1::
while (s[i])
{
	while (sep)
		i++;
	temp = i;
	while (s[i] && !sep)
		i++;
	i != temp
		make_p // substr
	if (!p)
		return (free_all)
}
*/

static char	*make_p(char const *s, char c, size_t cnt_tok)
{
	size_t	front;
	size_t	tail;
	size_t	cnt;

	tail = 0;
	cnt = 0;
	while (cnt <= cnt_tok)
	{
		front = tail;
		while (s[tail] != c && cnt <= cnt_tok)
			tail++;
		tail++;
		cnt++;
	}
	return (ft_substr(s, front, tail));
}

static char	**make_pp(char const *s, char c)
{
	char	**pp;

	pp = (char **)malloc(sizeof(char *) * cnt_word(s, c));
	if (!pp)
		return (0);
	return (pp);
}
