/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:13:11 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 23:58:33 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*convt;
	size_t			cnt;

	convt = (unsigned char *)s;
	cnt = 0;
	while (cnt < n)
	{
		if ((unsigned char) c == convt[cnt])
			return (convt + cnt);
		cnt++;
	}
	return (0);
}
