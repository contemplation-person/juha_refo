/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:21:30 by juha              #+#    #+#             */
/*   Updated: 2022/01/20 21:36:27 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
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
