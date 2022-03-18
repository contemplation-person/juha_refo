/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 22:54:11 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;

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
