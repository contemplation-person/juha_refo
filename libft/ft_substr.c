/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:49:47 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 17:17:41 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!s)
		return (0);
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (0);
	if (start >= len)
	{
		temp[0] = '\0';
		return (temp);
	}
	i = start;
	j = 0;
	while (j < len)
		temp[j++] = (char)s[i++];
	temp[j] = '\0';
	return (temp);
}
