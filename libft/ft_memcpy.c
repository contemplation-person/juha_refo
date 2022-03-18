/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 17:16:33 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;
	size_t			cnt;

	if (!dst && !src)
		return (0);
	temp = (unsigned char *)src;
	cnt = 0;
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = temp[cnt];
		cnt++;
	}
	return (dst);
}
