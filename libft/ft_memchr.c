/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:13:11 by juha              #+#    #+#             */
/*   Updated: 2022/03/15 17:28:51 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
