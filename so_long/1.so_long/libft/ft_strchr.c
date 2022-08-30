/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:44:54 by juha              #+#    #+#             */
/*   Updated: 2022/04/04 15:10:23 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				n;
	unsigned char	u_c;

	u_c = (unsigned char) c;
	n = 0;
	while (s[n])
	{
		if (s[n] == u_c)
			return ((char *)(s + n));
		n++;
	}
	if (u_c == '\0')
		return ((char *)(s + n));
	return (0);
}
