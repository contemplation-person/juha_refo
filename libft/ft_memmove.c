/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 22:51:43 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, unsigned int count)
{
	unsigned char	*temp;
	unsigned int	cnt;

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
