/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:27:42 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 23:58:22 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			t;

	if (n != 0)
	{
		t = 0;
		temp = (unsigned char *)s;
		while (t < n)
			temp[t++] = '\0';
	}
	else
		return ;
}
