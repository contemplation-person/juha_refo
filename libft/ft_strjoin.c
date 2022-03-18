/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:04:06 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 22:49:04 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char	*temp;

	if (!s1 && s2)
		return (0);
	size = -1;
	while (s1[++size])
		;
	while (s2[++size])
		;
	temp = (char *)malloc(size);
	if (!temp)
		return (0);
	i = -1;
	while (s1[++i])
		temp[i] = s1[i];
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}
