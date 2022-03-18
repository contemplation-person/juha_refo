/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:21:11 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 23:01:18 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_temp1;
	unsigned char	*s_temp2;
	size_t			i;

	s_temp1 = (unsigned char *)s1;
	s_temp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s_temp1[i] != s_temp2[i])
			return (s_temp1[i] - s_temp2[i]);
		i++;
	}
	return (0);
}
