/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2023/01/08 04:05:01 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char		**make_pp(char *s, char c, size_t cnt);
static void		free_all(char **pp, size_t cnt);
static size_t	cnt_word(char *str, char c);
static char		*make_p(char *s, char c);

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	k;

	if (start > ft_strlen(s))
	{
		temp = malloc(1);
		if (!temp)
			exit(1);
		*temp = '\0';
		return (temp);
	}
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