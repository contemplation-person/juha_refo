/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/21 20:06:55 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

char	**ft_split(char const *s, char c)
{
	char	**pp;
	size_t	cnt;

	cnt = ft_cnt_word(s, c);
	**pp = 0;
	return (pp);
}

static size_t	ft_cnt_word(char const *s, char c)
{
	size_t	cnt;
	ssize_t	i;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		while (s[i] != c)
			++i;
		if (s[i] != '\0')
			cnt++;
	}
	return (cnt);
}


static char	**make_pp(size_t cnt)
{
	char	**pp;

	pp = (char **)malloc(sizeof(char *) * cnt);
	if (!pp)
		return (0);
	return (pp);
}
