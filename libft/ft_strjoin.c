/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:04:06 by juha              #+#    #+#             */
/*   Updated: 2022/03/18 13:38:51 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
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
