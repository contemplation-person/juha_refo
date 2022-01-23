/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:46:45 by juha              #+#    #+#             */
/*   Updated: 2022/01/19 11:48:13 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 1;
	while (*str)
	{
		if (!('A' <= *str && *str <= 'Z'))
			return (0);
		str++;
	}
	return (i);
}
/**
#include <stdio.h>
 int main()
 {
    int a = ft_str_is_uppercase("aaaaaa1aaaaaa");
    printf("%d", a); 
    return 0;
 }
 */
