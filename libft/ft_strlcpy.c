/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 22:49:02 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	cnt;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	cnt = 0;
	while (cnt < src_len && cnt + 1 < dstsize)
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	if (dstsize > 0)
		dst[cnt] = '\0';
	return (src_len);
}
