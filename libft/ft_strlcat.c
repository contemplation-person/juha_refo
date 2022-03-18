/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 17:17:00 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dst_len = 0;
	while (dst_len < src_len && dst_len < dstsize)
	{
		dst[dst_len] = src[dst_len];
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (dst_len);
}
