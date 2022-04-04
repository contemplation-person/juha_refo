/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/04/04 13:00:02 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**make_pp(char *s, char c, size_t cnt);
static void		free_all(char **pp, size_t cnt);
static size_t	cnt_word(char *str, char c);
static char		*make_p(char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**pp;
	char	*str;

	str = (char *)s;
	while (*str && *str == c)
		str++;
	pp = make_pp(str, c, cnt_word(str, c));
	return (pp);
}

static size_t	cnt_word(char *str, char c)
{
	char	*s;
	size_t	cnt;

	s = str;
	cnt = 0;
	while (*str && *str == c)
		str++;
	while (*s)
	{
		cnt++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (cnt);
}

static char	*make_p(char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] && s[cnt] != c)
		cnt++;
	return (ft_substr(s, 0, cnt));
}

static void	free_all(char **pp, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(pp[i]);
		pp[i++] = 0;
	}
	free(pp);
}

static char	**make_pp(char *s, char c, size_t cnt)
{
	size_t	i;
	char	**pp;

	pp = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!pp)
		return (0);
	i = 0;
	while (i < cnt)
	{
		pp[i] = make_p(s, c);
		if (pp[i] == 0)
		{
			free_all(pp, i);
			pp = 0;
			return (0);
		}
		i++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	pp[i] = 0;
	return (pp);
}
