/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/28 21:31:17 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

static size_t	cnt_word(char *s, char c);
static char		*make_p(char *s, char c);
static char		**free_all(char **pp, size_t i);

char	**ft_split(char const *str, char c)
{
	char	**pp;
	char	*s;
	size_t	i;

	s = (char *)str;
	pp = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!pp)
		return (0);
	i = 0;
	while (i < cnt_word((char *)str, c))
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
		{
			pp[i] = make_p(s, c);
			if (!pp[i])
				return (free_all(pp, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	if (cnt_word(s, c))
		pp[0] = ft_strdup("");
	pp[i] = 0;
	return (pp);
}

static size_t	cnt_word(char *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (s[i - 1] && s[i - 1] == c)
		return (cnt - 1);
	return (cnt);
}

static char	*make_p(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static char	**free_all(char **pp, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(pp[j]);
		pp[j++] = 0;
	}
	free (pp);
	pp = 0;
	return (0);
}
