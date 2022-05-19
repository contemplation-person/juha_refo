/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:41:05 by juha              #+#    #+#             */
/*   Updated: 2022/04/04 15:30:15 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	tail;
	size_t	front;

	front = 0;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	if (s1[front] == '\0')
		return (ft_strdup(""));
	tail = ft_strlen(s1);
	while (ft_strrchr(set, s1[tail]))
		tail--;
	return (ft_substr(s1, front, tail - front + 1));
}
