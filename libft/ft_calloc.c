/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:22:33 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 23:31:27 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			cnt;

	if (size > count)
		return (0);
	cnt = 0;
	p = (unsigned char *)malloc(count * size);
	if (!p)
		return (0);
	while (cnt < count * size)
		p[cnt++] = '\0';
	return ((void *)p);
}
