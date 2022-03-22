/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/22 16:25:05 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

static char	**make_pp(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**pp;

	**pp = make_pp(s, c);
	
	return (pp);
}

static char	**make_pp(char const *s, char c)
{
	char	**pp;
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;

	while (s[i])
	{
		if (!ft_strchr(s + i, c))
			cnt++;
		i++;
	}
	pp = (char **)malloc(sizeof(char *) * cnt);
	if (!pp)
		return (0);
	return (pp);
}
