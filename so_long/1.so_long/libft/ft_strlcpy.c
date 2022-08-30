/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/21 20:07:01 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	src_len;

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
