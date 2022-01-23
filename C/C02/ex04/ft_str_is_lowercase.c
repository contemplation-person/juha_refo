/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:51:55 by juha              #+#    #+#             */
/*   Updated: 2022/01/19 11:46:28 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 1;
	while (*str)
	{
		if (!('a' <= *str && *str <= 'z'))
			return (0);
		str++;
	}
	return (i);
}
/**
#include <stdio.h>
 int main()
 {
    int a = ft_str_is_lowercase("aaaaaa1aaaaaa");
    printf("%d", a); 
    return 0;
 }
 */
