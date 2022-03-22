/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/03/22 14:28:05 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	tail;
	size_t	front;

	if (!s1)
		return (0);
	front = 0;
	while (s1[front] && ft_strchr(set, s1[front++]))
		;
	if (s1[front] == '\0')
		return (ft_strdup(""));
	tail = 0;
	while (s1[tail++])
		;
	while (ft_strrchr(set, s1[--tail]))
		;
	return (ft_substr(s1, front - 1, tail - front + 2));
}
