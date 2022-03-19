/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/20 03:23:22 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	tail;
	size_t	front;

	if (!s1)
		return (0);
	front = -1;
	while (ft_strchr(set, s1[++front]))
		;
	if (s1[front] == '\0')
		return ((char *)(s1 + front));
	tail = sizeof(s1) - 1;
	while (ft_strrchr(set, s1[--tail]))
		;
	return (ft_substr(s1, s1[front], front - tail + 1));
}
