/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:27:42 by juha              #+#    #+#             */
/*   Updated: 2022/03/14 12:29:26 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			t;

	if (n == 0)
	{
		write(1, "bzero is 0\n", 11);
		return ;
	}
	else
	{
		t = 0;
		temp = (unsigned char *)s;
		while (t < n)
			temp[t++] = '\0';
	}
}
