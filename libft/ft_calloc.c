/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:22:33 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 22:51:15 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	unsigned char	*p;
	unsigned int	cnt;

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
