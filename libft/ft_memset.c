/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:27:42 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 17:16:41 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			cnt;

	cnt = 0;
	temp = (unsigned char *)b;
	while (cnt < len)
		temp[cnt++] = (unsigned char)c;
	return (temp);
}
