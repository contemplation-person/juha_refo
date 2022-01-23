/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:51:45 by juha              #+#    #+#             */
/*   Updated: 2022/01/19 11:45:08 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 1;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (i);
}
/**
#include <stdio.h>
 int main()
 {
    int a = ft_str_is_numeric("");
    printf("%d", a); 
    return 0;
 }
 */
