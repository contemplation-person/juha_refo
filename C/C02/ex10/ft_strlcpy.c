/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:21:30 by juha              #+#    #+#             */
/*   Updated: 2022/01/26 21:07:13 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((src[i] != '\0') && (i + 1 < size))
	{
		dest[i] = src[i];
		i++;
	}
	j = i;
	while (src[i])
		i++;
	while (dest[j])
	{
		dest[j] = '\0';
		j++;
	}
	return (i);
}
