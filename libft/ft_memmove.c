/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/21 20:06:53 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*temp;
	size_t			cnt;

	if (!dest && !src)
		return (0);
	temp = (unsigned char *)src;
	if (dest > src)
	{
		cnt = 0;
		while (cnt < count)
		{
			((unsigned char *)dest)[cnt] = temp[cnt];
			cnt++;
		}
	}
	else
	{
		cnt = count;
		while (0 < cnt)
		{
			cnt--;
			((unsigned char *)dest)[cnt] = temp[cnt];
		}
	}
	return (dest);
}
