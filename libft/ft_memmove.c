/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/22 14:35:28 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;
	size_t			i;	

	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	if (dest <= src)
		ft_memcpy(temp_dest, temp_src, count);
	else
	{
		i = 1;
		while (i < count + 1)
		{
			temp_dest[count - i] = temp_src[count - i];
			i++;
		}
	}
	return (dest);
}
