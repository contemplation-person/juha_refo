/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:27:42 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 22:51:00 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*temp;
	unsigned int	t;

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
